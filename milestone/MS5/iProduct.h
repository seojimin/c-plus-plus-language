//Milestone - 4. iProduct.h.
//student name: Jimin Seo
//student number: 145803169
//email: jseo22@myseneca.ca


#pragma once

#include <iostream>
#include <fstream>

namespace AMA
{
    
    class iProduct
    {  
    public:
       
        virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
        virtual std::fstream& load(std::fstream& file) = 0;
        virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
       
        virtual double total_cost() const = 0;
        virtual const char* name() const = 0;
        virtual void quantity(int) = 0;
        virtual int qtyNeeded() const = 0;
        virtual int quantity() const = 0;

		virtual bool operator==(const char*) const = 0;
        virtual int operator+=(int) = 0;
        virtual bool operator>(const iProduct&) const = 0;

    };
    
    std::ostream& operator<<(std::ostream& ostr, const iProduct& );
    std::istream& operator>>(std::istream& istr, iProduct& );

    double operator+=(double&, const iProduct&);
    
    iProduct* CreateProduct();
    iProduct* CreatePerishable();
    
}
