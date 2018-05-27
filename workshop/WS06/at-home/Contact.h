// Workshop6 at_home : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#pragma once

namespace sict {

	class Contact {

	private:
		char cha_name[20];
		long long * cha_phone;
		int num_len;
		int k;

	public:
		Contact();
		Contact(const char *, const long long [], int );
		//copy contructor
		Contact(const Contact& );
		void phoneVaild(const int , const long long [], int );
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact& operator+=(long long );
		//copy assignment operator
		Contact& operator=(const Contact& );
	};
}



