// Workshop4 at_home : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Passenger.h"

using namespace std;

namespace sict
{
	// the default constructor
	Passenger::Passenger()
	{
		pName[0] = '\0';
		desti[0] = '\0';
		month = 0;
		year = 0;
		day = 0;
	}

	// constructor with 2 parameters
	Passenger::Passenger(const char *p1Name, const char *desti1)
	{
		if ((p1Name != nullptr) && (desti1 != nullptr))
		{
			for (int i = 0; i < length && p1Name[i] != '\0'; i++)
			{
				pName[i] = p1Name[i];
			}
			// char * strncpy(char * destination, const char * source, size_t num);
			strncpy(pName, p1Name, sizeof(pName) - 1);

			for (int i = 0; i < length && desti1[i] != '\0'; i++)
			{
				desti[i] = desti1[i];
			}

			//desti[strlen(desti1)] = '\0';
			strncpy(desti, desti1, sizeof(desti) - 1);

			*this = Passenger(p1Name, desti1, 2017, 7, 1);
		}
		else
		{
			*this = Passenger();
		}
	}

	// constructor with 5 parameters
	Passenger::Passenger(const char *p1Name, const char *desti1, int years, int months, int days)
	{
		if ((p1Name != nullptr) && (desti1 != nullptr) && (strlen(p1Name) != 0) && (strlen(desti1) != 0) &&
			(years <= 2020) && (years >= 2017) && (months >= 1) && (months <=12) && (days >=1) && (days <=31))
		{
			for(int i = 0; i < length && p1Name[i] != '\0'; i++)
			{
				pName[i] = p1Name[i];
			}
			strncpy(pName, p1Name, sizeof(pName) - 1);

			for(int i = 0; i < length && desti1[i] != '\0'; i++)
			{
				desti[i] = desti1[i];
			}
			strncpy(desti, desti1, sizeof(desti) - 1);

			year = years;
			month = months;
			day = days;
		}
		else
		{
			*this = Passenger();
		}
	}

	// returns the address of the name of the passenger or empty string.
	const char* Passenger::name() const
	{
		if (isEmpty())
			return "";
		else 
			return &pName[0];
	}

	// checks if the passenger referenced can travel with the current Passenger 
	bool Passenger::canTravelWith(const Passenger& compare) const
	{
		return year == compare.year && month == compare.month && day == compare.day;
	}

	// this isEmpty function ask whether the value is empty or not.
	bool Passenger::isEmpty() const
	{
		return (pName[0] == 0) && (desti[0] == 0);
	}

	// display the data 
	void Passenger::display() const
	{	
		cout << pName << " - " << desti << " on " << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << endl;
	}
}
   

