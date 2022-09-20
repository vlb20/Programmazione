// Cascade.cpp
// Cascading member-function calls with the this pointer
#include <iostream>
#include "Time.h" // time class definition

using std::cout;
using std::endl;
int main() {
	Time t; 	// create time object
	
	t.setHour(18).setMinute(30).setSecond(22); 		// cascaded funcion calls
	
	// output time in universal and standard formats
	
	cout << "Universal time: " << t.toUniversalString() << "\nStandard time: " << t.toStandardString();
	
	// cascaded funcion calls 
	
	cout << "\n\nNew satndard tine: " << t.setTime(20,20,20) .toStandardString() << endl;
}