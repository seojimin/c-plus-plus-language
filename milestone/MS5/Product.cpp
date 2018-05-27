//Milestone - 3. Product
//student name: Jimin Seo
//student nummber: 145803169
//email: jseo22@myseneca.ca

#include "Product.h"

using namespace std;

namespace AMA
{
	//This constructor optionally receives a character that identifies the product type. The default value is ‘N’. This function 
	Product::Product(char type)
	{
		copy_p(type, "", "", "", 0, 0, 0.0, true, "");
	}

	//This constructor receives in its seven parameters values in the following order:
	Product::Product(const char* sku, const char* name, const char* unit,
		int qty,
		bool isTaxed,
		double price,
		int qtyNeeded) : p_name(nullptr)
	{
		copy_p('N', sku, unit, name, qty, qtyNeeded, price, isTaxed, "");
	}

	//This constructor receives an unmodifiable reference to a Product object and copies the object referenced to the current object. 
	Product::Product(const Product& rhs) : p_name(nullptr)
	{
		copy_p(rhs.p_type,
			rhs.p_sku,
			rhs.p_unit,
			rhs.p_name,
			rhs.p_quantity,
			rhs.p_needed,
			rhs.p_price,
			rhs.isTaxed,
			rhs.m_error_state.message());
	}

	//This operator receives an unmodifiable reference to a Product object and replaces the current object with a copy of the object referenced. 
	Product& Product::operator=(const Product& rhs)
	{
		if (this != &rhs)
		{
			copy_p(rhs.p_type, rhs.p_sku, rhs.p_unit, rhs.p_name, rhs.p_quantity, rhs.p_needed,
				rhs.p_price, rhs.isTaxed, rhs.m_error_state.message());
		}

		return *this;
	}

	//This function deallocates any memory that has been dynamically allocated.
	Product::~Product()
	{
		if (p_name)
		{
			delete[] p_name;
			p_name = nullptr;
		}
	}

	//This query receives a reference to an fstream object and an optional bool and returns a reference to the fstream object. 
	fstream& Product::store(fstream& file, bool newLine) const
	{
		file << type() << ',';
		file << sku() << ',';
		file << name() << ',';
		file << unit() << ',';
		file << (isTaxed ? 1 : 0) << ',';
		file << price() << ',';
		file << quantity() << ',';
		file << qtyNeeded();

		if (newLine)
		{
			file << '\n';
		}

		return file;
	}

	//This modifier receives a reference to an fstream object and returns a reference to that fstream object
	fstream& Product::load(fstream& file)
	{
		char buf[100];
		memset(buf, 0, 100);
		file.get(buf, 100, ',');
		file.seekg(1, ios::cur);
		strncpy(p_sku, buf, max_sku_length);

		memset(buf, 0, 100);
		file.get(buf, 100, ',');
		file.seekg(1, ios::cur);
		strncpy(p_name, buf, max_name_length);

		memset(buf, 0, 100);
		file.get(buf, 100, ',');
		file.seekg(1, ios::cur);
		strncpy(p_unit, buf, max_unit_length);

		auto c = file.get();
		if (c == '1') isTaxed = true;
		else isTaxed = false;

		file.seekg(1, ios::cur);

		file >> p_price;
		file.ignore();

		file >> p_quantity;
		file.ignore();

		file >> p_needed;
		file.ignore();

		return file;
	}

	//This query receives a reference to an ostream object and a bool and returns a reference to the ostream object. 
	ostream& Product::write(ostream& os, bool line) const
	{

		if (!m_error_state.isClear())
		{
			os << m_error_state.message();
		}
		else
		{
			if (line)
			{
				auto old_width = os.width();
				auto old_precision = os.precision();

				os << left << setw(max_sku_length) << sku() << '|';
				os << left << setw(20) << name() << '|';
				os << right << fixed << setprecision(2) << setw(7) << cost() << '|';
				os << right << setw(4) << quantity() << '|';
				os << left << setw(10) << unit() << '|';
				os << right << setw(4) << qtyNeeded() << '|';

				os.width(old_width);
				os.precision(old_precision);
			}
			else
			{
				auto old_width = os.width();
				auto old_precision = os.precision();

				os << " Sku : " << sku() << endl;
				os << " Name (no spaces) : " << name() << endl;
				os << " Price : " << fixed << setprecision(2) << price() << endl;
				os << " Price after tax : ";
				if (isTaxed) os << fixed << setprecision(2) << cost();
				else os << "N/A";
				os << endl;
				os << " Quantity on hand : " << quantity() << " " << unit() << endl;
				os << " Quantity needed : " << qtyNeeded() << endl;

				os.width(old_width);
				os.precision(old_precision);
			}
		}

		return os;
	}

	//This modifier receives a reference to an istream object and returns a reference to the istream object
	istream& Product::read(istream& is)
	{
		cout << " Sku: ";
		is >> p_sku;

		cout << " Name (no spaces): ";
		is >> p_name;

		cout << " Unit: ";
		is >> p_unit;

		char input;
		cout << " Taxed? (y/n): ";
		is >> input;
		if (input == 'y' || input == 'Y') isTaxed = true;
		else if (input == 'n' || input == 'N') isTaxed = false;
		else
		{
			is.setstate(ios::failbit);
			m_error_state.message("Only (Y)es or (N)o are acceptable");
			return is;
		}

		double price;
		cout << " Price: ";
		is >> price;

		if (!is.good())
		{
			m_error_state.message("Invalid Price Entry");
			return is;
		}

		p_price = price;

		double quantity;
		cout << " Quantity on hand: ";
		is >> quantity;

		if (!is.good())
		{
			m_error_state.message("Invalid Quantity Entry");
			return is;
		}

		p_quantity = quantity;

		double quantity_needed;
		cout << " Quantity needed: ";
		is >> quantity_needed;

		if (!is.good())
		{
			m_error_state.message("Invalid Quantity Needed Entry");
			return is;
		}

		p_needed = quantity_needed;
		m_error_state.clear();

		return is;
	}

