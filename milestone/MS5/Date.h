// Final Project Milestone 1
//
// Version 1.0
// Date 2018 MAR 16
// Author Jimin Seo
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

//define value
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;

  class Date {

  private:
	  int m_year;
	  int m_month;
	  int m_day;
	  long comValue;
	  int m_error_state;

	  int mdays(int, int)const;
	  void errCode(int errorCode);
 
  public:

	  //default constructor
	  Date();
	  //Three argument constructor
	  Date(int, int, int);

	  //Operators
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;

	  int errCode() const;
	  bool bad() const;

	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;
  };

  std::ostream& operator << (std::ostream& ostr, const Date& );
  std::istream& operator >> (std::istream& istr, Date& );

}
#endif