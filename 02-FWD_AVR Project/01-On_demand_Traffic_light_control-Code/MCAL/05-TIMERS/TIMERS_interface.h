/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 10/10/2022              ***********/
/********** SWC     : TIMERS                  ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H


/*Interrupt Vectors for TIPMERS0*/
#define TIMERS_U8_CMP_MTH_INTRPT			11	//Timer/Counter0 Output Compare Match Interrupt Enable
#define TIMERS_U8_OVF_INTRPT				12	//Timer/Counter0 Overflow Interrupt Enable




Error_State_t TIMERS_Error_State_tTimer0Init(void);

Error_State_t TIMERS_Error_State_tSetCallBack(void (*copy_pf)(void),u8 copy_u8TimersINTRPTIndex);

void TIMERS_voidTimer0SetCompareMatchValue(u8 copy_u8OCR0Value);


void TIMERS_voidTimerDelay_ms(u16 copy_u16DelayTimeIn_ms);




#endif
