#ifndef UART_H
#define UART_H

void UART_Initialization(uint16_t baudRate);

uint8_t UART_Transmit(uint8_t sendValue);

uint8_t UART_Receive();

#endif