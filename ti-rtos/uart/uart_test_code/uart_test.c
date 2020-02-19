/*
 * uart_test.c
 *
 *  Created on: 13 Þub 2020
 *      Author: Packard Bell
 */

#include "project.h"
#include "uart_test.h"

#define uart_buffersize 8

UART_Handle uart;
UART_Params uartParams;
tRingBufObject RingBuf;

Semaphore_Struct uart_semStruct;
Semaphore_Handle uart_semHandle;

Semaphore_Struct init_semStruct;
Semaphore_Handle init_semHandle;

unsigned char pcBuffer[128], uartBuf[uart_buffersize], pcData[],uartData[128];

void UART_Kurulum(eBaudRate BaudRate, OkumaKesmesi callback,eParite Parite)
{
    Board_initGeneral();
    Board_initGPIO();
    Board_initUART();

    UART_Params_init(&uartParams);
    uartParams.writeDataMode  = UART_DATA_BINARY;
    uartParams.readDataMode   = UART_DATA_BINARY;
    uartParams.readReturnMode = UART_RETURN_NEWLINE;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = BaudRate;
    // uartParams.writeMode = WriteMode;
    if(callback == NULL) {
        uartParams.readMode  = UART_MODE_BLOCKING;
    }
    else {
        uartParams.readMode  = UART_MODE_CALLBACK;
        uartParams.readCallback  = callback;
    }
    uartParams.parityType = Parite;
    uart = UART_open(Board_UART0, &uartParams);
    /*UARTIntRegister(UART0_BASE, readCallback);
    IntMasterEnable();
    IntEnable(INT_UART0);*/
    // UARTIntEnable(UART0_BASE, UART_INT_RX);

}
void UART_Step()
{
    uint32_t RingSize = RingBufUsed(&RingBuf);
    RingBufRead(&RingBuf,pcBuffer, RingSize);
    UART_write(uart, &pcBuffer, RingSize);
}
void readCallback(UART_Handle handle, void *pcData, size_t num)
{
    System_printf("Kesme geldi");
    RingBufWrite(&RingBuf, pcData, num);
    UART_read(handle, pcData, uart_buffersize);
    Semaphore_post(uart_semHandle);
}


