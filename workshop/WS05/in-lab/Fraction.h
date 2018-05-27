// Workshop5 in_lab : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#pragma once

namespace sict {

	class Fraction {
		int num;
		int denom;
		int greatest;

		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;

		Fraction operator+(const Fraction& rhs) const;

	};

}

