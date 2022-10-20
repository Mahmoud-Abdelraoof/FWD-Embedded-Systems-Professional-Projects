#include "card.h"


EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	EN_cardError_t L_strFunctionState = OK;
	if (cardData != NULL)
	{
		uint16_t L_uint16CounterName = 0;
		printf("Pleade, Enter Cardholder Name        : ");
		gets_s(cardData->cardHolderName, 25);
		for (uint16_t i = 0; cardData->cardHolderName[i] != '\0'; i++)
		{
			L_uint16CounterName++;
		}
		if (L_uint16CounterName < 20 || L_uint16CounterName>24)
		{
			L_strFunctionState = WRONG_NAME;
		}
	}
	else
	{
		L_strFunctionState = WRONG_NAME;
	}



	return L_strFunctionState;
}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	EN_cardError_t L_strFunctionState = OK;
	if (cardData != NULL)
	{
		printf("Please, Enter Expiration date        : ");
		gets_s(cardData->cardExpirationDate,6);
		//month
		if (checkMonthFormat(cardData) == OK&& checkYearFormat(cardData)==OK)
		{
			L_strFunctionState = OK;
		}
		else
		{
			L_strFunctionState = WRONG_EXP_DATE;
		}
	}
	else
	{
		L_strFunctionState = WRONG_EXP_DATE;
	}


	return L_strFunctionState;
}


EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	EN_cardError_t L_strFunctionState = OK;
	uint16_t L_uint16CounterPAN = 0;
	if (cardData != NULL)
	{
		printf("Please, Enter the PAN                : ");
		gets_s(cardData->primaryAccountNumber,20);
		for (uint16_t i = 0; cardData->primaryAccountNumber[i] != '\0'; i++)
		{
			L_uint16CounterPAN++;
		}
		if (L_uint16CounterPAN < 16 || L_uint16CounterPAN>19)
		{
			L_strFunctionState = WRONG_PAN;
		}
	}
	else
	{
		L_strFunctionState = WRONG_PAN;
	}

	return L_strFunctionState;
}

//month
EN_cardError_t checkMonthFormat(ST_cardData_t* cardData)
{
	EN_cardError_t L_strFunctionState = OK;
	if (cardData != NULL)
	{
		if ((cardData->cardExpirationDate[2] != '/') || (cardData->cardExpirationDate[0] >= '1'))
		{
			if (cardData->cardExpirationDate[0] == '1')
			{
				if (cardData->cardExpirationDate[1] > '2')
				{
					L_strFunctionState = WRONG_EXP_DATE;
				}
				else
				{
					L_strFunctionState = OK;

				}
			}
			else
			{
				L_strFunctionState = WRONG_EXP_DATE;
			}
		}
		else
		{
			L_strFunctionState = OK;
		}
	}
	else
	{
		L_strFunctionState = WRONG_EXP_DATE;
	}
	
	return L_strFunctionState;
}

//year
EN_cardError_t checkYearFormat(ST_cardData_t* cardData)
{
	EN_cardError_t L_strFunctionState = OK;
	if (cardData != NULL)
	{
		if (cardData->cardExpirationDate[5] != '\0')
		{
			L_strFunctionState = WRONG_EXP_DATE;
		}
		else
		{
			L_strFunctionState = OK;
		}
	}
	else
	{

	}
	return L_strFunctionState;
}