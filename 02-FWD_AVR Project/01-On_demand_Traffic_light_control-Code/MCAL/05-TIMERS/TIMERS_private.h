/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 10/10/2022              ***********/
/********** SWC     : TIMERS                  ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

#define TIMERS_U8_TIMSK_REG				*((volatile u8 *)0X59)
#define TIMERS_U8_TOIE0_PIN						0
#define TIMERS_U8_OCIE0_PIN						1

#define TIMERS_U8_TIFR_REG				*((volatile u8 *)0X58)
#define TIMERS_U8_TOV0_PIN						0
#define TIMERS_U8_OCF0_PIN						1

#define TIMERS_U8_TCCR0_REG				*((volatile u8 *)0X53)
#define TIMERS_U8_CS00_PIN						0
#define TIMERS_U8_CS01_PIN						1
#define TIMERS_U8_CS02_PIN						2
#define TIMERS_U8_WGM01_PIN						3
#define TIMERS_U8_COM00_PIN						4
#define TIMERS_U8_COM01_PIN						5
#define TIMERS_U8_WGM00_PIN						6
#define TIMERS_U8_FOC0_PIN						7

#define TIMERS_U8_TCNT0_REG				*((volatile u8 *)0X52)

#define TIMERS_U8_OCR0_REG				*((volatile u8 *)0X5C)


/***********************MACROS For TIMERS0 Modes***********************/
#define TIMERS_U8_NORMAL_MODE					0
#define TIMERS_U8_CTC_MODE						1
#define TIMERS_U8_FAST_PWM_MODE					2
#define TIMERS_U8_PWM_PHASE_CORRECT_MODE		3


/*********************MACROS For TIMERS0 Prescaler*********************/
#define TIMERS_U8_NO_CLOCK_SOURCE				0
#define TIMERS_U8_N0_PRESCALER					1
#define TIMERS_U8_8_PRESCALER					2
#define TIMERS_U8_64_PRESCALER					3
#define TIMERS_U8_256_PRESCALER					4
#define TIMERS_U8_1024_PRESCALER				5

/***********************MACROS For Interrupt Mode**********************/
#define TIMERS_U8_TURN_OFF_INTERRUPT			0
#define TIMERS_U8_TURN_ON_INTERRUPT				1

/*****************MACROS For TIMERS0 Interrupt Enable******************/
#define TIMERS_U8_OVF_INTRPT_ENB_PIN			0	//Timer/Counter0 Overflow Interrupt Enable
#define TIMERS_U8_CMP_MTH_INTRPT_ENB_PIN		1	//Timer/Counter0 Output Compare Match Interrupt Enable


#endif
