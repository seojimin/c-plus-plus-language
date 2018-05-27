//Milestone - 5. Perishable
//student name: Jimin Seo
//student nummber: 145803169
//email: jseo22@myseneca.ca


#pragma once

#include "Product.h"
#include "Date.h"

namespace AMA
{
    
    class Perishable : public Product
    {
    
    public:
        
        Perishable();
        
        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        
        const Date& expiry() const;
        
    private:
        
        Date m_date;
        std::string m_error_table[5];
        
    };
    
}
