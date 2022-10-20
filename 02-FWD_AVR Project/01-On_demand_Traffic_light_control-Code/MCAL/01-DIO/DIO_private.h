/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 18/09/2022              ***********/
/********** SWC     : DIO                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define DIO_U8_PORTA_REG			*((volatile u8*)0X3B)
#define DIO_U8_DDRA_REG		    	*((volatile u8*)0X3A)
#define DIO_U8_PINA_REG		    	*((volatile u8*)0X39)
	
	
	
#define DIO_U8_PORTB_REG			*((volatile u8*)0X38)
#define DIO_U8_DDRB_REG		    	*((volatile u8*)0X37)
#define DIO_U8_PINB_REG		    	*((volatile u8*)0X36)
	
	
	
#define DIO_U8_PORTC_REG			*((volatile u8*)0X35)
#define DIO_U8_DDRC_REG		    	*((volatile u8*)0X34)
#define DIO_U8_PINC_REG		    	*((volatile u8*)0X33)
	
	
	
#define DIO_U8_PORTD_REG			*((volatile u8*)0X32)
#define DIO_U8_DDRD_REG		    	*((volatile u8*)0X31)
#define DIO_U8_PIND_REG		    	*((volatile u8*)0X30)
	
	
/***************Macros for Pins Direction***************/	
#define DIO_U8_INITIAL_OUTPUT		1
#define DIO_U8_INITIAL_INPUT		0
/****************Macros for Pins Values*****************/	
#define DIO_U8_OUTPUT_LOW			0
#define DIO_U8_OUTPUT_HIGH			1
#define DIO_U8_FLOATING				0
#define DIO_U8_PULL_UP				1

/*****************************Concatenate function*****************************/
#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)			Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0
/***************************end Concatenate function***************************/





#endif
