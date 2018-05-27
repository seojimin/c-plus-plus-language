//Milestone - 3. ErrorState
//student name: Jimin Seo
//student nummber: 145803169
//email: jseo22@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS

#include "ErrorState.h"

#include <iostream>
#include <cstring>

using namespace std;

namespace AMA{
    
	//This function receives the address of a C-style null terminated string that holds an error message. 
	ErrorState::ErrorState(const char* errorMessage)
	{
		if (errorMessage == nullptr)
		{
			A_message = nullptr;
		}
		else
		{
			A_message = new char[strlen(errorMessage) + 1]; 
			strcpy(A_message, errorMessage); 
		}
	}

	//This function de-allocates any memory that has been dynamically allocated by the current object.
	ErrorState::~ErrorState()
	{
		delete[] A_message;
	}

	//This function clears any message stored by the current object and initializes the object to a safe empty state.
	void ErrorState::clear()
	{
		if (A_message != nullptr)
		{
			delete[] A_message;

			A_message = nullptr;
		}
	}

	//This query reports returns true if the current object is in a safe empty state.
	bool ErrorState::isClear()const
	{
		return (A_message == nullptr);
	}

	//This function stores a copy of the C-style string pointed to by str
	void ErrorState::message(const char* str)
	{
		clear();

		if (str != nullptr) {
			A_message = new char[strlen(str) + 1];
			strcpy(A_message, str);
		}
	}

	//This query returns the address of the message stored in the current object
	const char* ErrorState::message()const
	{
		return A_message;
	}

	//This operator sends an ErrorState message 
	std::ostream& operator<<(std::ostream& os, const ErrorState& errorMSG)
	{
		if (!errorMSG.isClear())
		{
			os << errorMSG.message();
		}
		return os;
	}
}
