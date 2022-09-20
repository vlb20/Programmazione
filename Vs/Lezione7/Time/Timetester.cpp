//Program to test calss Time.
// NOTE: This file must be compiled with Time.cpp
#include <iostream>
#include <stdexcept> // for invalid_argument exception class
#include "Time.h" // include definition of class Time from Time.h

using std::cout;
using std::invalid_argument;
using std::endl;
using std::cerr;
using std::string;


// Displays a Time in 24-hour and 12-hour formats
void displayTime(const string& message, const Time& time) {
	cout << message << "\nUniversal time: " << time.toUniversalString()
		<< "\nStandard time: " << time.toStandardString() << "\n\n";
}

int main(){
	Time t1; // all arguments defaulted
	Time t2{2}; // hour specified; minute and second defaulted
	Time t3{21,34}; // hour and minute specified; second defaulted
	Time t4{12, 25, 42}; // hour minute and second specified
	
	
	cout << "Constructed with: \n\n";
	displayTime("t1: all arguments defatulted", t1);
	displayTime("t2: hour specified; minute and second defaulted", t2);
	displayTime("t3: hour and minute specified; second defaulted", t3);
	displayTime("t4: hour, minute and second specified", t4);
	t1.setTime(13, 27, 6); // change time
	displayTime("After setTime:" , t1); // display t's new value
	
	//attempt to set the time with invalid values
	try{
		Time t{99,99,99}; //all values out of range
	}
	catch(invalid_argument &e) {
		cerr << "Exception while initializing t: " << e.what() << "\n\n";
	}

}		