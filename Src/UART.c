/*
 *	UART.c
 *
 */
 
#include "UART.h"
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart1;



int variable = 0;
char buffer[100];
int len=0;

char rx_indx, rx_data[2], rx_buffer[100];
char Transfer_cplt;



void uart_it_init(void)
{
	/* activate uart rx interrupt everytime receiveing 1 byte */
	HAL_UART_Receive_IT(&huart1, rx_data, 1);	
}
	


void uart_write(void)
{
		if(Transfer_cplt)
		{	
			sprintf(buffer,"%s\n", rx_buffer);
			len = strlen(buffer);
			HAL_UART_Transmit(&huart1, buffer, len, 1000);
			Transfer_cplt = 0;	// reset transfer_complete variable
			variable++;
		}
	
		
}
//Interrupt callback routine
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)  
{
    uint8_t i;
    if (huart->Instance == USART1)                              	//current UART
        {
					if (rx_indx==0) {for (i=0;i<100;i++) rx_buffer[i]=0;}   //clear Rx_Buffer before receiving new data 

					if (rx_data[0]!= 13)                                     //if received data different from ascii 13 (enter)
							{
								
								rx_buffer[rx_indx++]=rx_data[0];                   //add data to Rx_Buffer
							}
					else                                                    //if received data = 13
							{
								rx_indx=0;
								Transfer_cplt=1;                                   //transfer complete, data is ready to read
							}

					HAL_UART_Receive_IT(&huart1, rx_data, 1);               //activate UART receive interrupt every time
        }

}
