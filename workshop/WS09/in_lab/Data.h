// Workshop9 in_lab : header file 
// Name : Jimin Seo  
// Seneca E-mail : jseo22@myseneca.ca
// Student number: 145803169
#pragma once

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// Returns the largest element in data
	//
	template <typename T>
	T min(const T* data, int n)
	{
		T largeNum = LARGEST_NUMBER;

		for (int i = 0; i < n; i++){
			if (data[i] < largeNum)
				largeNum = data[i];
		}
		return largeNum;
	}

	// Returns the smallest element in data
	//
	template <typename T>
	T max(const T* data, int n)
	{
		T smallNum = SMALLEST_NUMBER;

		for (int i = 0; i < n; i++){
			if (data[i] > smallNum)
				smallNum = data[i];
		}
		return smallNum;
	}

	// Returns the sum of n elements in data
	//    
	template <typename T>
	T sum(const T* data, int n)
	{
		T sunNum = 0;

		for (int i = 0; i < n; i++){
			sunNum += data[i];
		}
		return sunNum;
	}
   
	// average returns the average of n items in data
	//
	template <typename T>
	double average(const T* data, int n)
	{
		return sum(data, n) / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template <typename T>
	bool read(istream& input, T* data, int n)
	{
		for (int i = 0; i < n; i++)
		{
			input.seekg(1, ios::cur);

			char arr[20];

			if (i == n - 1) {
				input.get(arr, 20, '\n');
			}
			else {
				input.get(arr, 20, ',');
			}

			data[i] = atof(arr);
		}

		return true;
	}

	// Display name right-justified in a field of 20 and each data element in a field of 15
	//
	template <typename T>
	void display(const char* name, const T* data, int n)
	{
		cout << setw(20) << name;

		for (int i = 0; i < n; i++)
			cout << setw(COLUMN_WIDTH) << data[i];
			cout << endl;
	}

	bool readRow(istream& input, const char* name, int* data, int n);
	bool readRow(istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

