/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 10/10/2022              ***********/
/********** SWC     : TIMERS                  ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H



/********************************Waveform Generation Mode********************************/
/*options : TIMERS_U8_NORMAL_MODE
          : TIMERS_U8_CTC_MODE
          : TIMERS_U8_FAST_PWM_MODE
          : TIMERS_U8_PWM_PHASE_CORRECT_MODE*/


#define TIMERS_U8_TIMER0_Mode						TIMERS_U8_NORMAL_MODE
/***************************************************************************************/




/****************Select Prescaler For Timer0 CLK => Clock Select************************/
/*options : TIMERS_U8_NO_CLOCK_SOURCE
          : TIMERS_U8_N0_PRESCALER
          : TIMERS_U8_8_PRESCALER
          : TIMERS_U8_64_PRESCALER
          : TIMERS_U8_256_PRESCALER
          : TIMERS_U8_1024_PRESCALER*/


#define TIMERS_U8_TIMER0_PRESCALER					TIMERS_U8_8_PRESCALER
/***************************************************************************************/




/********************************Select Interrupt Mode Operation**********************************/
/*options : TIMERS_U8_TURN_OFF_INTERRUPT
          : TIMERS_U8_TURN_ON_INTERRUPT*/

#define TIMERS_U8_TIMER0_TNTERRUPT_MODE_OPTN		TIMERS_U8_TURN_OFF_INTERRUPT
/***************************************************************************************/



/***************************************************************************************/
/* 1. The No of overflow you want to get the required time delay.
 * 2. The preload value to make sure you set the exact time.
 */
#define TIMERS_U8_NORMAL_NO_OF_OVF					19531
#define TIMERS_U8_PRELOAD_INITIAL_VALUE				192
/* 1. The No of overflow you want to get required time delay.
 * 2. The Initial value you want to make the timer start from, this value ranges from 0 to 2^n(max).
 */
#define TIMERS_U8_CTC_NO_OF_OVF						10000
#define TIMERS_U8_SET_CTC_INITIAL_VALUE				100
/***************************************************************************************/


#endif
