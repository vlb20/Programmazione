//testGenericList.cpp
#include <iostream>
#include <string>
#include "LinkedList.h"

using std::string;
using std::cout;

int main(){
LinkedList<string> L;
L.addFront("FCO");
L.addFront("LAX");
L.addFront("XDD");
L.addFront("DXD");
L.addFront("DDX");
cout << L.front() << "\n";
LinkedList<int> L2;
L2.addFront(10);
L2.addFront(20);
cout << L2.front() << "\n";

L.print();
L.reversal();
L.print();
cout << "\n size of list L is "<< L.size();
cout << "\n first element of the list is " << L[0];
cout << "\n second element of the list is " << L[1];
cout << "\n last element of the list is " << L[4]<<"\n";
L.addBack("KEK"); L.print();
L.addPosition("Cringe", 2);
L.print();
LinkedList<string> L3(L);
L3.addBack("Boi");
L3.print();
cout <<"\ncopy";
LinkedList<string> L4 = L3;
L4.print();
cout << "\nequal";
}
