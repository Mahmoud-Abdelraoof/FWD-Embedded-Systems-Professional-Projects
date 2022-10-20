/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 30/09/2022              ***********/
/********** SWC     : EXTI                    ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/*****************Define for EXTI Registers***************/
#define EXTI_U8_MCUCR_REG			*((volatile u8 *)0X55)
#define EXTI_U8_MCUCSR_REG			*((volatile u8 *)0X54)
#define EXTI_U8_GICR_REG			*((volatile u8 *)0X5B)
#define EXTI_U8_GIFR_REG			*((volatile u8 *)0X5A)
/*****************MCUCR register BITS*********************/
#define ISC00_BIT					0
#define ISC01_BIT                   1
#define ISC10_BIT                   2
#define ISC11_BIT                   3
/****************GICR register BITS***********************/
#define INT0_BIT					6
#define INT1_BIT					7
#define INT2_BIT					5
/****************MCUCSR register pins*********************/
#define ISC2_BIT					6




#endif