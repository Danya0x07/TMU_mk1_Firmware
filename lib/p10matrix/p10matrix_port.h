#ifndef _INC_P10MATRIX_PORT_H
#define _INC_P10MATRIX_PORT_H

#include "main.h"

#define SCLK_LOW()  LL_GPIO_ResetOutputPin(LEDMX_SCLK_GPIO_Port, LEDMX_SCLK_Pin)
#define SCLK_HIGH() LL_GPIO_SetOutputPin(LEDMX_SCLK_GPIO_Port, LEDMX_SCLK_Pin)

#define IRQ_ON()    NVIC_EnableIRQ(TIM1_UP_IRQn)
#define IRQ_OFF()   NVIC_DisableIRQ(TIM1_UP_IRQn)

static inline void SetScanStep(uint_fast8_t step)
{
    LL_GPIO_SetOutputPin(LEDMX_A_GPIO_Port, LEDMX_A_Pin);
    LL_GPIO_SetOutputPin(LEDMX_B_GPIO_Port, LEDMX_B_Pin);
    if (step & 0b01)
        LL_GPIO_ResetOutputPin(LEDMX_A_GPIO_Port, LEDMX_A_Pin);
    if (step & 0b10)
        LL_GPIO_ResetOutputPin(LEDMX_B_GPIO_Port, LEDMX_B_Pin);
}

static inline void ShiftOutByte(uint8_t byte)
{
    while (!LL_SPI_IsActiveFlag_TXE(SPI2));
        ;
    LL_SPI_TransmitData8(SPI2, ~byte);
    while (!LL_SPI_IsActiveFlag_TXE(SPI2));
        ;
    (void)LL_SPI_ReceiveData8(SPI2);
}

static inline void ShiftOutBytes(const uint8_t *data, uint32_t len)
{
    while (len--)
        ShiftOutByte(*data++);
    while (!LL_SPI_IsActiveFlag_TXE(SPI2));
        ;
    while (LL_SPI_IsActiveFlag_BSY(SPI2));
        ;
}

#endif // _INC_P10MATRIX_PORT_H