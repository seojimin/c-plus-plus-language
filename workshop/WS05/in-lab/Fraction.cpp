// Workshop5 in_lab : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include <iostream>
#include "Fraction.h"

using namespace std;

namespace sict{
	// the default constructor
	Fraction::Fraction() 
	{
		denom = 0;
	}

	//the two-argument constructor
	Fraction::Fraction(int a, int b) 
	{
		if (a >= 0 && b > 0) 
		{
			num = a;
			denom = b;
			greatest = gcd();
			reduce();
		}
		else 
		{
			denom = 0;
		}

	}

	//the max query
	int Fraction::max() const
	{
		int max = 0;

		if (num >= denom)
		{
			max	= num;
		}
		else 
		{
			max = denom;
		}

		return max;
	}

    //the min query
	int Fraction::min() const 
	{
		int min = 0;

		if (num > denom)
		{
			min = denom;
		}
		else 
		{
			min = num;
		}

		return min;
	}

	// gcd returns the greatest common divisor of num and denom
    int Fraction::gcd() const 
	{
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) 
		{
            if (mx % x == 0 && mn % x == 0) 
			{
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    //the reduce modifier
	void Fraction::reduce() 
	{
		num /= greatest;
		denom /= greatest;
	}

    //the display query
	void Fraction::display() const 
	{

		if (isEmpty()) 
		{
			cout << "no fraction stored";
		}
		else if (denom == 1)
		{
			cout << num;
		}
		else 
		{
			cout << num << "/" << denom;
		}
	}

    // returns true if the object is in a safe empty state
	bool Fraction::isEmpty() const 
	{
		return (denom == 0);
	}

    // represents the right operand of an addition expression
	Fraction Fraction:: operator+(const Fraction& rhs) const {

		int num1;
		int denom2;

		if (isEmpty() || rhs.isEmpty()) 
		{
			return Fraction();
		}
		else 
		{
			num1 = (num * rhs.denom) + (denom * rhs.num);
			denom2 = denom * rhs.denom;

			return Fraction(num1, denom2);
		}
	}
}