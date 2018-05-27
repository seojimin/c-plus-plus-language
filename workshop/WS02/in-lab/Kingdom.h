
// Name : Jimin Seo  
// Seneca email : jseo22@myseneca.ca
// Student number: 145803169

// TODO: header safeguards
// #pragma once 
#ifndef NAMESPACE_KINGDOM_H
#define NAMESPACE_KINGDOM_H

// TODO: sict namespace
namespace sict {
	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[32];
		int m_population;
	};

	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const Kingdom&k);
}

#endif



