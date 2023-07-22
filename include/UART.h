#ifndef CODEPRETZEL_UART_HAL_H
#define CODEPRETZEL_UART_HAL_H

#include <stdint.h>
#include <stdbool.h>

#ifdef CLK_FREQ
#define CLK_FREQ 4000000L
#endif

uint8_t const USART_NORMAL_MODE = 16;
uint8_t const USART_CLK2X_MODE = 8;

typedef struct
{
    uint8_t number;
    uint32_t baud_rate;
    bool parity;
    uint8_t data_bits;
    uint8_t stop_bits;
    bool enable_rx_interrupt;
}UART_DATA;

const UART_DATA UART0_DEFAULT_VALUES = {0, 115200, false, 8, 1, true};


void UART_init(UART_DATA * uart_peripheral);
void UART_putchar(UART_DATA * uart_peripheral, uint8_t outgoing_char);
uint8_t UART_getchar(UART_DATA * uart_peripheral);

// To use 
typedef void (*isr_function_pointer)(void);

#endif /* CODEPRETZEL_UART_HAL_H */
