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
#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"


void GIE_voidEnable(void)
{
	SET_BIT(GIE_U8_SREG_REG,GIE_U8_SREG_BIT);
}

void GIE_voidDisable(void)
{
	CLR_BIT(GIE_U8_SREG_REG,GIE_U8_SREG_BIT);
}
