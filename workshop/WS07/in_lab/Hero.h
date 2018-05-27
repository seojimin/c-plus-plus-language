// Workshop7 in_lab : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#pragma once

#include <iostream>

namespace sict
{
	// excluding null 
    const int MAX_NAME_LENGTH = 41;
    const int MAX_ROUNDS = 100;
    
    class Hero
    {
		//friend function
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	private:

		char f_name[MAX_NAME_LENGTH];
		int f_health;
		int f_Strength;

    public:

		//default constructor
        Hero();
		// constructor with 3 parameters
        Hero(const char*, int, int);
        
        void operator-=(int attack);
        bool isAlive() const;
        int attackStrength() const;
       
    };

	const Hero& operator*(const Hero& first, const Hero& second);
    
    
}
