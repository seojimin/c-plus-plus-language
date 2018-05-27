// Workshop8 at_home : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include <iostream>
#include "Account.h"

using namespace std;

namespace sict {

	//Default constructor
	Account::Account() {
		Currentbal = 0.0;
	}

	//constructor receives either a double holding the initial account balance or nothing. 
	Account::Account(double accBal) {
		if (accBal > 0.0) {
			Currentbal = accBal;
		}
		else {Currentbal = 0.0;}
	}

	//receives an amount to be credited (added) to the account balance and returns the success of the transaction
	bool Account::credit(double creditedBal) {
		
		bool check;
		if (creditedBal > 0) {
			check = true;
			Currentbal += creditedBal;
		}
		else {
			check = false;
		}

		return check;
	}

	//receives an amount to be debited (subtracted) from the account balance and returns the success of the transaction.
	bool Account::debit(double debitedBal) {

		bool check;
		if (debitedBal > 0) {
			check = true;
			Currentbal -= debitedBal;
		}
		else {
			check = false;
		}

		return check;
	}

	//returns the current balance of the account.
	double Account::balance() const{
		return Currentbal;
	}
}