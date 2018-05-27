//Milestone - 3. Product
//student name: Jimin Seo
//student nummber: 145803169
//email: jseo22@myseneca.ca

#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>

#include "ErrorState.h"
#include "iProduct.h"

namespace AMA
{

	const int max_sku_length = 7;
	const int max_name_length = 10;
	const int max_unit_length = 75;
	const int k_curr_tax_rate = 13;

	class Product : public iProduct
	{
	private:

		void copy_p(const char type,
			const char* sku,
			const char* unit,
			const char* name,
			int qty,
			int qty_needed,
			double price,
			bool isTaxed,
			const char* msg);

	public:

		explicit Product(char type = 'N');
		Product(const char* sku, const char* name, const char* unit,
			int qty = 0,
			bool isTaxed = true,
			double price = 0.0,
			int qtyNeeded = 0);

		Product(const Product& rhs);
		Product& operator=(const Product& rhs);

		virtual ~Product();

		virtual std::fstream& store(std::fstream& file, bool newLine = true) const;
		virtual std::fstream& load(std::fstream& file);
		virtual std::ostream& write(std::ostream& os, bool linear) const;
		virtual std::istream& read(std::istream& is);

		bool operator==(const char* val) const;
		double total_cost() const;
		void quantity(int val);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;

		bool operator>(const char* sku) const;
		bool operator>(const iProduct& rhs) const;
		int operator+=(int val);

	protected:

		char type() const;
		void name(const char* val);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char* str);
		bool isClear() const;

		bool emptyState;

		char p_type;
		char p_sku[max_sku_length + 1];
		char p_unit[max_unit_length + 1];
		char* p_name;
		int p_quantity;
		int p_needed;
		double p_price;
		bool isTaxed;

		ErrorState m_error_state;

	};

	std::ostream& operator<<(std::ostream& os, const iProduct& prod);
	std::istream& operator>>(std::istream& is, iProduct& prod);
	double operator+=(double& val, const iProduct& prod);

}
