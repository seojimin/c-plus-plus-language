// Workshop7 at-home : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#pragma once

#include "Hero.h"

namespace sict
{
    class SuperHero : public Hero
    {
		
	private:

		int f_bonus;
		int f_defend;

    public:

		//default constructor
		SuperHero();
		// constructor with 3 parameters
		SuperHero(const char*, int , int , int , int );
        
		int attackStrength() const;
		int defend() const;
       
    };

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);

}



	
	

	