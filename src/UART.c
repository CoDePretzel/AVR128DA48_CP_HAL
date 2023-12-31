#include <avr/io.h>
#include <UART.h>

void UART_Init(UART_DATA_t * uart_peripheral)
{        
    bool enable_rx_int = false;
    if(uart_peripheral->enable_rx_interrupt)
    {
        enable_rx_int = true;
    }    
    // Calculate the selected UART address
    volatile USART_t * USARTxREG = (USART_t *) (USART_BASE_ADDR + (USART_PERIPH_OFFSET * uart_peripheral->number));
    USARTxREG->BAUD = getScaledBaudRate(uart_peripheral->baud_rate); // Assign baud rate
    USARTxREG->CTRLB |= USART_TXEN_bm; // Enable selected UART
}

uint16_t public_getScaledBaudRate(uint32_t baud_rate)
{
    float scaled_baud = USART_ASYNC_MODE*CLK_FREQ / (USART_NORMAL_MODE*baud_rate);
    scaled_baud += 0.5;
    return (uint16_t) scaled_baud;
}

// Basado en TB3216-Getting-Started-with-USART-DS90003216
void USART1_sendChar(char c)
{
    while (!(USART1.STATUS & USART_DREIF_bm))
    {
        ;
    } 
    USART1.TXDATAL = c;
}