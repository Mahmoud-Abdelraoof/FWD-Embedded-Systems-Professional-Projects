/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 30/09/2022              ***********/
/********** SWC     : EXTI                    ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define EXTI_U8_INT0					0
#define EXTI_U8_INT1					1
#define EXTI_U8_INT2					2


#define EXTI_U8_RAISING_EDGE			0
#define EXTI_U8_FALLING_EDGE			1
#define EXTI_U8_ANY_LOGICAL_CHANGE		2
#define EXTI_U8_LOW_LEVEL				3



Error_State_t EXTI_Error_StateEnable(u8 copy_u8EXTIIndex,u8 copy_u8EdgeIndex);

Error_State_t EXTI_Error_StateDisable(u8 copy_u8EXTIIndex);

Error_State_t EXTI_Error_State_tEXTICallBack(void (*copy_PF)(void),u8 copy_u8EXTIIndex);




#endif
