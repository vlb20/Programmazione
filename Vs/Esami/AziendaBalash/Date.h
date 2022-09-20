//Date.h
// Date class definition; Member functions defined in Date.cpp


#ifndef DATE_H
#define DATE_H

#include <array>
#include <iostream>


class Date {
	friend std::ostream& operator<<(std::ostream&, const Date&);
	friend Date operator+(int, const Date& );
	friend Date operator+(const Date&, int);
	friend Date operator-(const Date&, int);
public:
	Date(int d = 1, int m = 1, int y = 1900); // default constructor
	Date(const Date& d);
	~Date(){}
	void setDate(int, int, int); 				// set month, day, year
	Date& operator =(const Date& d);
	Date& operator++(); // prefix increment operator
	Date operator++(int); //postfix increment operator
	Date& operator+=(unsigned int); // add days, modify object
	static bool leapYear(int); // is year a leap year?
	bool endOfMonth(int) const ; // is the year a leap year?
	bool operator<(const Date&) const;
	bool operator>(const Date&) const;
	bool operator >=(const Date&) const;
	bool operator <=(const Date&) const;
	bool operator !=(const Date&) const;
	bool operator ==(const Date&) const;
private:
	unsigned int day; // 1-31 based on month
	unsigned int month; // 1-12(January - December)
	unsigned int year; // any year
	static const std::array<unsigned int,13> days; // days per month
	void helpIncrement(); // utility function for incrementing date
	void helpDecrement(); // utiliy function for decrementing date
	// utility function to check if day is proper for month and year
};


#endif