
#include "database.h"

 EN_serverError_t _isValidAccount ;
 EN_serverError_t _isBlockedAccount ;
 EN_serverError_t _isAmountAvailable ;
 EN_serverError_t _saveTransaction ;
ST_accountsDB_t *p_account = accountsDB;

uint8_t t = False;
uint8_t trans_num=False;







/** REQUIRMENTS :-
 1- check pan given with pan in database   --- (done)
 2- if exists  --> SEREVER_OK           ----> return reference to this account in the DB    --- (done)
 3- if not     --> ACCOUNT_NOT_FOUND    ----> return ACCOUNT_NOT_FOUND
                                        ----> account reference will be NULL


/******************************************* isValidAccount **********************************************/
//calling database and card data

EN_serverError_t isValidAccount(uint8_t *pan )
{

    uint8_t exist_flag = False ;
    EN_serverError_t server_status ;

    for(uint8_t account_num= False ; account_num< ACC_Index ; account_num++) // num of accounts
    {
        for(uint8_t counter = False ; counter < COUNT_Index ; counter++)
        {
            if( pan[counter] == (p_account)->primaryAccountNumber[counter] )
            {
                exist_flag =True ;
				
            }
            else
            {
                p_account++;
                exist_flag =False;
                break ;
            }
        }
		
		if (exist_flag)
		{
			break;
		}
		
		
    }

    if(exist_flag)
    {
        server_status = SERVER_OK ;
    }
    else
    {
        server_status =ACCOUNT_NOT_FOUND  ;
        p_account = NULL ;

    }




    return server_status ;
}

// implement test function here



/*************************************** END OF isValidAccount ***********************************************/






/******************************************* isBlockedAccount **********************************************/
//calling pointer to account


EN_serverError_t isBlockedAccount()
{

    if(_isValidAccount== SERVER_OK)
    {
        if (p_account->state==BLOCKED)
        {


            return BLOCKED_ACCOUNT ;

        }
        else
        {

            return SERVER_OK;

        }

    }

}


/*************************************** END OF isBlockedAccount ***********************************************/










/******************************************* isAmountAvailable **********************************************/
// calling terminal data and database
EN_serverError_t isAmountAvailable(float *termData)
{

    if(_isValidAccount==SERVER_OK && _isBlockedAccount == SERVER_OK)
    {
        if ((p_account->balance)<(*termData))
        {
            return LOW_BALANCE;
        }
        else
        {
            return SERVER_OK;
        }

    }
}



/*************************************** END OF isAmountAvailable ***********************************************/










