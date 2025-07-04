/**
 * @file    nrf24l01_port.h
 * @brief   Платформозависимая часть библиотеки.
 *
 * Путём реализации интерфейса, объявленного в данном файле можно перенести
 * библиотеку на любую платформу.
 *
 * @note
 * В данном файле можно подключать любые заголовочные файлы, необходимые
 * для реализации объявленного интерфейса.
 */

#ifndef _NRF24L01_PORT_H
#define _NRF24L01_PORT_H

/*
 * Здесь может быть подключение пользовательских заголовочных файлов
 */
#include "main.h"
#include "tim.h"

/**
 * @name    Макросы для управления выводами трансивера.
 * @{
 */
#define _csn_high() LL_GPIO_SetOutputPin(NRF_CSN_GPIO_Port, NRF_CSN_Pin)
#define _csn_low()  LL_GPIO_ResetOutputPin(NRF_CSN_GPIO_Port, NRF_CSN_Pin)
#define _ce_high()  LL_GPIO_SetOutputPin(NRF_CE_GPIO_Port, NRF_CE_Pin)
#define _ce_low()   LL_GPIO_ResetOutputPin(NRF_CE_GPIO_Port, NRF_CE_Pin)
/** @} */

/**
 * @brief   Обменивается байтом по SPI.
 *
 * @note
 * Если в проекте используется несколько библиотек, работающих с SPI, то будет
 * целесообразно вынести соответствующую функцию в отдельный файл, а в этой
 * функции просто делегировать ей работу.
 *
 * @bug
 * Если функция, которой данная функция/макрос делегирует обмен байтом по SPI,
 * находится в отдельной единице трансляции, то как минимум для
 * arm-none-eabi-gcc v6.3.1 имеет место баг, вызванный оптимизацией компилятора.
 * Баг проявляется на уровнях оптимизации, отличных от -O0 и -Og.
 * Симптомы: некорректные значения при передаче/приёме данных по SPI.
 */
static inline uint8_t _spi_transfer_byte(uint8_t byte)
{
    while (!LL_SPI_IsActiveFlag_TXE(SPI1))
        ;
    LL_SPI_TransmitData8(SPI1, byte);
    while (!LL_SPI_IsActiveFlag_RXNE(SPI1))
        ;
    return LL_SPI_ReceiveData8(SPI1);
}

/**
 * @brief   Обменивается массивом байт по SPI.
 *
 * @param[in] out   Буфер исходящих данных. NULL, если не исопльзуется.
 * @param[out] in   Буфер входящих данных. NULL, если не исопльзуется.
 * @param len   Количество байт для обмена.
 *
 * @note
 * Если в проекте используется несколько библиотек, работающих с SPI, то будет
 * целесообразно вынести соответствующую функцию в отдельный файл, а в этой
 * функции просто делегировать ей работу.
 *
 * @warning
 * in и out не могут быть NULL одновременно.
 */
static inline void _spi_transfer_bytes(uint8_t *in, const uint8_t *out,
                                       size_t len)
{
    if (in == NULL) {
        while (len--)
            _spi_transfer_byte(*out++);
    } else if (out == NULL) {
        while (len--)
            *in++ = _spi_transfer_byte(0);
    } else {
        while (len--)
            *in++ = _spi_transfer_byte(*out++);
    }
}

/** Функция миллисекундной задержки. */
#define _delay_ms(ms)   HAL_Delay((ms))

/**
 * Функция микросекундной задержки.
 *
 * @note
 * Данная функция не является необходимой. Если микросекундная задержка не
 * доступна, необходимо указать это в файле nrf24l01_conf.h
 */
#define _delay_us(us)   Micros_Wait((us))

#endif /* _NRF24L01_PORT_H */
