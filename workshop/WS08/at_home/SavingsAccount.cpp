// Workshop8 at_home : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	// Default constructor
	SavingsAccount::SavingsAccount() {
		interRate = 0.0;
	}

	//constructor receives a double holding the ***initial account balance*** and a double holding the interest rate to be applied to the balance
	SavingsAccount::SavingsAccount(double accBal, double inter) : Account(accBal) {
		if (inter > 0) {
			interRate = inter;
		}
		else {
			interRate = 0.0;
		}
	}

	//this modifier calculates the interest earned on the current balance and credits the account with that interest.
	void SavingsAccount::monthEnd() {

		Currentbal += (Currentbal * interRate);

	}

	//receives a reference to an ostream object and inserts the following output on separate lines to the object
	void SavingsAccount::display(ostream& ostr) const {
		if ((balance() >= 1.0) && (interRate >= 0.0))
		{
			ostr << "Account type: Savings" << endl;
			ostr.setf(ios::fixed);
			ostr.precision(2);
			ostr << "Balance: $" << balance() << endl;
			ostr.setf(ios::fixed);
			ostr.precision(2);
			ostr << "Interest Rate (%): " << interRate * 100.0 << endl;
			ostr.unsetf(ios::fixed);
		}
	}
}