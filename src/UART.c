#include <avr/io.h>
#include <UART.h>

void UART_init(UART_DATA_t * uart_peripheral)
{        
    //USART0 = 0x0800, start of USART memory mapped registers
    uint8_t * uart_periph_offset = (uint8_t*) 0x20; // Every 0x20, the next USART starts    

    bool enable_rx_int = false;
    if(uart_peripheral->enable_rx_interrupt)
    {
        enable_rx_int = true;
    }    
    USART_t * USARTxREGS = USART0 + (uart_periph_offset * uart_peripheral->number);
    USARTxREGS->BAUD = getScaledBaudRate(uart_peripheral->baud_rate);
}

uint16_t public_getScaledBaudRate(uint32_t baud_rate)
{
    float scaled_baud = USART_ASYNC_MODE*CLK_FREQ / (USART_NORMAL_MODE*baud_rate);
    scaled_baud += 0.5;
    return (uint16_t) scaled_baud;
}