// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include <iostream>
#include "CRA_Account.h"
#include <cstring>
#include <cmath> // cmath and abs effectively cast x to a double before calculations.
using namespace std;

namespace sict
{
	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		if ((sin >= min_sin && sin <= max_sin) && (strlen(familyName) != 0) && (strlen(givenName) != 0)){

			int nine_digit = 100000000;
			int i, j, rest;
			int quotient[val_num];
			int odd_sum = 0;
			int even_sum = 0;
			int odd_qu = 0;
			int odd_rest = 0;
			int total = 0;

			for(i = 0; i < val_num; i++)
			{
				if(i == 0) 
				{
					quotient[i] = sin / nine_digit;
				}
				else
				{
					quotient[i] = rest / nine_digit;
				}
				rest = sin % min_sin;
				nine_digit = nine_digit * 0.1;
			}

			for(j = 0; j < val_num - 1; j++) 
			{
				if (j % 2 == 0) 
				{
					even_sum += quotient[j];
				}
				else
				{
					odd_qu = (quotient[j] * 2) / 10;
					odd_rest = (quotient[j] * 2) % 10;
					odd_sum += odd_qu + odd_rest;
				}
			}

			total += even_sum + odd_sum;

			if(!!((total + quotient[val_num - 1]) % 10 == 0)) 
			{
				strncpy(fName, familyName, sizeof(fName));
				strncpy(gName, givenName, sizeof(gName));
				Sin = sin;
				numArr = 0;
			}
			else
			{
				Sin = 0;
			}
		}
		else
		{
			Sin = 0;
		}
	}
	
	bool CRA_Account::isEmpty() const
	{
		bool check = true; 
		if (((Sin) != 0) && (min_sin <= Sin) && (Sin <= max_sin))
		{
			check = false;
		}
		else
		{
			check = true; 
		}
		return check; 
	}
	
	void CRA_Account::display() const
	{
		int k;
		
		if (Sin != 0)
		{
			cout << "Family Name: " << fName << endl;
			cout << "Given Name : " << gName << endl;
			cout << "CRA Account: " << Sin << endl;

			cout.setf(ios::fixed);
			cout.precision(2);
			for (k = 0; k < numArr; k++)
			{
				if (m_balance[k] > 2)
				{
					cout << "Year (" << m_year[k] << ") balance owing: " << m_balance[k] << endl;
				}
				else if (m_balance[k] < -2)
				{
					cout << "Year (" << m_year[k] << ") refund due: " << abs(m_balance[k]) << endl;
				}
				else
				{
					cout << "Year (" << m_year[k] << ") No balance owing or refund due!" << endl;
				}
			}
		}
		else 
		{
			cout << "Account object is empty!" << endl;
		}
	}

	void CRA_Account::set(int year, double balance) {

		if (Sin != 0 && numArr < 4)
		{
			m_year[numArr] = year;
			m_balance[numArr] = balance;
			numArr++;
		}
	}

}
