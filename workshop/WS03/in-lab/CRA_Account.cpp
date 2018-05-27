// OOP244-BTP200 Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 2.1
// 2018/01/23
// Chris Szalwinski

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
	// set stores a family name, given name and SIN, validating first,
	// in the current object
	//
	void CRA_Account::set(const char* fn, const char* gn, int sin_)
	{
		// assume sin is invalid, then check if valid
		if (sin_ >= min_sin && sin_ <= max_sin) {
			strncpy(m_familyName, fn, max_name_length + 1);
			m_familyName[max_name_length] = '\0';
			strncpy(m_givenName, gn, max_name_length + 1);
			m_givenName[max_name_length] = '\0';
			m_sin = sin_;
		}
		else {
			m_familyName[0] = '\0';
			m_givenName[0] = '\0';
			m_sin = 0;
		}
	}

	// set adds a year and balanace to the return records for the
	// current object
	//
	void CRA_Account::display() const
	{
		if (!isEmpty()) {
			cout << "Family Name: " << m_familyName << endl;
			cout << "Given Name : " << m_givenName << endl;
			cout << "CRA Account: " << m_sin << endl;
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	// isEmpty returns the empty status of the current object
	//
	bool CRA_Account::isEmpty() const {
		return m_sin == 0;
	}
}
