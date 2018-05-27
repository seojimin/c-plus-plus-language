// Workshop8 in_lab : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account : public iAccount {

	protected:
		double Currentbal;

		//returns the current balance of the account.
		double balance() const;

	public:

		//default constructor
		Account();
		//constructor receives either a double holding the initial account balance or nothing. 
		Account(double);

		//receives an amount to be credited (added) to the account balance and returns the success of the transaction
		bool credit(double);

		//receives an amount to be debited (subtracted) from the account balance and returns the success of the transaction.
		bool debit(double);
	};


}
#endif
