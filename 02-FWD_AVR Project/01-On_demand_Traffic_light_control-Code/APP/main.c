/*
 * main.c
 *
 *  Created on: Oct 11, 2022
 *      Author: karim
 */

/*main.h*/
#include "main.h"



int main(void)
{
	u8 L_u8ReturnNTI0State = 0;
	/*DIO Init*/
	DIO_voidInit();
	/*Enable the GLobal Interrupt */
	GIE_voidEnable();
	/*set EXTI callback function*/
	EXTI_Error_State_tEXTICallBack(&APP_voidGetTrafficLightState,EXTI_U8_INT0);
	/*Enable EXTI INT0*/
	EXTI_Error_StateEnable(EXTI_U8_INT0,EXTI_U8_RAISING_EDGE);

	while(1)
	{
		APP_voidTrifficLightInit();
	}

	return 0;
}




