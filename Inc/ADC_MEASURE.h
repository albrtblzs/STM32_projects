/*
 *	ADC_MEASURE.h
 *
 */

#ifndef ADC_MEASURE_H
#define ADC_MEASURE_H

#include "stm32f0xx_hal.h"


/* Initialize the ADC interrupt */
extern void ADC_it_init(void);



/* single channel ADC conversion with interrupt  */
void HAL_ADC_ConvCpltCallback(UART_HandleTypeDef *huart);

#endif // ADC_MEASURE_H	