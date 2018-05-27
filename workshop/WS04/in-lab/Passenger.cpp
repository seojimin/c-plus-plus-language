// Workshop4 in_lab : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169
// This cpp file(Passenger.cpp) demostrates that how to declare default constructor and constructor with two parameters.

#include <iostream>
#include "Passenger.h"
#include <cstring>

using namespace std;

namespace sict
{
	//the default constructor
	Passenger::Passenger()
	{
		pName[0] = '\0';
		desti[0] = '\0';
	}

	//constructor with 2 parameters
	Passenger::Passenger(const char *p1Name, const char *desti1)
	{
		if ((p1Name != nullptr) && (desti1 != nullptr))
		{
			for (int i = 0; i < length && p1Name[i] != '\0'; i++)
			{
				pName[i] = p1Name[i];
			}
			
			//pName[strlen(p1Name)] = '\0';
			strncpy(pName, p1Name, sizeof(pName) - 1);

			for (int i = 0; i < length && desti1[i] != '\0'; i++)
			{
				desti[i] = desti1[i];
			}

			//desti[strlen(desti1)] = '\0';
			strncpy(desti, desti1, sizeof(desti) - 1);

		}
		else
		{
			*this = Passenger();
		}
	}
	// if the data is nullptr or empty, it returns true 
	bool Passenger::isEmpty() const
	{
		if ((pName[0] != '\0') && (desti[0] != '\0'))
		{
			return false;
		}
		else
			return true;
	}

	void Passenger::display() const
	{
		if (isEmpty())
		{
			cout << "No passenger!" << endl;
		}
		else
		{
			cout << pName << " - " << desti << endl;
		}
	}
}
   

