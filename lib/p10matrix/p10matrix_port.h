#ifndef _INC_P10MATRIX_PORT_H
#define _INC_P10MATRIX_PORT_H

#include "main.h"

#define SCLK_LOW()  LL_GPIO_ResetOutputPin(LEDMX_SCLK_GPIO_Port, LEDMX_SCLK_Pin)
#define SCLK_HIGH() LL_GPIO_SetOutputPin(LEDMX_SCLK_GPIO_Port, LEDMX_SCLK_Pin)

#define IRQ_ON()    NVIC_EnableIRQ(TIM1_UP_IRQn)
#define IRQ_OFF()   NVIC_DisableIRQ(TIM1_UP_IRQn)

#define A_PIN   GPIO_PIN_11
#define B_PIN   GPIO_PIN_12

static inline void SetScanStep(uint_fast8_t step)
{
    uint32_t portValue = LL_GPIO_ReadOutputPort(LEDMX_A_GPIO_Port);
    portValue |= A_PIN | B_PIN;
    if (step & 0b01)
        portValue &= ~A_PIN;
    if (step & 0b10)
        portValue &= ~B_PIN;
    LL_GPIO_WriteOutputPort(LEDMX_A_GPIO_Port, portValue);
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