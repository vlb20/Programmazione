
#include <iostream>
#include "Polynomial.h"

using std::cout;
using std::endl;

int main() {
	
	double a[] = {1.1, 2.2, 3.3, 4.4};
	Polynomial p1(a, 4);
	Polynomial p2(p1);
	cout << "p1 is " << p1 << endl << "p2 is " << p2 << endl;
	
	/*Polynomial p3 = p1 + p2;
	p1 += p3;
	cout << "p1 is " << p1 << endl << "p2 is " << p2 << endl;
	cout << "p3 is " << p3 << endl;*/
	
	double a4[] = {3,3,3,3,3};
	Polynomial p4(a4, 5);
	cout << p4 << endl;
	p4 += Polynomial(8);
	cout << p4 << endl;
	
	Polynomial p5 = p4 * 0.5;
	Polynomial p6 = 4 * p5;
	cout << p5 << endl << p6 << endl;
	
	// Uncommenting these lines and compiing wil result in a compilation error
	/*
	da errore perché, definendo il costruttore explicit nel caso di aggiunta di costante,
	non gli diamo la possibilità di cambiare implicitamente il double a un polinomio.
	È necessario invocare il costruttore in maniera esplicita
	*/
	// int x = 2; 
	// p5 += x;
	// cout << p5 << endl << x << endl;
	
	if (p4 == p4)
		cout << "p4 == p4" << endl;
	if (p4 == p6) 
		cout << "p4 == p6" << endl;
	cout << "\n\n\n";
	Polynomial p7 = p4 * p5;
	cout << p4 << " * \n" << p5 << " = \n";
	cout << p7<<endl;
	double b[] = {1,2};
	double c[] = {3,1};
	Polynomial p8{b,2};
	Polynomial p9{c,2};
	Polynomial p10 = p8 * p9;
	cout << p8 << " * \n" << p9 << " = \n";
	cout << p10;
	
	return 0;
}