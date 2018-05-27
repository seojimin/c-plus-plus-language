// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////
// Workshop8 at_home : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include "ChequingAccount.h"

using namespace std;

namespace sict {

	ChequingAccount::ChequingAccount(double initialBal, double transFee, double monthEndFee) : Account(initialBal){
		
		if (transFee > 0)
		{
			trans_fee = transFee;
		}
		else {
			trans_fee = 0.0;
		}

		if (monthEndFee > 0) 
		{
			month_fee = monthEndFee;
		}
		else {
			month_fee = 0.0;
		}
	}

	//this modifier credits the balance by the amount received and if successful debits the transaction fee from the balance
	bool ChequingAccount::credit(double creditedBal) {

		bool check;
		if (Account::credit(creditedBal)) {
			check = true;
			Currentbal -= trans_fee;
		}
		else {
			check = false;
		}

		return check;
	}

	//this modifier debits the balance by the amount received and if successful debits the transaction fee from the balance.
	bool ChequingAccount::debit(double debitedBal) {

		bool check;
		if (Account::debit(debitedBal)) {
			check = true;
			Currentbal -= trans_fee;
		}
		else {
			check = false;
		}

		return check;
	}

	//this modifier debits the monthly fee from the balance.
	void ChequingAccount::monthEnd() {
		debit(month_fee);
	}

	// receives a reference to an ostream object and inserts the following output on separate lines to the object
	void ChequingAccount::display(std::ostream& ostr) const{
		ostr << "Account type: Chequing" << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Balance: $" << balance() << endl;
		ostr << "Per Transaction Fee: " << trans_fee << endl;
		ostr << "Monthly Fee: " << month_fee << endl;
		ostr.unsetf(ios::fixed);
	}
}
