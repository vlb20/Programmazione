#include <iostream>
#include "Date.h" // include definition of class Date form Date.h
#include <sstream>
using std::cout; 
using std::endl; 
using std::ostringstream;

int main() {
	Date d1{25, 12, 2020};
	Date d2; // date2 defaults to 1/1/2000
	
	cout << "d1 is " << d1 << "\n d2 is " << d2;
	cout << "\n\nd1 += 7 is " << (d1 += 7);
	
	d2.setDate(28, 2, 2008);
	cout << "\n\n d2 is " << d2;
	cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)" ;
	
	Date d3{13, 1, 2010};
	
	cout << "\n\nTesting the prefix increment operator: \n"
		<< "  d3 is " << d3 << endl;
	cout << "++d3 is " << ++d3 << endl;
	cout << "  d3 is " << d3;
	
	cout << "\n\nTesting the postfix increment operator:\n"
		<< "  d3 is " << d3 << endl;
	cout << " d3++ is " << d3++ << endl;
	cout << " d3 is " << d3;
	
	std::string check = (d2 < d3)? " is " : "is not " ;
	cout << "\n\nTestings relational operators: \n"
		<< d2 << check <<"less than " << d3 << "\n";
	
	std::string check2 = (d1 > d3)? " is " : "is not " ;
	cout << "\n\nTestings relational operators: \n"
		<< d1 << check2 <<"more than " << d2 << "\n";
	
	std::string check3 = (d1 != d3)? " is " : "is not " ;
	cout << "\n\nTestings relational operators: \n"
		<< d1 << check3 <<"different than " << d2 << "\n";
	
	Date d4 =d3 +10;
	cout << "\n\nTesting summing numberofdays\n"
		<< d4 << " = " << d3 << " + 10 days \n";
	d4  = d3 - 20;
	cout << "\n\nTesting subtracting numberofdays\n"
		<< d4 << " = " << d3 << " - 20 days \n";
}