//Milestone - 2. ErrorState
//student name: Jimin Seo
//student nummber: 145803169
//email: jseo22@myseneca.ca

#pragma once

#include <iostream>
#include <cstring>

namespace AMA {

	class ErrorState {

	private:

		//A pointer that holds the address of the message, if any, stored in the current object.
		char* A_message;

	public:

		//This function receives the address of a C-style null terminated string that holds an error message. 
		explicit ErrorState(const char* errorMessage = nullptr);

		//A deleted copy constructor prevents copying of any ErrorState object.
		ErrorState(const ErrorState& em) = delete;

		//A deleted assignment operator prevents assignment of any ErrorState object to the current object. 
		ErrorState& operator=(const ErrorState& em) = delete;

		//This function de-allocates any memory that has been dynamically allocated by the current object.
		virtual ~ErrorState();

		//This function clears any message stored by the current object and initializes the object to a safe empty state.
		void clear();

		//This query reports returns true if the current object is in a safe empty state.
		bool isClear()const;

		//This function stores a copy of the C-style string pointed to by str
		void message(const char* str);

		//This query returns the address of the message stored in the current object
		const char* message()const;
	};

	//This operator sends an ErrorState message 
	std::ostream& operator<<(std::ostream& os, const ErrorState& errorMSG);
}

