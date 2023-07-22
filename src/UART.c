#include <avr/io.h>
#include <UART.h>

void UART_init(UART_DATA * uart_peripheral)
{        
    uint8_t * uart_base_addr = (uint8_t*) 0x0800; //USART0
    uint8_t * uart_periph_offset = (uint8_t*) 0x20;
    uint8_t * uart_baud_offset = (uint8_t *) 0x8;

    enable_rx_int = false;
    if(uart_peripheral->enable_rx_interrupt)
    {
        enable_rx_int = true;
    }    
    USART_t * USARTxREGS = USART0 + (uart_periph_offset*c_uart_num);
    // Calculate UART Baud 

    //uint8_t * uart_
    c_uart_num = uart_peripheral->number;
    
    *(current_uart_addr + uart_baud_offset) = uart_periph_offset->baud_rate;
    USART0_BAUD = uart_peripheral->baud_rate;
    //115200
    // uint16_t MAX = 65535
    // uint32_t val = 115200
    // 4375000
    USART0.BAUDL = (uint8_t)(uart_peripheral->baud_rate) >> 24;
}