// Date.cpp
//Date class member-function definitions
#include <sstream>
#include <string>
#include <iostream>
#include <array>
#include <stdexcept>
#include "Date.h"

using std::string;
using std::ostream;
using std::endl;
using std::array;
using std::cout;
using std::invalid_argument;

//initialize static member; one classwide copy
const array<unsigned int, 13> Date::days{
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Date consructor
Date::Date(int day, int month, int year){
	setDate(day,month, year);
}
//copyconstructor and operator= 

Date::Date(const Date&d){
	setDate(d.day, d.month,d.year);
}

Date& Date::operator=(const Date&d){
	if(!(this == &d)){
		day = d.day;
		month = d.month;
		year = d.year;
	}
	return *this;
}


//set month, day and year
void Date::setDate(int dd, int mm, int yy){
	if( mm >= 1 && mm<= 12) {	
		month = mm;
	}
	else {
		throw invalid_argument("Month must be 1-12");
	}
	
	if ( yy >= 1900 && yy <= 2100) {
		year = yy;
	}
	else {
		//throw invalid_argument("Year must be >= 1900 and <= 2100");
	}
	
	// test for a leap year
	if((month == 2 && leapYear(year) && dd >= 1 && dd <=29) || (dd >= 1 && dd <= days[month])) {
		day = dd;
	}
	else {
		throw invalid_argument("Day is out of range for current month and year");
	}
}

bool Date::operator<(const Date& second) const {
	if (year < second.year) return true;
	if (year == second.year && month < second.month) return true;
	if (year == second.year && month == second.month && day < second.day) return true;
	return false;
}

// add a specific number of days
Date operator+(int numdays, const Date& dd)
{
	Date newdate = dd;
	for (int i = 1 ; i <= numdays; i++) {newdate.helpIncrement();}
	return newdate;
}
//add the invoking object and a specific number of days
Date operator+(const Date& dd, int numdays)
{
	Date newdate = dd;
	for(int i = 1 ; i<= numdays; i++) {newdate.helpIncrement();}
	return newdate;
}
// overloaded prefix increment operator
Date& Date::operator++() {
	helpIncrement(); 	// increment date
	return *this; 		// reference return to create an lvalue
}

// overloaded postfic increment operator; note that the dummy integer parameter
// does not have a parameter name
Date Date::operator++(int){
	Date temp{*this};		//hold current state of object
	helpIncrement();
	
	// reutnr unincremented, saved, temporary object
	return temp;	// value return; not a reference return
}

// add specified number of days to date
Date& Date::operator+=(unsigned int additionalDays) {
	for (unsigned int i = 0; i < additionalDays; ++i) {helpIncrement();}
	return *this;
}
	
//if the year is a leap year, return true; otherwise, return false
bool Date::leapYear(int testYear) { return (testYear % 400 == 0 || (testYear % 4 == 0 && testYear % 100 != 0)); }
	
// determine wheter the day is the last day of the month
bool Date::endOfMonth(int testDay) const {
	if (month == 2 && leapYear(year)) return testDay == 29;
	else return testDay == days[month];	
}


void Date::helpIncrement() {
	// day is not end of month
	if (!endOfMonth(day)){++day;} // increment day
	else {
		if (month < 12) {	// day is end of month and month < 12
			++month;
			day = 1;
		}
		else { // last day of year
			++year;
			month = 1;
			day = 1;
		}
	}
}

// overloaded output operator
ostream& operator<<(ostream& output, const Date& d){
	static string monthName[13]{"", "January", "February", "March", "April", "May", "June", "July", "August",
	"september", "October", "November", "December"};
	output<< d.day<< ' ' << monthName[d.month] << ' ' << d.year;
	return output; // enables cascading
	
}


// overloaded operators exercise

bool Date::operator>(const Date& second) const {
	if (year > second.year) return true;
	if (year == second.year && month > second.month) return true;
	if (year == second.year && month == second.month && day > second.day) return true;
	return false;
	
}

bool Date::operator >=(const Date& second) const {
		if (year >= second.year) return true;
		if (year == second.year && month >= second.month) return true;
		if (year == second.year && month == second.month && day >= second.day) return true;
		return false;
}

bool Date::operator <=(const Date& second) const{
	if (year <= second.year) return true;
	if (year == second.year && month <= second.month) return true;
	if (year == second.year && month == second.month && day <= second.day) return true;
	return false;
}

bool Date::operator !=(const Date& second) const {
	if(year != second.year) return true;
	if (year == second.year && month != second.month) return true;
	if (year == second.year && month == second.month && day != second.day) return true;
	return false;
}
bool Date::operator ==(const Date& second) const {
	if (year == second.year && month == second.month && day == second.day) return true;
	return false;
}

void Date::helpDecrement() {

	// day is not begin of month
	if (day != 1){--day;} // decrement
	else {
		if (month > 1) {	// day is begin of month and month >= 1
			--month;
			day = days[month];
		}
		else { // first day of the year
			--year;
			month = 12;
			day = days[month];
		}
	}	
}

Date operator-(const Date& dd, int numdays){
	Date newdate = dd;
	for(int i = 1 ; i<= numdays; i++) {newdate.helpDecrement();}
	return newdate;
}
