// Workshop8 at_home : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account{

		private:
			double trans_fee;
			double month_fee;

		public:
			
			//constructor receives a double holding the initial account balance, a double holding the transaction fee to be applied to the balance and a double holding the month-end fee to be applied to the account. 
			ChequingAccount(double, double, double);

			//this modifier credits the balance by the amount received and if successful debits the transaction fee from the balance
			bool credit(double);

			//this modifier debits the balance by the amount received and if successful debits the transaction fee from the balance.
			bool debit(double);

			//this modifier debits the monthly fee from the balance.
			void monthEnd();

			// receives a reference to an ostream object and inserts the following output on separate lines to the object
			void display(std::ostream& ostr) const;

	};
}
#endif
