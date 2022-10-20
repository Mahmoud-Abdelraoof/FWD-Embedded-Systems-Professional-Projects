#include "app.h"

#define decode(a,b,c,d) a##b##c##d
#define appStart decode(m,a,i,n)




int appStart()
{
	extern ST_cardData_t L_strCard;
	extern ST_terminalData_t L_strterminal;
	ST_transaction_t L_strTransData;
	uint16_t L_uint16_tSaveTransactionSequenceNumber = 0;
	float32_t L_float32_tRestBalance = 0;
	if (getCardHolderName(&L_strCard) == WRONG_NAME)
	{
		printf("Error!! The name you entered is invalid, try again, noting that the number of letters in the name is from 20-24...\n");
	}
	else
	{
		if (getCardExpiryDate(&L_strCard) == WRONG_EXP_DATE)
		{
			printf("Error!! Please, Enter the Expiration Data in month/year format such as 07/28\n");
		}
		else
		{
			if (getCardPAN(&L_strCard) == WRONG_PAN)
			{
				printf("Error!! The number you entered is invalid, try again, noting that the number consists of 16 - 19 characters...\n");
			}
			else
			{
				if (getTransactionDate(&L_strterminal) == WRONG_DATE)
				{
					printf("Error!! Please, Enter the transaction date in day/month/year format such as 05/08/2028\n");
				}
				else
				{
					if (isCardExpired(L_strCard, L_strterminal) == EXPIRED_CARD)
					{
						printf("Error!! The Card is Expired...\n");
					}
					else
					{
						if (getTransactionAmount(&L_strterminal) == INVALID_AMOUNT)
						{
							printf("Error!! Invalid amount...\n");
						}
						else
						{
							setMaxAmount(&L_strterminal);
							if (L_strterminal.transAmount > L_strterminal.maxTransAmount)
							{
								printf("Error!! Exceed the Maximim amount...\n");
							}
							else
							{ 
								if (isValidAccount(&L_strCard) == DECLINED_STOLEN_CARD)
								{
									printf("Error!! STOLEN CARD...\n");
								}
								else
								{
									if (isAmountAvailable(&L_strCard,&L_float32_tRestBalance) == LOW_BALANCE)
									{
										printf("SORRY!! This amount is not available in your account...\n");
									}
									else
									{
										if (saveTransaction(&L_uint16_tSaveTransactionSequenceNumber) == OK)
										{
											printf("Payment completed successfully...\n");
											printf("_______________________________________________________________\n");
											printf("Your current balance is              : %f\n", L_float32_tRestBalance);
											printf("Sequence Number of the Transaction is: %d\n", L_uint16_tSaveTransactionSequenceNumber);
										}
										else if (saveTransaction(&L_uint16_tSaveTransactionSequenceNumber) == SAVING_FAILED_EXP)
										{
											printf("Error!! Can't save the Card Expiration Date Name...\n");
										}
										else if (saveTransaction(&L_uint16_tSaveTransactionSequenceNumber) == SAVING_FAILED_NAME)
										{
											printf("Error!! Can't save the Cardholder Name...\n");
										}
										else if (saveTransaction(&L_uint16_tSaveTransactionSequenceNumber) == SAVING_FAILED_PAN)
										{
											printf("Error!! Can't save the PAN...\n");
										}
									}
								}
								
							}

						}
					}
				}
			}
		}
	}
	printf("_______________________________________________________________\n");
	printf("Thanks for using THE PAYMENT APPLICATION.\n");
	printf("This APP is created by: Eng.Mahmoud Abdelraoof Mahmoud.\n");
	printf("                 GOOD BYE\n");
	printf("_______________________________________________________________\n");

	


	return 0;
}