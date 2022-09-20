//Time.cpp
// Time class member-function definitions for the modified cascade version
#include <iomanip> // for setw and setfill stream manipulation
#include <stdexcept> // for invalid_argument exception class
#include <sstream> // for ostringstream class
#include <string>
#include "Time.h" // include definition of class Time from Time.h
using std::ostringstream;
using std::invalid_argument;
using std::string;
using std::setw;
using std::setfill;

//time constructor initializes each data member
Time::Time(int hour, int minute, int second){
	setTime(hour, minute, second); 	// validate and set time
}

//set new Time value using universal time

Time& Time::setTime(int h, int m, int s){
	setHour(h); //set private field hour
	setMinute(m); // set private field minute 
	setSecond(s); // set private field second
	
	return *this; // enable cascading
}

// set hour value
Time& Time::setHour(int h){
	//validate hour, minute and second
	if(h >= 0 && h < 24) {
		hour = h;
	}
	else {
		throw invalid_argument(
			"hour must be 0-23");
	}
	
	return *this; 	// enable cascading
}

// set minute value
Time& Time::setMinute(int m){
	if(m >= 0 && m < 60) {
		minute = m;
	}
	else {
		throw invalid_argument(
			"Minute must be 0-59");
	}
	
	return *this; 	// enable cascading
}
//set second value
Time& Time::setSecond(int s){
	//validate hour, minute and second
	if(s >= 0 && s < 60) {
		second = s;
	}
	else {
		throw invalid_argument(
			"second must be 0-59");
	}
	return *this; 	// enable cascading
}
// return hour value
unsigned int Time::getHour() const {return hour;}

//return minute value
unsigned int Time::getMinute() const {return minute;}

//return second value

unsigned int Time::getSecond() const {return second;}
//return Time as a string in universal-time format (HH:MM:SS)

string Time::toUniversalString() const {
	ostringstream output;
	output << setfill('0')<< setw(2) << hour << ":" 
		<< setw(2) << minute << ":" << setw(2) << second;
	return output.str(); // returns the formattes string
}

//return Time as string in standard-time format (HH:MM:SS AM or PM)
string Time::toStandardString() const{
	ostringstream output; 
	output << ((hour == 0 || hour == 12 ) ? 12 : hour % 12) << ":"
		<< setfill('0') << setw(2) << minute << ":" << setw(2) 
		<< second << (hour < 12? " AM" : " PM");
	return output.str();
}