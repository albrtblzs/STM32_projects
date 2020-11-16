/*
 *	ADC_MEASURE.c
 *
 */

#include "ADC_MEASURE.h"
#include "ADC_MEASURE.h"

ADC_HandleTypeDef hadc;

unsigned ADC_raw = 0;

float Vdd = 0;

void ADC_it_init(void)
{
	HAL_ADC_Start_IT(&hadc);

	HAL_Delay(200);
}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)  
{ 
  if (__HAL_ADC_GET_FLAG(hadc, ADC_FLAG_EOC)) 
  { 
    ADC_raw = HAL_ADC_GetValue(hadc); 
    Vdd = 3300 * ((*VREFINT_CAL_ADDR) / ADC_raw); 
  } 
}
