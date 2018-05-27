// Workshop4 at_home : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#pragma once

namespace sict
{
	const int length = 32;

	class Passenger
	{
	private:
		char pName[length];
		char desti[length];
		int year;
		int month;
		int day;

	public:
		Passenger();
		Passenger(const char*, const char*);
		Passenger(const char*, const char*,int ,int ,int);
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
		void display() const;

	};
}


