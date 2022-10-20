#ifndef SERVER_H
#define SERVER_H

#include <string.h>
#include "STD_TYPES.h"
#include "card.h"
#include "terminal.h"


typedef enum EN_transState_t
{
	APPROVED = 2, 
	DECLINED_INSUFFECIENT_FUND, 
	DECLINED_STOLEN_CARD, 
	INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef enum EN_serverError_t
{ 
	//OK,
	SAVING_FAILED_NAME = 3,
	SAVING_FAILED_EXP,
	SAVING_FAILED_PAN,
	TRANSACTION_NOT_FOUND, 
	ACCOUNT_NOT_FOUND, 
	LOW_BALANCE
}EN_serverError_t;


typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState;
	uint32_t transactionSequenceNumber;
}ST_transaction_t;


typedef struct ST_accountsDB_t
{
	float balance;
	uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;



EN_transState_t recieveTransactionData(ST_transaction_t* transData);
EN_transState_t checkTransactionPAN(void);
EN_transState_t checkTransactionBalance(float32_t* copt_float32_tMaxBalance);
EN_serverError_t isValidAccount(ST_cardData_t* cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, float32_t* copy_float32_tRestBalance);
EN_serverError_t saveTransaction(uint16_t* copy_uint16_tSequenceNumber);
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData);

#endif