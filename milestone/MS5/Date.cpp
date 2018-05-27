// Final Project Milestone 1
//
// Version 1.0
// Date 2018 March 16
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
#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

namespace AMA {

	// number of days in month mon_ and year year_
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	//This function sets the error state variable to one of the values listed above
	void Date::errCode(int errorCode) {
		m_error_state = errorCode;
	}

	//default constructor
	Date::Date() {
		m_year = 0;
		m_month = 0;
		m_day = 0;
		comValue = 0;
		m_error_state = NO_ERROR;
	}

	//Three argument constructor
	Date::Date(int year, int month, int day) {
		if (year < min_year || year > max_year) {
			m_year = 0;
			m_month = 0;
			m_day = 0;
			comValue = 0;
			errCode(YEAR_ERROR);
		}
		else if (month < 1 || month > 12) {
			m_year = 0;
			m_month = 0;
			m_day = 0;
			comValue = 0;
			errCode(MON_ERROR);
		}
		else if (mdays(month, year) < day || day < 1) {
			m_year = 0;
			m_month = 0;
			m_day = 0;
			comValue = 0;
			errCode(DAY_ERROR);
		}
		else {
			m_year = year;
			m_month = month;
			m_day = day;
			comValue = year * 372 + month * 13 + day;
			errCode(NO_ERROR);
		}

	}
 
  //This query returns the error state as an error code value
	int Date::errCode() const {
		return m_error_state;
	}

  //This query returns true if the error state is not NO_ERROR. 
	bool Date::bad() const {
		return errCode() != NO_ERROR;
	}

  //comparing object
  bool Date::operator==(const Date& rhs)const {
	  if (bad() || rhs.bad() || comValue == 0 || rhs.comValue == 0) {

		  return false;
	  }
	  else 
	  {
		  return comValue == rhs.comValue;
	  }
  }

  //comparing object
  bool Date::operator!=(const Date& rhs)const {
	  if (bad() || rhs.bad() || comValue == 0 || rhs.comValue == 0) {

		  return false;
	  }
	  else 
	  {
		  return comValue != rhs.comValue;
	  }

  }

  //comparing object
  bool Date::operator<(const Date& rhs)const {
	  if (bad() || rhs.bad() || comValue == 0 || rhs.comValue == 0) {

		  return false;
	  }
	  else 
	  {
		  return comValue < rhs.comValue;
	  }
  }

  //comparing object
  bool Date::operator>(const Date& rhs)const {
	  if (bad() || rhs.bad() || comValue == 0 || rhs.comValue == 0) {

		  return false;
	  }
	  else
	  {
		  return comValue > rhs.comValue;
	  }

  }

  //comparing object
  bool Date::operator<=(const Date& rhs)const {
	  if (bad() || rhs.bad() || comValue == 0 || rhs.comValue == 0) {

		  return false;
	  }
	  else 
	  {
		  return comValue <= rhs.comValue;
	  }

  }

  //comparing object
  bool Date::operator>=(const Date& rhs)const {
	  if (bad() || rhs.bad() || comValue == 0 || rhs.comValue == 0) {

		  return false;
	  }
	  else
	  {
		  return comValue >= rhs.comValue;
	  }

  }

  // This function reads the date from the console in the following format: YYYY?MM?DD 
  istream& Date::read(istream& istr) {
	  istr >> m_year;
	  istr.ignore();

	  istr >> m_month;
	  istr.ignore();

	  istr >> m_day;

	  if (!(istr.fail())) { // .good()
		  if (m_year < min_year || m_year > max_year) 
		  {
			  m_year = 0;
			  m_month = 0;
			  m_day = 0;
			  comValue = 0;
			  errCode(YEAR_ERROR);
		  }
		  else if (m_month < 1 || m_month>12) 
		  {
			  m_year = 0;
			  m_month = 0;
			  m_day = 0;
			  comValue = 0;
			  errCode(MON_ERROR);
		  }
		  else if (m_day < 1 || m_day > 31) 
		  {
			  m_year = 0;
			  m_month = 0;
			  m_day = 0;
			  comValue = 0;
			  errCode(DAY_ERROR);
		  }
	  }
	  else 
	  {
		  comValue = m_year * 372 + m_month * 13 + m_day;
		  m_error_state = CIN_FAILED;
	  }
	  return istr;
  }

  // This query writes the date to an std::ostream object in the following format: YYYY/MM/DD
  ostream& Date::write(ostream& ostr)const {

	  auto old_fill = ostr.fill();
	  auto old_w = ostr.width();

	  ostr.fill('0');
	  ostr << setw(4) << m_year << '/';
	  ostr << setw(2) << m_month << '/';
	  ostr << setw(2) << m_day;

	  ostr.fill(old_fill);
	  ostr.width(old_w);

	  return ostr;

  }

  // helper function (overloading)
  //std::ostream object to print a date to the console
  ostream& operator<<(ostream& ostr, const Date& rhs) {

	  rhs.write(ostr);
	  return ostr;
  }

  //std::istream object to read a date from the console
  istream& operator>>(istream& istr, Date& rhs) {

	  rhs.read(istr);
	  return istr;
  }
}
