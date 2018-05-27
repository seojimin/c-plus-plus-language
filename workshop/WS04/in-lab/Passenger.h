// Workshop4 in_lab : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169
// This header file(Passenger.h)  contains definitions default constructor and constructor with 2 parameters

#pragma once

namespace sict
{
	const int length = 32;

	class Passenger
	{
	private:
		char pName[length];
		char desti[length];

	public:
		Passenger();
		Passenger(const char*p1Name, const char*desti1);
		bool isEmpty() const;
		void display() const;

	};
}


