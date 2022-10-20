#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	EN_terminalError_t L_strFunctionState = OK;
	if (termData != NULL)
	{
		printf("Please, Enter the transaction date   : ");
		gets_s(termData->transactionDate,15);
		if (termData->transactionDate[2]=='/'&& termData->transactionDate[5] == '/'&& termData->transactionDate[10]=='\0')
		{
			if (Terminal_checkDayFormat(termData) == OK && Terminal_checkMonthFormat(termData) == OK)
			{
				L_strFunctionState = OK;
			}
			else
			{
				L_strFunctionState = WRONG_DATE;
			}
		}
		else
		{
			L_strFunctionState = WRONG_DATE;
		}
	}
	else
	{
		L_strFunctionState = WRONG_DATE;
	}
	return L_strFunctionState;
}



EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	EN_terminalError_t L_strFunctionState = OK;
	if(isYearCardExpired(cardData,termData)==OK)
	{
		L_strFunctionState = OK;
		
	}
	else
	{
		if (isMonthCardExpired(cardData, termData) == OK)
		{
			L_strFunctionState = OK;
		}
		else
		{
			L_strFunctionState = EXPIRED_CARD;
		}
	}
	return L_strFunctionState;
}


EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t L_strFunctionState = OK;
	if (termData != NULL)
	{
		printf("Please, Enter The transaction amount : ");
		scanf_s("%f",&termData->transAmount);
		if (termData->transAmount <= 0)
		{
			L_strFunctionState = INVALID_AMOUNT;
		}
		else
		{
			L_strFunctionState = OK;
		}
	}
	else
	{
		L_strFunctionState = INVALID_AMOUNT;
	}
	return L_strFunctionState;
}


EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)

{
	EN_terminalError_t L_strFunctionState = OK;
	float32_t L_float32_tMaxBalance = 0;
	if (termData != NULL)
	{
		/*if (checkTransactionBalance(&L_float32_tMaxBalance) == 2)// 2 -> APPROVED
		{
			termData->maxTransAmount = L_float32_tMaxBalance;
		}else{}*/
		termData->maxTransAmount = 50000;
		if (termData->maxTransAmount <= 0)
		{
			L_strFunctionState = INVALID_MAX_AMOUNT;
		}
		else
		{
			L_strFunctionState = OK;
		}
	}
	else
	{
		L_strFunctionState = INVALID_MAX_AMOUNT;
	}
	return L_strFunctionState;
}



EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t L_strFunctionState = OK;
	if (termData != NULL)
	{
		if (termData->transAmount > termData->maxTransAmount)
		{
			L_strFunctionState = EXCEED_MAX_AMOUNT;
		}
		else
		{
			L_strFunctionState = OK;
		}
	}
	else
	{
		L_strFunctionState = EXCEED_MAX_AMOUNT;
	}
	return L_strFunctionState;
}











EN_cardError_t Terminal_checkDayFormat(ST_terminalData_t* cardData)
{
	EN_cardError_t L_strFunctionState = OK;
	if (cardData != NULL)
	{
		if (cardData->transactionDate[0] > '3')
		{
			L_strFunctionState = WRONG_DATE;
		}
		else if (cardData->transactionDate[0] == '3' && cardData->transactionDate[1] > '1')
		{
			L_strFunctionState = WRONG_DATE;
		}
		else
		{
			L_strFunctionState = OK;
		}
	}
	else
	{
		L_strFunctionState = WRONG_DATE;
	}
	return L_strFunctionState;
}





EN_cardError_t Terminal_checkMonthFormat(ST_terminalData_t* cardData)
{
	EN_cardError_t L_strFunctionState = OK;
	if (cardData != NULL)
	{
		if (cardData->transactionDate[3] >= '1')
		{
			if (cardData->transactionDate[3] == '1')
			{
				if (cardData->transactionDate[4] > '2')
				{
					L_strFunctionState = WRONG_DATE;
				}
				else
				{
					L_strFunctionState = OK;

				}
			}
			else
			{
				L_strFunctionState = WRONG_DATE;
			}
		}
		else
		{
			L_strFunctionState = OK;
		}
	}
	else
	{
		L_strFunctionState = WRONG_DATE;
	}

	return L_strFunctionState;
}


EN_terminalError_t isMonthCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	EN_terminalError_t L_strFunctionState = OK;
	if (cardData.cardExpirationDate[0] > termData.transactionDate[3])
	{
		EN_terminalError_t L_strFunctionState = OK;
	}
	else if (cardData.cardExpirationDate[0] == termData.transactionDate[3])
	{
		if (cardData.cardExpirationDate[1] >= termData.transactionDate[4])
		{
			L_strFunctionState = OK;
		}
		else
		{
			L_strFunctionState = EXPIRED_CARD;
		}
	}
	else
	{
		L_strFunctionState = EXPIRED_CARD;
	}
	return L_strFunctionState;
}


EN_terminalError_t isYearCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	EN_terminalError_t L_strFunctionState = OK;
	if (cardData.cardExpirationDate[3] > termData.transactionDate[8])
	{
		L_strFunctionState = OK;
	}
	else if (cardData.cardExpirationDate[3] == termData.transactionDate[8])
	{
		if (cardData.cardExpirationDate[4] >= termData.transactionDate[9])
		{
			L_strFunctionState = OK;
		}
		else
		{
			L_strFunctionState = EXPIRED_CARD;
		}
	}
	else
	{
		L_strFunctionState = EXPIRED_CARD;
	}
	return L_strFunctionState;
}