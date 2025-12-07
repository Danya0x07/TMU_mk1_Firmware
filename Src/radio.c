#include "radio.h"
#include "main.h"
#include "led.h"
#include "protocol.h"
#include <nrf24l01.h>

#define LINK_TIMEOUT    1000

static uint32_t lastMsgTimeStart, lastMsgTimeFinish;
static enum nrf24l01_pipe_number lastPipe = NRF24L01_PIPE0;

void Radio_Init(void)
{
    struct nrf24l01_rx_config config = {
		.addr_size = NRF24L01_ADDRS_3BYTE,
		.crc_mode  = NRF24L01_CRC_1BYTE,
		.datarate  = NRF24L01_DATARATE_1MBPS,
		.mode = NRF24L01_RX_MODE_DPL_ACK_PAYLOAD,
		.en_irq = NRF24L01_IRQ_RX_DR,
		.rf_channel = PROTOCOL_RADIO_CHANNEL,
	};
	struct nrf24l01_pipe_config p0_conf = { // start LRW
		.address.array = (uint8_t [3])PROTOCOL_LTW_START_ADDRESS,
		.mode = NRF24L01_PIPE_MODE_ACK_DPL
	}, p1_conf = {  // finish LTW
        .address.array = (uint8_t [3])PROTOCOL_LTW_FINISH_ADDRESS,
        .mode = NRF24L01_PIPE_MODE_ACK_DPL
    };

    HAL_Delay(NRF24L01_PWR_ON_DELAY_MS);

    if (nrf24l01_rx_configure(&config) < 0) {
        Led_BlinkStart(1, 500);
    }
    nrf24l01_rx_setup_pipe(NRF24L01_PIPE0, &p0_conf);
    nrf24l01_rx_setup_pipe(NRF24L01_PIPE1, &p1_conf);
    nrf24l01_rx_start_listening();
}

bool Radio_PacketReceived(void)
{
    return nrf24l01_get_interrupts() & NRF24L01_IRQ_RX_DR;
}

bool Radio_PacketPending(void)
{
    return nrf24l01_data_in_rx_fifo();
}

void Radio_GetLinkStatus(bool *linkStart, bool *linkFinish)
{
    *linkStart = HAL_GetTick() - lastMsgTimeStart < LINK_TIMEOUT;
    *linkFinish = HAL_GetTick() - lastMsgTimeFinish < LINK_TIMEOUT;
}

RadioCommStatus Radio_ReadMessage(struct ProtocolMessage *message)
{
    if (nrf24l01_read_pld_size() != sizeof(struct ProtocolMessage)) {
        nrf24l01_flush_rx_fifo();
        nrf24l01_clear_interrupts(NRF24L01_IRQ_RX_DR);
        return RadioCommStatus_ESIZE;
    }

    enum nrf24l01_pipe_number pipe = nrf24l01_rx_get_pld_pipe_no();

    nrf24l01_read_pld(message, sizeof(struct ProtocolMessage));
    nrf24l01_clear_interrupts(NRF24L01_IRQ_RX_DR);

    if (pipe == NRF24L01_PIPE0) {
        lastMsgTimeStart = HAL_GetTick();
    }
    else if (pipe == NRF24L01_PIPE1) {
        lastMsgTimeFinish = HAL_GetTick();
    }
    else {
        nrf24l01_flush_rx_fifo();
        return RadioCommStatus_EPIPE;
    }
    lastPipe = pipe;

    return RadioCommStatus_OK;
}

void Radio_WriteResponse(const struct ProtocolMessage *response, bool overwrite)
{
    if (overwrite) {
        nrf24l01_flush_tx_fifo();
        nrf24l01_rx_write_ack_pld(NRF24L01_PIPE0, response, sizeof(struct ProtocolMessage));
        nrf24l01_rx_write_ack_pld(NRF24L01_PIPE1, response, sizeof(struct ProtocolMessage));
    }
    else if (lastPipe == NRF24L01_PIPE0 || lastPipe == NRF24L01_PIPE1) {
        nrf24l01_rx_write_ack_pld(lastPipe, response, sizeof(struct ProtocolMessage));
    }
}
