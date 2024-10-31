#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"


#define RED_LED      (1U << 1)  // Port F Pin 1
#define BLUE_LED     (1U << 2)  // Port F Pin 2
#define GREEN_LED    (1U << 3)  // Port F Pin 3

void initUART0(void) {
 // Activate UART0 and Port A
    SYSCTL_RCGCUART_R |= (1U << 0);       // Enable UART0 clock
    SYSCTL_RCGCGPIO_R |= (1U << 0);       // Enable GPIO Port A clock

    // Set up PA0 and PA1 for UART communication
    GPIO_PORTA_AFSEL_R |= (1U << 0) | (1U << 1); // Enable alternate functions on PA0 and PA1
    GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) | 0x00000011; // Configure PA0 and PA1 for UART
    GPIO_PORTA_DEN_R |= (1U << 0) | (1U << 1); // Digital enable on PA0, PA1

    // Set UART0 for 9600 baud rate, 8-N-1 frame format
    UART0_CTL_R &= ~UART_CTL_UARTEN;     // Disable UART0 while configuring
    UART0_IBRD_R = 104;                  // Integer part of Baud Rate Divisor (BRD)
    UART0_FBRD_R = 11;                   // Fractional part of BRD
    UART0_LCRH_R = UART_LCRH_WLEN_8;     // 8 data bits, no parity, 1 stop bit
    UART0_CTL_R |= UART_CTL_UARTEN;      // Enable UART0
       
}


int main(void) {
   
}
