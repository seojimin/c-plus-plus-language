// Workshop6 in_lab : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#pragma once

namespace sict {

	class Contact {

	private:
		char char_name[20];
		long long * phone_num;
		int num_len;
		int k;

	public:
		Contact();
		Contact(const char*, const long long [], int);
		void phoneVaild(const int, const long long [], int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}


