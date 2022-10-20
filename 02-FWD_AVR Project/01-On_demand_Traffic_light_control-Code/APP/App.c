/*
 * App.c
 *
 *  Created on: Oct 12, 2022
 *      Author: karim
 */

#include "App.h"

static u8 APP_u8_LightControlFlag;


/*
 * this function initialize the LEDs of the cars.
 * it store which LED is work in the global flag APP_u8_LightControlFlag.
 * we store which led is work to we can detect what our action we the interrupt occur
 * */
void APP_voidTrifficLightInit(void)
{

	/*Green LED*/
	DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_HIGH);
	APP_u8_LightControlFlag = APP_U8_GREEN_LED;
	DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_HIGH);
	TIMERS_voidTimerDelay_ms(5000);
	DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_LOW);
	DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_LOW);

	/*Yellow LED*/
	APP_voidYellowLedBlink();

	/*Red LED*/
	DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_HIGH);
	APP_u8_LightControlFlag = APP_U8_RED_LED;
	DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_HIGH);
	TIMERS_voidTimerDelay_ms(5000);
	DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_LOW);
	DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_LOW);

	/*Yellow LED*/
	APP_voidYellowLedBlink();


}

/*
 * this function to make the yellow-led blink in the cars and pedestrian in the same time during the 5 sec
 * it is just make a counter to control this process
 * */
void APP_voidYellowLedBlink(void)
{
	u32 L_CounterDelay = 0;
	while(L_CounterDelay < 5)
	{
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_HIGH);
		APP_u8_LightControlFlag = APP_U8_YELLOW_LED;
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_HIGH);
		TIMERS_voidTimerDelay_ms(600);
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_LOW);
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_LOW);
		TIMERS_voidTimerDelay_ms(520);
		L_CounterDelay++;
	}
}

/*
 * this function make the yellow-led cars blink
 * it control this process by using counter and delay function which we make by using the timer in normal mode
 * */
void APP_voidCarYellowLedBlink(void)
{
	u32 L_CounterDelay = 0;
	while(L_CounterDelay < 5)
	{
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_HIGH);
		APP_u8_LightControlFlag = APP_U8_YELLOW_LED;
		TIMERS_voidTimerDelay_ms(600);
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_LOW);
		TIMERS_voidTimerDelay_ms(520);
		L_CounterDelay++;
	}
}

//Error_State_t APP_voidControlValueOfINT0(void)
//{
//	Error_State_t L_enumFunctionState = RET_NOK;
//	u8 L_u8ReturnNTI0Value = 0;
//	DIO_Error_State_tGetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,&L_u8ReturnNTI0Value);
//	if(0 < L_u8ReturnNTI0Value)
//	{
//		TIMERS_voidTimerDelay_ms(20);
//		DIO_Error_State_tGetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,&L_u8ReturnNTI0Value);
//		if(0 < L_u8ReturnNTI0Value)
//		{
//			L_enumFunctionState = RET_NOK;
//		}
//		else
//		{
//			//L_enumFunctionState = RET_OK;
//		}
//	}
//	else
//	{
//		//L_enumFunctionState = RET_OK;
//	}
//	return L_enumFunctionState;
//}

/*
 * ISR function for the EXTI0
 * when the rasing edge come on NTI0 this function start to implementation
 * this function switch on the global flag to can decide what he will do
 * => if the gloabl flag => RED-LED:
 * Change from normal mode to pedestrian mode when the pedestrian button is pressed.
 * If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds,
 * this means that pedestrians can cross the street while the pedestrian's Green LED is on.
 * => if the gloabl flag => YELLOW-LED || GREEN-LED:
 * If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs
 *  start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds,
 *  this means that pedestrian must wait until the Green LED is on.
 * => and after that:
 *  At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds
 *  and the pedestrian's Green LED is still on.
 *  After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
 *  Traffic lights signals are going to the normal mode again.
 * */
void APP_voidGetTrafficLightState(void)
{
	switch(APP_u8_LightControlFlag)
	{
	case APP_U8_YELLOW_LED:
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_LOW);  // pedestrian REG-LED OFF
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_LOW);  // cars YELLOW-LED OFF
		APP_voidYellowLedBlink();                                           // car and pedestrian YELLOW-LED Blink
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_LOW);  // pedestrian YELLOW-LED OFF
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_LOW);  // cars YELLOW-LED OFF
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_HIGH);  // pedestrian GREEN-LED ON
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_HIGH);  // cars RED-LED ON
		TIMERS_voidTimerDelay_ms(5000);									     // delay
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_LOW);   // cars RED-LED OFF
		APP_voidCarYellowLedBlink();
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_LOW);  // pedestrian GREEN-LED OFF
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_LOW);  // cars YELLOW-LED OFF
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_HIGH);  // pedestrian RED-LED ON
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_HIGH);  // cars GREEN-LED ON
		TIMERS_voidTimerDelay_ms(5000);									     // delay
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_LOW);  // cars GREEN-LED OFF
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_LOW);  // pedestrian RED-LED OFF
		break;
	case APP_U8_GREEN_LED:
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_LOW); // pedestrian RED-LED OFF
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_LOW);  // cars GREEN-LED OFF
		APP_voidYellowLedBlink();
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_LOW);  // pedestrian YELLOW-LED OFF
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_LOW);  // cars YELLOW-LED OFF
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_HIGH);  // pedestrian GREEN-LED ON
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_HIGH);  // cars RED-LED ON
		TIMERS_voidTimerDelay_ms(5000);									     // delay
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_LOW);   // cars RED-LED OFF
		APP_voidCarYellowLedBlink();
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_LOW);  // cars YELLOW-LED OFF
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_LOW);  // pedestrian GREEN-LED OFF
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_HIGH);  // pedestrian RED-LED ON
		DIO_Error_State_tSetPinValue(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_HIGH);  // cars GREEN-LED ON
		break;
	}
}


void APP_voidToggleLED(void)
{
	static u8 flag = 0;
	if(0 == flag)
	{
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_HIGH);
		flag = 1;
	}
	else
	{
		DIO_Error_State_tSetPinValue(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_LOW);
		flag = 0;
	}
}

