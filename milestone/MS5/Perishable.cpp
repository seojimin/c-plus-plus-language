//Milestone - 5. Perishable
//student name: Jimin Seo
//student nummber: 145803169
//email: jseo22@myseneca.ca

#include "Perishable.h"
using namespace std;

namespace AMA
{
    
    Perishable::Perishable() : Product('P')
    {
    }
    
    fstream& Perishable::store(fstream& file, bool newLine) const
    {
        Product::store(file, false);
        file << ',' << m_date;
        
        if ( newLine )
        {
            file << '\n';
        }
        
        return file;
    }
    
    fstream& Perishable::load(fstream& file)
    {
        Product::load(file);
        file >> m_date;
        
        return file;
    }
    
    ostream& Perishable::write(ostream& os, bool linear) const
    {
        Product::write(os, linear);
        if (m_error_state.isClear() )
        {
            if ( !linear )
            {
                os << " Expiry date : ";
            }
            m_date.write(os);
        }
        os.clear();
        
        return os;
    }
    
    istream& Perishable::read(istream& is)
    {
        Product::read(is);
        if ( is.good() )
        {
            cout << " Expiry date (YYYY/MM/DD): ";
            
            Date temp;
            temp.read(is);
            int error_code = temp.errCode();
            if ( error_code == NO_ERROR )
            {
				m_error_state.clear();
                m_date = temp;
            }
            else
            {
                static const string s[5] =
                {
                    "No Error",
                    "Invalid Date Entry",
                    "Invalid Year in Date Entry",
                    "Invalid Month in Date Entry",
                    "Invalid Day in Date Entry"
                };

				m_error_state.message(s[error_code].c_str());
                is.setstate(ios::failbit);
            }
        }
        
        return is;
    }
    
    const Date& Perishable::expiry() const
    {
        return m_date;
    }
    
}
