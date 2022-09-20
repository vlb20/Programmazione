// Time.h
// Time class definition.
// Member function are defined in Time.cpp

#include <string>

//Prevent multiple inclusions of header
#ifndef TIME_H
#define TIME_H

//Time class definition
class Time{
public:
	explicit Time(int = 0, int = 0, int = 0); //default constructor

	//set functions
	void setTime(int, int, int); // set hour, minute and second
	void setHour(int); // set hour (after validation)
	void setMinute(int); // set minute (after validation)
	void setSecond(int); // set second (after validation)
	
	//get functions
	unsigned int getHour() const; //return hour
	unsigned int getMinute() const; // return minute
	unsigned int getSecond() const; // return second
	
	std::string toUniversalString() const; // 24-hour time format
	std::string toStandardString() const; // 12-hour time format
private:
	unsigned int hour{0}; // 0 - 23 (24-hour clock format)
	unsigned int minute{0}; // 0-59
	unsigned int second{0}; // 0-59
};
#endif