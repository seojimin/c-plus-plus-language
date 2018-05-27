// Workshop8 at_home : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include <iostream>
#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	const double interRate = 0.05;
	const double trans_fee = 0.50;
	const double month_fee = 2.00;

	//this function receives the address of a C-style string that identifies the type of account to be created and the initial balance in the account and returns its address to the calling function
	iAccount* CreateAccount(const char* account, double initialBal) {

		if (account[0] == 'S') {
			return new SavingsAccount(initialBal, interRate);
		}
		else if (account[0] == 'C')
		{
			return new ChequingAccount(initialBal, trans_fee, month_fee);
		}
		else {
			return nullptr;
		}
	}

}
