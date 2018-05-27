// Workshop7 at-home : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include <iostream>
#include <cstring>
#include "SuperHero.h"

using namespace std;

namespace sict
{
	//default constuctor with Hero() 
	SuperHero::SuperHero() : Hero()
	{
		f_bonus = 0;
		f_defend = 0;
	}

	//If the information received is valid, the object accepts them. Otherwise, the object assumes a safe empty state
	SuperHero::SuperHero(const char* name, int health, int attackStrength,int bonus, int defend) :
		Hero(name, health, attackStrength)
	{
		f_bonus = bonus;
		f_defend = defend;
	}

	//a query that returns the attack strength of the current object includ-ing its super power bonus. If the object is in a safe empty state, this function returns 0.
	int SuperHero::attackStrength() const
	{
		if (strlen(f_name) == 0 && f_health == 0 && f_Strength == 0)

			return 0;

		return Hero::attackStrength() + f_bonus;
	}

	//a query that returns the defend strength of the current object. If the object is in a safe empty state, this function returns 0
	int SuperHero::defend() const
	{
		if (strlen(f_name) == 0 && f_health == 0 && f_Strength == 0)

			return 0;

		return f_defend;
	}

	//a non-friend that returns an unmodifiable reference to the winner of the battle between the SuperHeroes after max_rounds rounds. 
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{
		SuperHero first_1 = first;
		SuperHero second_2 = second;
		bool Winner = true;
		int round = 0;

		for (int i = 1; i <= MAX_ROUNDS; ++i)
		{
			second_2 -= (first_1.attackStrength() - second_2.defend());
			if (!second_2.isAlive())
			{
				Winner = true;
				round = i;
				break;
			}

			first_1 -= (second_2.attackStrength() - first_1.defend());
			if (!first_1.isAlive())
			{
				Winner = false;
				round = i;
				break;
			}
		}

		cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
		if (Winner) cout << first;
		else cout << second;

		cout << " in " << round << " rounds." << endl;

		return Winner ? first : second;
	}

}
