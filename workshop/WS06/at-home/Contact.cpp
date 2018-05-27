// Workshop6 at_home : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"

using namespace std;

namespace sict {

	//default constructor 
	Contact::Contact() {

		cha_name[0] = '\0';
		cha_phone = nullptr;
		num_len = 0;
		k = 0;
	}

	//Copy contructor
	Contact::Contact(const Contact& copy) {

		strcpy(cha_name, copy.cha_name);
		num_len = copy.num_len;
		k = copy.k;

		if (num_len > 0) {
			cha_phone = new long long[num_len];
			for (int i = 0; i < num_len; i++) {
				cha_phone[i] = copy.cha_phone[i];
			}

		}
		else {
			cha_phone = nullptr;
		}

	}

	//constructor with 3 parameters
	Contact::Contact(const char *name, const long long phone[], int num) {

		if (name == nullptr) {

			cha_name[0] = '\0';
			cha_phone = nullptr;
		}
		else {

			num_len = 0;
			k = 0;

			strncpy(cha_name, name, 19);
			cha_name[19] = '\0';


			if (phone == nullptr) {
				cha_phone = nullptr;
			}
			else {
				cha_phone = new long long[num_len];
				phoneVaild(2, phone, num);
			}
		}

	}

	// check the phone number valid
	void Contact::phoneVaild(const int valid_, const long long phone[], int num) {

		for (int i = 0; i < num; i++) {

			long long country = phone[i] / 10000000000LL;
			long long country_rest = phone[i] % 10000000000LL;
			long long area = country_rest / 1000000000LL;
			long long tel = country_rest % 10000000LL;

			if ((country > 0) && (country < 100) && (area > 0) && (tel >= 1000000)) {
				num_len++;
				if (valid_ == 2) {
					cha_phone[k] = phone[i];
					k++;
				}
			}
		}
	}

	//destructor
	Contact::~Contact() {

		delete[] cha_phone;
		cha_phone = nullptr;
	}

	//a query that returns false if the current object has valid data; true if the object is in a safe empty state
	bool Contact::isEmpty() const {

		return (cha_name[0] == '\0');
	}

	//a query that prints the data stored by the object 
	void Contact::display() const {

		if (isEmpty()) {

			cout << "Empty contact!" << endl;
		}
		else {

			cout << cha_name << endl;

			for (int i = 0; i < num_len; i++) {

				long long country = cha_phone[i] / 10000000000LL;
				long long int area = (cha_phone[i] % 10000000000LL) / 10000000LL;
				long long int tel1 = ((cha_phone[i] % 10000000000LL) % 10000000LL) / 10000LL;
				long long int tel2 = ((cha_phone[i] % 10000000000LL) % 10000000LL) % 10000LL;


				cout.fill('0');
				cout << "(+" << country << ") " << area << " " << tel1 << "-" << setw(4) << std::right << tel2 << endl;

			}

		}

	}

	// the += operator
	Contact& Contact::operator+=(long long okay) {

		long long country = okay / 10000000000LL;
		long long country_rest = okay % 10000000000LL;
		long long area = country_rest / 1000000000LL;
		long long tel = country_rest % 10000000LL;


		long long *Copy_C_phone;

		if ((country > 0) && (country < 100) && (area > 0) && (tel >= 1000000)) {

			Copy_C_phone = new long long[num_len + 1];

			for (int i = 0; i <num_len; i++) {

				Copy_C_phone[i] = cha_phone[i];

			}
			Copy_C_phone[num_len] = okay;
			delete[] cha_phone;

			cha_phone = Copy_C_phone;
			num_len++;

		}


		return *this;
	}


	//the copy assignment operator
	Contact& Contact::operator=(const Contact& con) {

		if (this != &con) {
			strcpy(cha_name, con.cha_name);
			num_len = con.num_len;
			k = con.k;

			if (num_len > 0) {
				cha_phone = new long long[num_len];
				for (int i = 0; i < num_len; i++) {
					cha_phone[i] = con.cha_phone[i];
				}

			}
			else {
				cha_phone = nullptr;
			}
		}
		return *this;
	}

}

