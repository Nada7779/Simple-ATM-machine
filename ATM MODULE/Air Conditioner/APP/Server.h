#ifndef SERVER_H_
#define SERVER_H_


#include "../SERVICE/STD_TYPES.h"


// for transaction state
typedef enum EN_transState_t
{
     APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t ;





typedef enum EN_serverError_t
{
    SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
} EN_serverError_t ;



typedef enum EN_accountState_t
{
    RUNNING,
    BLOCKED
} EN_accountState_t;




typedef struct ST_accountsDB_t
{
    float balance;
    EN_accountState_t state;
    uint8_t primaryAccountNumber[17];
} ST_accountsDB_t;

#define ACC_Index	10
#define COUNT_Index	16
#define False	0
#define True	1

/******************* Functions prototypes *************************/



EN_serverError_t isValidAccount(uint8_t *pan);

EN_serverError_t isBlockedAccount();

EN_serverError_t isAmountAvailable(float *termData);



extern EN_serverError_t _isValidAccount ;
extern EN_serverError_t _isBlockedAccount ;
extern EN_serverError_t _isAmountAvailable ;

extern ST_accountsDB_t *p_account ;

#endif // SERVER_H_INCLUDED