	//This query receives the address of an unmodifiable C-style null-terminated string and returns true if the string is identical to the sku of the current object; false otherwise.
	bool Product::operator==(const char* val) const
	{
		return (strcmp(p_sku, val) == 0);
	}

	//This query that returns the total cost of all items of the product on hand, taxes included.
	double Product::total_cost() const
	{
		return cost() * quantity();
	}

	//This modifier that receives an integer holding the number of units of the Product that are on hand.
	void Product::quantity(int val)
	{
		p_quantity = val;
	}

	//This query returns true if the object is in a safe empty state; false otherwise.
	bool Product::isEmpty() const
	{
		return emptyState;
	}

	//This query that returns the number of units of the product that are needed.
	int Product::qtyNeeded() const
	{
		return p_needed;
	}

	//This query returns the number of units of the product that are on hand.
	int Product::quantity() const
	{
		return p_quantity;
	}

	//This query receives the address of a C-style null-terminated string holding a product sku and returns true if the sku of the current 
	// object is greater than the string stored at the received address (according to how the string comparison functions define ‘greater than’); false otherwise.
	bool Product::operator>(const char* sku) const
	{
		return strcmp(p_sku, sku) > 0;
	}

	//This query receives an unmodifiable reference to a Product object and returns true if the name of the current object is greater than the name
	// of the referenced Product object (according to how the string comparison functions define ‘greater than’); false otherwise.
	bool Product::operator>(const iProduct& rhs) const
	{
		return true;
	}

	//This modifier receives an integer identifying the number of units to be added to the Product and returns the updated number of units on hand. 
	int Product::operator+=(int val)
	{
		if (val > 0)
		{
			p_quantity += val;
		}

		return p_quantity;
	}
	//
	char Product::type() const
	{
		return p_type;
	}

	//This function receives the address of a C-style null-terminated string that holds the name of the product. 
	void Product::name(const char* val)
	{
		if (val != nullptr)
		{
			if (p_name)
			{
				strcpy(p_name, val);
			}
			else
			{
				p_name = new char[max_name_length + 1];
				strcpy(p_name, val);
			}
		}
		else if (val == nullptr)
		{
			if (p_name)
			{
				delete[] p_name;
				p_name = nullptr;
			}
		}
	}

	//This query returns the address of the C-style string that holds the name of the product. 
	const char* Product::name() const
	{
		return p_name;
	}

	//This query returns the address of the C-style string that holds the sku of the product. 
	const char* Product::sku() const
	{
		return p_sku;
	}

	//This query returns the address of the C-style string that holds the unit of the product. 
	const char* Product::unit() const
	{
		return p_unit;
	}

	//This query returns the taxable status of the product. 
	bool Product::taxed() const
	{
		return isTaxed;
	}

	//This query returns the price of a single item of the product. 
	double Product::price() const
	{
		return p_price;
	}

	//This query returns the price of a single item of the product plus any tax that applies to the product.
	double Product::cost() const
	{
		if (isTaxed)
		{
			return price() * (1.0 + k_curr_tax_rate / 100.0);
		}

		return price();
	}

	//This function receives the address of a C-style null-terminated string holding an error message and stores that message in the ErrorState object. 
	void Product::message(const char* msg)
	{
		m_error_state.message(msg);
	}

	//This query returns true if the ErrorState object is clear; false otherwise.
	bool Product::isClear() const
	{
		return m_error_state.isClear();
	}

	//This constructor prevent to use the same code so many times.
	void Product::copy_p(const char type,
		const char* sku,
		const char* unit,
		const char* name,
		int qty,
		int qty_needed,
		double price,
		bool isTaxed,
		const char* msg)
	{
		p_type = type;
		strcpy(p_sku, sku);
		strcpy(p_unit, unit);
		Product::name(name);
		p_quantity = qty;
		p_needed = qty_needed;
		p_price = price;
		isTaxed = isTaxed;
		m_error_state.message(msg);

		if (strlen(p_sku) && strlen(p_unit) && name && strlen(name))
		{
			emptyState = true;
		}
		else
		{
			emptyState = false;
		}
	}

	//This helper receives a reference to an ostream object and an unmodifiable reference to a Product object and returns a reference to the ostream object.
	// Your implementation of this function will insert a Product record into the ostream.
	ostream& operator<<(ostream& ostr, const iProduct& prod)
	{
		return prod.write(ostr, true);
	}

	//This helper receives a reference to an istream object and a reference to a Product object and returns a reference to the istream object. 
	// Your implementation of this function extracts the Product record from the istream.
	istream& operator>>(istream& istr, iProduct& prod)
	{
		return prod.read(istr);
	}

	//Once you have implemented all of the functions for this class, compile your Product.cpp and ErrorState.cpp files with the MyProduct.cpp and tester files provided. 
	double operator+=(double& val, const iProduct& prod)
	{
		val += prod.total_cost();
		return val;
	}

}
