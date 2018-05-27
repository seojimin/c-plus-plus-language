// Workshop8 in_lab : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {

	class SavingsAccount : public Account{

	private:
		double interRate;

	public:
			// default constructor
			SavingsAccount();
			//constructor receives a double holding the initial account balance and a double holding the interest rate to be applied to the balance
			SavingsAccount(double, double);

			//this modifier calculates the interest earned on the current balance and credits the account with that interest
			void monthEnd();

			//receives a reference to an ostream object and inserts the following output on separate lines to the object
			void display(std::ostream& ostr) const;
	};
}
#endif
