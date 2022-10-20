#include "server.h"

ST_accountsDB_t L_strValidAccounts[255] = 
{
	[0].balance  = 10000, [0].primaryAccountNumber  = "14523698744152893",
	[1].balance  = 15000, [1].primaryAccountNumber  = "4524878459446565454",
	[2].balance  = 25000, [2].primaryAccountNumber  = "17854123698741253",
	[3].balance  = 30000, [3].primaryAccountNumber  = "109125140236658784",
	[4].balance  = 18000, [4].primaryAccountNumber  = "108125140236658784",
	[5].balance  = 19500, [5].primaryAccountNumber  = "107125040236658784",
	[6].balance  = 35000, [6].primaryAccountNumber  = "105125140236658784",
	[7].balance  = 40000, [7].primaryAccountNumber  = "104125140236658784",
	[8].balance  = 43000, [8].primaryAccountNumber  = "103125140236658784",
	[9].balance  = 17500, [9].primaryAccountNumber  = "102125140236658784",
	[10].balance = 47000, [10].primaryAccountNumber = "101125140236658784",
	[11].balance = 50000, [11].primaryAccountNumber = "100125140236658784",
	[12].balance = 68000, [12].primaryAccountNumber = "1101251340236658784",
};

ST_transaction_t L_strTransactionDatabase[255] = { 0 };
ST_cardData_t L_strCard;
ST_terminalData_t L_strterminal;
uint16_t server_PANCounter = 0;
uint16_t server_uint16_tisValidAccountCounter = 0;




EN_transState_t checkTransactionPAN(void)
{
	EN_transState_t L_strFunctionState = DECLINED_STOLEN_CARD;
	for (uint16_t i = 0; i < 13; i++)
	{
		if (strcmp(L_strCard.primaryAccountNumber, L_strValidAccounts[i].primaryAccountNumber) == 0)
		{
			server_PANCounter = i;
			L_strFunctionState = APPROVED;
			break;
		}
		else {}
	}
	return L_strFunctionState;
}


EN_transState_t checkTransactionBalance(float32_t* copt_float32_tMaxBalance)
{
	EN_transState_t L_strFunctionState = APPROVED;
	if (copt_float32_tMaxBalance != NULL)
	{
		if (checkTransactionPAN() == APPROVED)
		{
			*copt_float32_tMaxBalance = L_strterminal.transAmount;
			if (*copt_float32_tMaxBalance > L_strValidAccounts[server_PANCounter].balance)
			{
				L_strFunctionState = DECLINED_INSUFFECIENT_FUND;
			}
			else
			{
				L_strFunctionState = APPROVED;
			}
		}
		else
		{
			L_strFunctionState = DECLINED_INSUFFECIENT_FUND;
		}
	}
	else
	{
		L_strFunctionState = DECLINED_INSUFFECIENT_FUND;
	}


	return L_strFunctionState;
}



EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	EN_transState_t L_strFunctionState = APPROVED;
	float32_t L_float32_tMaxBalance = 0;
	if (transData != NULL)
	{
		if (checkTransactionPAN() != APPROVED)
		{
			L_strFunctionState = DECLINED_STOLEN_CARD;
		}else{}
		if (checkTransactionBalance(&L_float32_tMaxBalance) == DECLINED_INSUFFECIENT_FUND)
		{
			L_strFunctionState = DECLINED_INSUFFECIENT_FUND;
		}
		else
		{
			L_strValidAccounts[server_PANCounter].balance -= L_float32_tMaxBalance;
			printf("The balance after payment: %f.\n", L_strValidAccounts[server_PANCounter].balance);
		}
	}
	else
	{
		L_strFunctionState = DECLINED_STOLEN_CARD;
	}
	
	return L_strFunctionState;
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	EN_serverError_t L_strFunctionState = DECLINED_STOLEN_CARD;
	if (cardData != NULL)
	{
		for (uint16_t i = 0; i < 13; i++)
		{
			if (strcmp(cardData->primaryAccountNumber, L_strValidAccounts[i].primaryAccountNumber) == 0)
			{
				server_uint16_tisValidAccountCounter = i;
				L_strFunctionState = OK;
				break;
			}else {}
		}
	}
	else
	{
		L_strFunctionState = DECLINED_STOLEN_CARD;
	}
	return L_strFunctionState;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData,float32_t *copy_float32_tRestBalance)
{
	EN_serverError_t L_strFunctionState = OK;
	float32_t L_float32_tNewBalance = 0;
	if (termData != NULL)
	{
		L_float32_tNewBalance = L_strValidAccounts[server_uint16_tisValidAccountCounter].balance;
		if (L_strterminal.transAmount > L_float32_tNewBalance)
		{
			L_strFunctionState = LOW_BALANCE;
		}
		else
		{
			L_strFunctionState = OK;
			*copy_float32_tRestBalance = L_float32_tNewBalance - L_strterminal.transAmount;
		}
	}
	else
	{
		L_strFunctionState = LOW_BALANCE;
	}
	return L_strFunctionState;
}

EN_serverError_t saveTransaction(uint16_t *copy_uint16_tSequenceNumber)
{
	EN_serverError_t L_strFunctionState = OK;
	*copy_uint16_tSequenceNumber = server_uint16_tisValidAccountCounter+1;
	uint16_t j = 0;
	for (j = 0; j < 6; j++)
	{
		L_strTransactionDatabase[server_uint16_tisValidAccountCounter].cardHolderData.cardExpirationDate[j] = L_strCard.cardExpirationDate[j];
		if (L_strCard.primaryAccountNumber[j] == '\0')
		{
			L_strFunctionState = OK;
			break;
		}
		else
		{
			L_strFunctionState = SAVING_FAILED_EXP;
		}
	}
	for (j = 0;j< 25;j++)
	{
		L_strTransactionDatabase[server_uint16_tisValidAccountCounter].cardHolderData.cardHolderName[j] = L_strCard.cardHolderName[j];
		if (L_strCard.primaryAccountNumber[j] == '\0')
		{
			L_strFunctionState = OK;
			break;
		}
		else
		{
			L_strFunctionState = SAVING_FAILED_NAME;
		}
	}
	for (j = 0; j < 20; j++)
	{
		L_strTransactionDatabase[server_uint16_tisValidAccountCounter].cardHolderData.primaryAccountNumber[j] = L_strCard.primaryAccountNumber[j];
		if (L_strCard.primaryAccountNumber[j] == '\0')
		{
			L_strFunctionState = OK;
			break;
		}
		else
		{
			L_strFunctionState = SAVING_FAILED_PAN;
		}
	}
	return L_strFunctionState;
}