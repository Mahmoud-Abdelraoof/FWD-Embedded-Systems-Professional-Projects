/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 18/09/2022              ***********/
/********** SWC     : DIO                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/

/*lib layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
void DIO_voidInit(void)
{
/****************************************************************************************************************************************************/
	DIO_U8_DDRA_REG = Conc(DIO_U8_PA7_INITIAL_DIRECTION,DIO_U8_PA6_INITIAL_DIRECTION,DIO_U8_PA5_INITIAL_DIRECTION,DIO_U8_PA4_INITIAL_DIRECTION,
						   DIO_U8_PA3_INITIAL_DIRECTION,DIO_U8_PA2_INITIAL_DIRECTION,DIO_U8_PA1_INITIAL_DIRECTION,DIO_U8_PA0_INITIAL_DIRECTION);
						   
	DIO_U8_DDRB_REG = Conc(DIO_U8_PB7_INITIAL_DIRECTION,DIO_U8_PB6_INITIAL_DIRECTION,DIO_U8_PB5_INITIAL_DIRECTION,DIO_U8_PB4_INITIAL_DIRECTION,
						   DIO_U8_PB3_INITIAL_DIRECTION,DIO_U8_PB2_INITIAL_DIRECTION,DIO_U8_PB1_INITIAL_DIRECTION,DIO_U8_PB0_INITIAL_DIRECTION);
						   
	DIO_U8_DDRC_REG = Conc(DIO_U8_PC7_INITIAL_DIRECTION,DIO_U8_PC6_INITIAL_DIRECTION,DIO_U8_PC5_INITIAL_DIRECTION,DIO_U8_PC4_INITIAL_DIRECTION,
						   DIO_U8_PC3_INITIAL_DIRECTION,DIO_U8_PC2_INITIAL_DIRECTION,DIO_U8_PC1_INITIAL_DIRECTION,DIO_U8_PC0_INITIAL_DIRECTION);
						   
	DIO_U8_DDRD_REG = Conc(DIO_U8_PD7_INITIAL_DIRECTION,DIO_U8_PD6_INITIAL_DIRECTION,DIO_U8_PD5_INITIAL_DIRECTION,DIO_U8_PD4_INITIAL_DIRECTION,
						   DIO_U8_PD3_INITIAL_DIRECTION,DIO_U8_PD2_INITIAL_DIRECTION,DIO_U8_PD1_INITIAL_DIRECTION,DIO_U8_PD0_INITIAL_DIRECTION);
/****************************************************************************************************************************************************/	   
	DIO_U8_PORTA_REG = Conc(DIO_U8_PA7_INITIAL_VALUE,DIO_U8_PA6_INITIAL_VALUE,DIO_U8_PA5_INITIAL_VALUE,DIO_U8_PA4_INITIAL_VALUE,
						   DIO_U8_PA3_INITIAL_VALUE,DIO_U8_PA2_INITIAL_VALUE,DIO_U8_PA1_INITIAL_VALUE,DIO_U8_PA0_INITIAL_VALUE);
						   
	DIO_U8_PORTB_REG = Conc(DIO_U8_PB7_INITIAL_VALUE,DIO_U8_PB6_INITIAL_VALUE,DIO_U8_PB5_INITIAL_VALUE,DIO_U8_PB4_INITIAL_VALUE,
						   DIO_U8_PB3_INITIAL_VALUE,DIO_U8_PB2_INITIAL_VALUE,DIO_U8_PB1_INITIAL_VALUE,DIO_U8_PB0_INITIAL_VALUE);
						   
	DIO_U8_PORTC_REG = Conc(DIO_U8_PC7_INITIAL_VALUE,DIO_U8_PC6_INITIAL_VALUE,DIO_U8_PC5_INITIAL_VALUE,DIO_U8_PC4_INITIAL_VALUE,
						   DIO_U8_PC3_INITIAL_VALUE,DIO_U8_PC2_INITIAL_VALUE,DIO_U8_PC1_INITIAL_VALUE,DIO_U8_PC0_INITIAL_VALUE);
						   
	DIO_U8_PORTD_REG = Conc(DIO_U8_PD7_INITIAL_VALUE,DIO_U8_PD6_INITIAL_VALUE,DIO_U8_PD5_INITIAL_VALUE,DIO_U8_PD4_INITIAL_VALUE,
						   DIO_U8_PD3_INITIAL_VALUE,DIO_U8_PD2_INITIAL_VALUE,DIO_U8_PD1_INITIAL_VALUE,DIO_U8_PD0_INITIAL_VALUE);
}


