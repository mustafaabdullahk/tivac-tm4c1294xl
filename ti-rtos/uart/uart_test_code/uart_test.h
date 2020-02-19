/*
 * uart_test.h
 *
 *  Created on: 13 Þub 2020
 *      Author: Packard Bell
 */

#ifndef UART_TEST_H_
#define UART_TEST_H_

#include <ti/drivers/UART.h>
typedef void        (*OkumaKesmesi)    (UART_Handle, void *buf, size_t count);
typedef enum eBaudRate
{
    Baud_2400=2400,
    Baud_9600=9600,
    Baud_19200=19200,
    Baud_38400=38400,
    Baud_57600=57600,
    Baud_115200=115200,
    Baud_921600=921600
} eBaudRate;
typedef enum eParite
{
    Parite_NONE = 0,  /*!< No parity */
    Parite_EVEN = 1,  /*!< Parity bit is even */
    Parite_ODD  = 2,  /*!< Parity bit is odd */
    Parite_ZERO = 3,  /*!< Parity bit is always zero */
    Parite_ONE  = 4   /*!< Parity bit is always one */
} eParite;

void UART_Kurulum(eBaudRate BaudRate, OkumaKesmesi callback,eParite Parite);
void UART_Step();
void readCallback(UART_Handle handle, void *pcData, size_t num);

#endif /* UART_TEST_H_ */
