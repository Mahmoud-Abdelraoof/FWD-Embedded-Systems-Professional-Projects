/*
 * App.h
 *
 *  Created on: Oct 12, 2022
 *      Author: karim
 */

#ifndef APP_H_
#define APP_H_

#define APP_U8_RED_LED			1
#define APP_U8_YELLOW_LED		2
#define APP_U8_GREEN_LED		3

#include "main.h"

Error_State_t APP_voidControlValueOfINT0(void);

void APP_voidTrifficLightInit(void);

void APP_voidYellowLedBlink(void);

void APP_voidCarYellowLedBlink(void);

void APP_voidGetTrafficLightState(void);

void APP_voidToggleLED(void);






#endif /* APP_H_ */