/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tSetPinDirection(u8 copy_u8portId, u8 copy_u8pinId,u8 copy_u8pinDirection)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if((copy_u8portId <= DIO_U8_PORTD) && (copy_u8pinId<=DIO_U8_PIN7) && ((copy_u8pinDirection==DIO_U8_OUTPUT) || (copy_u8pinDirection==DIO_U8_INPUT)))
	{
		switch (copy_u8portId)
		{
			case DIO_U8_PORTA:
				switch (copy_u8pinDirection)
				{
					case DIO_U8_OUTPUT:SET_BIT(DIO_U8_DDRA_REG,copy_u8pinId);break;
					case DIO_U8_INPUT :CLR_BIT(DIO_U8_DDRA_REG,copy_u8pinId);break;
				}
			break;
			case DIO_U8_PORTB:
				switch (copy_u8pinDirection)
				{
					case DIO_U8_OUTPUT:SET_BIT(DIO_U8_DDRB_REG,copy_u8pinId);break;
					case DIO_U8_INPUT :CLR_BIT(DIO_U8_DDRB_REG,copy_u8pinId);break;
				}
			break;
			case DIO_U8_PORTC:
				switch (copy_u8pinDirection)
				{
					case DIO_U8_OUTPUT:SET_BIT(DIO_U8_DDRC_REG,copy_u8pinId);break;
					case DIO_U8_INPUT :CLR_BIT(DIO_U8_DDRC_REG,copy_u8pinId);break;
				}
			break;
			case DIO_U8_PORTD:
				switch (copy_u8pinDirection)
				{
					case DIO_U8_OUTPUT:SET_BIT(DIO_U8_DDRD_REG,copy_u8pinId);break;
					case DIO_U8_INPUT :CLR_BIT(DIO_U8_DDRD_REG,copy_u8pinId);break;
				}
			break;
		}
	}
	else
	{
		L_enumFunctionState = RET_NOK;
	}
	return L_enumFunctionState;
	
}
/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tSetPinValue(u8 copy_u8portId, u8 copy_u8pinId,u8 copy_u8pinValue)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if(copy_u8pinId<=DIO_U8_PIN7)
	{
		switch (copy_u8portId)
		{
			case DIO_U8_PORTA:
				switch(copy_u8pinValue)
				{	
					case DIO_U8_HIGH: SET_BIT(DIO_U8_PORTA_REG,copy_u8pinId);break;
					case DIO_U8_LOW : CLR_BIT(DIO_U8_PORTA_REG,copy_u8pinId);break;
					default: L_enumFunctionState = RET_NOK;
				}
			break;
			case DIO_U8_PORTB:
				switch(copy_u8pinValue)
				{
					case DIO_U8_HIGH: SET_BIT(DIO_U8_PORTB_REG,copy_u8pinId);break;
					case DIO_U8_LOW : CLR_BIT(DIO_U8_PORTB_REG,copy_u8pinId);break;
					default: L_enumFunctionState = RET_NOK;
				}
			break;
			case DIO_U8_PORTC:
				switch(copy_u8pinValue)
				{
					case DIO_U8_HIGH: SET_BIT(DIO_U8_PORTC_REG,copy_u8pinId);break;
					case DIO_U8_LOW : CLR_BIT(DIO_U8_PORTC_REG,copy_u8pinId);break;
					default: L_enumFunctionState = RET_NOK;
				}
			break;
			case DIO_U8_PORTD:
				switch(copy_u8pinValue)
				{
					case DIO_U8_HIGH: SET_BIT(DIO_U8_PORTD_REG,copy_u8pinId);break;
					case DIO_U8_LOW : CLR_BIT(DIO_U8_PORTD_REG,copy_u8pinId);break;
					default: L_enumFunctionState = RET_NOK;
				}
			break;
			default:
			L_enumFunctionState = RET_NOK;
			break;
		}
	}
	else
	{
		L_enumFunctionState = RET_NOK;
	}
	return L_enumFunctionState;
}
/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tGetPinValue(u8 copy_u8portId, u8 copy_u8pinId,u8 *copy_u8returnedPinValue)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if((copy_u8pinId<=DIO_U8_PIN7) && (NULL!=copy_u8returnedPinValue))
	{
		switch (copy_u8portId)
		{
			case DIO_U8_PORTA:*copy_u8returnedPinValue = GET_BIT(DIO_U8_PINA_REG,copy_u8pinId);
			if(*copy_u8returnedPinValue==0)
			{
				*copy_u8returnedPinValue = DIO_U8_LOW;
			}
			else
			{
				*copy_u8returnedPinValue = DIO_U8_HIGH;
			}
			break;
			case DIO_U8_PORTB:*copy_u8returnedPinValue = GET_BIT(DIO_U8_PINB_REG,copy_u8pinId);
			if(*copy_u8returnedPinValue==0)
			{
				*copy_u8returnedPinValue = DIO_U8_LOW;
			}
			else
			{
				*copy_u8returnedPinValue = DIO_U8_HIGH;
			}
			break;
			case DIO_U8_PORTC:*copy_u8returnedPinValue = GET_BIT(DIO_U8_PINC_REG,copy_u8pinId);
			if(*copy_u8returnedPinValue==0)
			{
				*copy_u8returnedPinValue = DIO_U8_LOW;
			}
			else
			{
				*copy_u8returnedPinValue = DIO_U8_HIGH;
			}
			break;
			case DIO_U8_PORTD:*copy_u8returnedPinValue = GET_BIT(DIO_U8_PIND_REG,copy_u8pinId);
			if(*copy_u8returnedPinValue==0)
			{
				*copy_u8returnedPinValue = DIO_U8_LOW;
			}
			else
			{
				*copy_u8returnedPinValue = DIO_U8_HIGH;
			}
			break;
			default:
			L_enumFunctionState = RET_NOK;
			break;
		}
	}
	else
	{
		L_enumFunctionState  =RET_NOK;
	}
	return L_enumFunctionState;
}
/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tSetPortDirection(u8 copy_u8portId, u8 copy_u8portDirection)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if(copy_u8portDirection==DIO_U8_OUTPUT||copy_u8portDirection==DIO_U8_INPUT)
	{
		switch(copy_u8portId)
		{
			case DIO_U8_PORTA:
				switch(copy_u8portDirection)
				{
					case DIO_U8_OUTPUT:DIO_U8_DDRA_REG = 0XFF;break;
					case DIO_U8_INPUT :DIO_U8_DDRA_REG = 0X00;break;
					default: L_enumFunctionState = RET_NOK;break;
				}
			break;
			case DIO_U8_PORTB:
				switch(copy_u8portDirection)
				{
					case DIO_U8_OUTPUT:DIO_U8_DDRB_REG = 0XFF;break;
					case DIO_U8_INPUT :DIO_U8_DDRB_REG = 0X00;break;
					default: L_enumFunctionState = RET_NOK;break;
				}
			break;
			case DIO_U8_PORTC:
				switch(copy_u8portDirection)
				{
					case DIO_U8_OUTPUT:DIO_U8_DDRC_REG = 0XFF;break;
					case DIO_U8_INPUT :DIO_U8_DDRC_REG = 0X00;break;
					default: L_enumFunctionState = RET_NOK;break;
				}
			break;
			case DIO_U8_PORTD:
				switch(copy_u8portDirection)
				{
					case DIO_U8_OUTPUT:DIO_U8_DDRD_REG = 0XFF;break;
					case DIO_U8_INPUT :DIO_U8_DDRD_REG = 0X00;break;
					default: L_enumFunctionState = RET_NOK;break;
				}
			break;
			default: L_enumFunctionState = RET_NOK;
		}
	}
	else
	{
		L_enumFunctionState = RET_NOK;
	}
	return L_enumFunctionState;
}
/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tSetPortValue(u8 copy_u8portId, u8 copy_u8portValue)
{
	Error_State_t L_enumFunctionState = RET_OK;
	switch(copy_u8portId)
	{
		case DIO_U8_PORTA: DIO_U8_PORTA_REG = copy_u8portValue;break;
		case DIO_U8_PORTB: DIO_U8_PORTB_REG = copy_u8portValue;break;
		case DIO_U8_PORTC: DIO_U8_PORTC_REG = copy_u8portValue;break;
		case DIO_U8_PORTD: DIO_U8_PORTD_REG = copy_u8portValue;break;
		default: L_enumFunctionState = RET_NOK;break;
	}
	return L_enumFunctionState;
}
/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tGetPortValue(u8 copy_u8portId, u8 *copy_u8returnedportValue)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if(NULL!=copy_u8returnedportValue)
	{
		switch(copy_u8portId)
		{
			case DIO_U8_PORTA: *copy_u8returnedportValue = DIO_U8_PINA_REG;break;
			case DIO_U8_PORTB: *copy_u8returnedportValue = DIO_U8_PINB_REG;break;
			case DIO_U8_PORTC: *copy_u8returnedportValue = DIO_U8_PINC_REG;break;
			case DIO_U8_PORTD: *copy_u8returnedportValue = DIO_U8_PIND_REG;break;
			default: L_enumFunctionState = RET_NOK;
		}
	}
	else
	{
		L_enumFunctionState = RET_NULL_PTR;
	}
	
	
	return L_enumFunctionState;
}
