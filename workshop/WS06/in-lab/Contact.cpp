// Workshop6 in_lab : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"

using namespace std;

namespace sict {

	// Default constructor
	Contact::Contact() {
		char_name[0] = '\0';
		phone_num = nullptr;
	}

	// constructor with 3 parameters
	Contact::Contact(const char *name, const long long phone[], int num) {

		if (name == nullptr) {
			char_name[0] = '\0';
			phone_num = nullptr;
		}
		else {
			strncpy(char_name, name, 19);
			char_name[19] = '\0';

			phoneVaild(1, phone, num);
			phone_num = new long long[num_len];
			phoneVaild(2, phone, num);
		}
	}

	// check the phone num is valid
	void Contact::phoneVaild(const int gu, const long long phone[], int num) {

		num_len = 0;
		k = 0;

		for (int i = 0; i < num; i++) {

			long long country = phone[i] / 10000000000LL;
			long long country_rest = phone[i] % 10000000000LL;
			long long area = country_rest / 1000000000LL;
			long long tel_no = country_rest % 10000000LL;

			if ((country > 0) && (country < 100) && (area > 0) && (tel_no >= 1000000)) {

				num_len++;

				if (gu == 2) {
					phone_num[k] = phone[i];
					k++;
				}
			}
		}
	}

	// destructor
	Contact::~Contact() {
		delete[] phone_num;
		phone_num = nullptr;
	}

	// a query that returns false if the current object has valid data; true if the object is in a safe empty state
	bool Contact::isEmpty() const {
		return (char_name[0] == '\0');
	}

	// a query that prints the data stored by the object
	void Contact::display() const {

		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << char_name << endl;

			for (int i = 0; i < num_len; i++) {

				long long country = phone_num[i] / 10000000000LL;
				long long int area = (phone_num[i] % 10000000000LL) / 10000000LL;
				long long int tel1 = ((phone_num[i] % 10000000000LL) % 10000000LL) / 10000LL;
				long long int tel2 = ((phone_num[i] % 10000000000LL) % 10000000LL) % 10000LL;

				cout.fill('0');
				cout << "(+" << country << ") " << area << " " << tel1 << "-" << setw(4) << std::right << tel2 << endl;

			}

		}


	}


}


