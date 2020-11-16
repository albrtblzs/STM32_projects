/*
 *	UART.h
 *
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f0xx_hal.h"


/* Initialize the ring buffer */
extern void uart_it_init(void);
extern char Transfer_cplt;

void uart_write(void);

/* the ISR for the uart. put it in the IRQ handler */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif // UART_H_
