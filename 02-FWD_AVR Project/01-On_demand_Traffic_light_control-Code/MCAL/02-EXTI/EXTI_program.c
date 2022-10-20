/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 30/09/2022              ***********/
/********** SWC     : EXTI                    ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
/*LIB*/
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/*Global Pointer to a function*/
static void (*EXTI_APFEXTI[3])(void) = {NULL,NULL,NULL};

Error_State_t EXTI_Error_StateEnable(u8 copy_u8EXTIIndex,u8 copy_u8EdgeIndex)
{
	Error_State_t L_enumFunctionState = RET_OK;
	switch(copy_u8EXTIIndex)
	{
		case EXTI_U8_INT0:
			switch(copy_u8EdgeIndex)
			{
				case EXTI_U8_RAISING_EDGE:
				SET_BIT(EXTI_U8_MCUCR_REG,ISC00_BIT);
				SET_BIT(EXTI_U8_MCUCR_REG,ISC01_BIT);
				SET_BIT(EXTI_U8_GICR_REG,INT0_BIT);
				break;
				case EXTI_U8_FALLING_EDGE:
				CLR_BIT(EXTI_U8_MCUCR_REG,ISC00_BIT);
				SET_BIT(EXTI_U8_MCUCR_REG,ISC01_BIT);
				SET_BIT(EXTI_U8_GICR_REG,INT0_BIT);
				break;
				case EXTI_U8_ANY_LOGICAL_CHANGE:
				SET_BIT(EXTI_U8_MCUCR_REG,ISC00_BIT);
				CLR_BIT(EXTI_U8_MCUCR_REG,ISC01_BIT);
				SET_BIT(EXTI_U8_GICR_REG,INT0_BIT);
				break;
				case EXTI_U8_LOW_LEVEL:
				CLR_BIT(EXTI_U8_MCUCR_REG,ISC00_BIT);
				CLR_BIT(EXTI_U8_MCUCR_REG,ISC01_BIT);
				SET_BIT(EXTI_U8_GICR_REG,INT0_BIT);
				break;
				default : L_enumFunctionState = RET_NOK;
				break;
			}
		break;
		case EXTI_U8_INT1:
			switch(copy_u8EdgeIndex)
			{
				case EXTI_U8_RAISING_EDGE:
				SET_BIT(EXTI_U8_MCUCR_REG,ISC10_BIT);
				SET_BIT(EXTI_U8_MCUCR_REG,ISC11_BIT);
				SET_BIT(EXTI_U8_GICR_REG,INT1_BIT);
				break;
				case EXTI_U8_FALLING_EDGE:
				CLR_BIT(EXTI_U8_MCUCR_REG,ISC10_BIT);
				SET_BIT(EXTI_U8_MCUCR_REG,ISC11_BIT);
				SET_BIT(EXTI_U8_GICR_REG,INT1_BIT);
				break;
				case EXTI_U8_ANY_LOGICAL_CHANGE:
				SET_BIT(EXTI_U8_MCUCR_REG,ISC10_BIT);
				CLR_BIT(EXTI_U8_MCUCR_REG,ISC11_BIT);
				SET_BIT(EXTI_U8_GICR_REG,INT1_BIT);
				break;
				case EXTI_U8_LOW_LEVEL:
				CLR_BIT(EXTI_U8_MCUCR_REG,ISC10_BIT);
				CLR_BIT(EXTI_U8_MCUCR_REG,ISC11_BIT);
				SET_BIT(EXTI_U8_GICR_REG,INT1_BIT);
				break;
				default : L_enumFunctionState = RET_NOK;
				break;
			}
		break;		
		case EXTI_U8_INT2:
			switch(copy_u8EdgeIndex)
			{
				case EXTI_U8_RAISING_EDGE:
				SET_BIT(EXTI_U8_MCUCR_REG,ISC10_BIT);
				SET_BIT(EXTI_U8_MCUCR_REG,ISC11_BIT);
				SET_BIT(EXTI_U8_GICR_REG,INT1_BIT);
				break;
				case EXTI_U8_FALLING_EDGE:
				CLR_BIT(EXTI_U8_MCUCSR_REG,ISC2_BIT);
				SET_BIT(EXTI_U8_GICR_REG,INT2_BIT);
				break;
				default : L_enumFunctionState = RET_NOK;
				break;
			}
		break;	
		default : L_enumFunctionState = RET_NOK;
		break;
	}
	return L_enumFunctionState;
}

Error_State_t EXTI_Error_StateDisable(u8 copy_u8EXTIIndex)
{
	Error_State_t L_enumFunctionState = RET_OK;
	switch(copy_u8EXTIIndex) 
	{
		case EXTI_U8_INT0:
		CLR_BIT(EXTI_U8_GICR_REG,INT0_BIT);
		break;
		case EXTI_U8_INT1:
		CLR_BIT(EXTI_U8_GICR_REG,INT1_BIT);
		break;
		case EXTI_U8_INT2:
		CLR_BIT(EXTI_U8_GICR_REG,INT2_BIT);
		break;
		default : L_enumFunctionState = RET_NOK;
		break;
	} 
	return L_enumFunctionState;
}


Error_State_t EXTI_Error_State_tEXTICallBack(void (*copy_PF)(void),u8 copy_u8EXTIIndex)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if((copy_PF != NULL) && (copy_u8EXTIIndex<=EXTI_U8_INT2))
	{
		EXTI_APFEXTI[copy_u8EXTIIndex] = copy_PF;
	}
	else
	{
		L_enumFunctionState = RET_NOK;
	}
	return L_enumFunctionState;
}




/*prototype for ISR of EXTI0*/
void __vector_1(void)	__attribute__((signal));
void __vector_1(void)
{
	if(EXTI_APFEXTI[EXTI_U8_INT0] != NULL)
	{
		EXTI_APFEXTI[EXTI_U8_INT0]();
	}
}

/*prototype for ISR of EXTI1*/
void __vector_2(void)	__attribute__((signal));
void __vector_2(void)
{
	if(EXTI_APFEXTI[EXTI_U8_INT1] != NULL)
	{
		EXTI_APFEXTI[EXTI_U8_INT1]();
	}
}

/*prototype for ISR of EXTI2*/
void __vector_3(void)	__attribute__((signal));
void __vector_3(void)
{
	if(EXTI_APFEXTI[EXTI_U8_INT2] != NULL)
	{
		EXTI_APFEXTI[EXTI_U8_INT2]();
	}
}
