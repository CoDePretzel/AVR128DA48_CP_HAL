#ifndef CODEPRETZEL_GPIO_HAL_H
#define CODEPRETZEL_GPIO_HAL_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint8_t number;
    uint32_t baud_rate;
    bool parity;
    uint8_t data_bits;
    uint8_t stop_bits;
    bool enable_rx_interrupt;
}UART_PARAMS;

const UART_PARAMS UART0_DEFAULT_VALUES = {0, 115200, false, 8, 1, true};


void UART_init(UART_PARAMS * uart_peripheral);
void UART_putchar(UART_PARAMS * uart_peripheral, uint8_t outgoing_char);
uint8_t UART_getchar(UART_PARAMS * uart_peripheral);

// To use 
typedef void (*isr_function_pointer)(void);

#endif /* CODEPRETZEL_UART_HAL_H */
