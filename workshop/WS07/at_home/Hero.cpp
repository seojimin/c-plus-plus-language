// Workshop7 at-home : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include <iostream>
#include <cstring>
#include "Hero.h"
using namespace std;

namespace sict
{
	//default constructor
    Hero::Hero()
    {
		f_name[0] = 0;
		f_health = 0;
		f_Strength = 0;
    }
    
	//If the information received is valid, the object accepts them. Otherwise, the object assumes a safe empty state
    Hero::Hero(const char* name, int health, int attackStrength)
    {
        if ( name && strlen(name) > 0 && health >= 0 && attackStrength >= 0 )
        {
            strncpy(f_name, name, MAX_NAME_LENGTH);
            f_name[MAX_NAME_LENGTH-1] = 0;
            f_health = health;
            f_Strength = attackStrength;
        }
        else
        {
			*this = Hero();
        }
    }
    
	//an overloaded operator that receives an attack strength and, if that strength is positive-valued, deducts that strength from the current object’s health.
    void Hero::operator-=(int attack)
    {
        if ( attack > 0 )
        {
            f_health -= attack;
           
			if (f_health < 0)
			{
				f_health = 0;
			}
        }
    }
    
	//a query that returns true if the current object is healthy and false otherwise
    bool Hero::isAlive() const
    {
        return f_health > 0;
    }
    
	//a query that returns the attack strength of the current object. If the object is in a safe empty state, this function returns 0.
    int Hero::attackStrength() const
    {
        if (strlen(f_name) == 0 && f_health == 0 && f_Strength == 0)
			
			return 0;
        
        return f_Strength;
    }
    
    //a friend that inserts the name of hero into stream os and returns a reference to that stream
    ostream& operator<<(ostream& os, const Hero& hero)
    {
        if ((strlen(hero.f_name) == 0 && hero.f_health <= 0 && hero.f_Strength <= 0))
			os << "No hero";
        else 
			os << hero.f_name;
        return os;
    }
    
	//a non-friend that returns an unmodifiable reference to the winner of the battle between the Heroes after max_rounds rounds
    const Hero& operator*(const Hero& first, const Hero& second)
    {
        Hero first_1 = first;
        Hero second_2 = second;
        bool Winner = true;
        int round = 0;
        
        for(int i = 1 ; i <= MAX_ROUNDS ; ++ i)
        {
			second_2 -= first_1.attackStrength();
            if ( !second_2.isAlive() )
            {
                Winner = true;
                round = i;
                break;
            }
            
			first_1 -= second_2.attackStrength();
            if ( !first_1.isAlive() )
            {
                Winner = false;
                round = i;
                break;
            }
        }
        
        cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";
        if ( Winner ) 
			cout << first;

        else 
			cout << second;

        cout << " in " << round << " rounds." << endl;
        
        return Winner ? first : second;
    }
    
}
