#ifndef CODEPRETZEL_UART_HAL_H
#define CODEPRETZEL_UART_HAL_H

#include <stdint.h>
#include <stdbool.h>

#ifndef CLK_FREQ
#define CLK_FREQ 4000000UL
#endif

// Public elements
typedef struct
{
    uint8_t number;
    uint32_t baud_rate;
    bool parity;
    uint8_t data_bits;
    uint8_t stop_bits;
    bool enable_rx_interrupt;
}UART_DATA_t;

const UART_DATA_t UART0_DEFAULT_VALUES = {0, 115200, false, 8, 1, true};


// Private declarations and prototypes
static uint8_t * USART_BASE_ADDR = (uint8_t*) 0x0800; // start of USART memory mapped registers
static uint8_t USART_PERIPH_OFFSET = 0x20; // Every 0x20, the next USART starts
static uint8_t const USART_NORMAL_MODE = 16;
static uint8_t const USART_CLK2X_MODE = 8;
static uint8_t const USART_ASYNC_MODE = 64;

static inline uint16_t getScaledBaudRate(uint32_t baud_rate)
{
    float scaled_baud = USART_ASYNC_MODE*CLK_FREQ / (USART_NORMAL_MODE*baud_rate);
    scaled_baud += 0.5;
    return (uint16_t) scaled_baud;
}

uint16_t public_getScaledBaudRate(uint32_t baud_rate);

void UART_Init(UART_DATA_t * uart_peripheral);
void UART_putchar(UART_DATA_t * uart_peripheral, uint8_t outgoing_char);
uint8_t UART_getchar(UART_DATA_t * uart_peripheral);
void USART1_sendChar(char c);

// To use 
typedef void (*isr_function_pointer)(void);

#endif /* CODEPRETZEL_UART_HAL_H */
