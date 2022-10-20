/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 18/09/2022              ***********/
/********** SWC     : DIO                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
 #ifndef DIO_INTERFACE_H
 #define DIO_INTERFACE_H

#include "STD_TYPES.h"
#include "ERROR_STATE.h"

/* Macros for PORTS */
#define DIO_U8_PORTA		0
#define DIO_U8_PORTB		1
#define DIO_U8_PORTC		2
#define DIO_U8_PORTD		3



/* Macros for PINS */
#define DIO_U8_PIN0 		0
#define DIO_U8_PIN1			1
#define DIO_U8_PIN2			2
#define DIO_U8_PIN3			3
#define DIO_U8_PIN4			4
#define DIO_U8_PIN5			5
#define DIO_U8_PIN6			6
#define DIO_U8_PIN7			7



/* Macros for Pin Direction */
#define DIO_U8_OUTPUT		1
#define DIO_U8_INPUT		0



/* Macros for pin value */
#define DIO_U8_HIGH			1
#define DIO_U8_LOW			0

void DIO_voidInit(void);

Error_State_t DIO_Error_State_tSetPinDirection  (u8 copy_u8portId, u8 copy_u8pinId,u8 copy_u8pinDirection);

Error_State_t DIO_Error_State_tSetPinValue      (u8 copy_u8portId, u8 copy_u8pinId,u8 copy_u8pinValue);

Error_State_t DIO_Error_State_tGetPinValue      (u8 copy_u8portId, u8 copy_u8pinId,u8 *copy_u8returnedPinValue);

Error_State_t DIO_Error_State_tSetPortDirection (u8 copy_u8portId, u8 copy_u8portDirection);

Error_State_t DIO_Error_State_tSetPortValue     (u8 copy_u8portId, u8 copy_u8portValue);

Error_State_t DIO_Error_State_tGetPortValue     (u8 copy_u8portId, u8 *copy_u8returnedportValue);


#endif
