// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: iAccount.h
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file defines the iAccount interface
///////////////////////////////////////////////////

// Workshop8 at_home : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__
#define interface SICT_IACCOUNT_H__

#include <iostream>

namespace sict {

	class iAccount {

	public:
		// adds a positive amount to the account balance 
		virtual bool credit(double) = 0;

		// subtracts a positive amount from the account balance 
		virtual bool debit(double) = 0;

		// applies month-end transactions to the account
		virtual void monthEnd() = 0;

		//inserts account information into an ostream object
		virtual void display(std::ostream&) const = 0;
	};

	// receives a C-style string identifying the type of account and the initial account balance, creates the account with the starting balance and returns its address.
	iAccount* CreateAccount(const char*, double);
}
#endif

