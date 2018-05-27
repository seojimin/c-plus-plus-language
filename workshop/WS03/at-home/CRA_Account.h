// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169
// This header file(CRA_Account.h) shows that display();, isEmpty and two different set(); functions to check valid sin and name. 

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict
{
	const int max_name_length = 40; 
	const int min_sin = 100000000;  
	const int max_sin = 999999999;  
	const int max_yrs = 4;
	const int val_num = 9;

	class CRA_Account
	{
	private:
		char  fName[max_name_length];
		char  gName[max_name_length];
		int Sin;
		int m_year[max_yrs];
		double m_balance[max_yrs];
		int numArr;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
	};
}

#endif