// Workshop9 in_lab : cpp file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169

#include "Data.h"
#include <cstring>
#include <iomanip>
using namespace std;

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//
	bool readRow(istream& input, const char* name, double* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (strcmp(rowname, name) != 0) {
				// wrong row
				cout << "Cannot parse row for " << name << endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	bool readRow(istream& input, const char* name, int* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (strcmp(rowname, name) != 0) {
				// wrong row
				cout << "Cannot parse row for " << name << endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		auto old_precision = cout.precision();
		cout.precision(2);
		cout.setf(ios::fixed);
		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"

		cout << "Population change from 2000 to 2004 is " << (population[n - 1] - population[0]) / 1000000.0 << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		bool upOrDown = true;

			if (violentCrime[0] > violentCrime[n - 1]) {
				upOrDown = false;
			};

		cout << "Violent Crime trend is " << (upOrDown == true ? "up" : "down") << endl;

		// Q3 print the GTA number accurate to 0 decimal places
		cout << "There are " << average(grandTheftAuto, n) / 1000000 << " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << (int)min(violentCrimeRate, n) << endl;
		cout << "The Maximum Violent Crime rate was " << (int)max(violentCrimeRate, n) << endl;

		cout.unsetf(ios::fixed);
		cout.precision(old_precision);

	}
}