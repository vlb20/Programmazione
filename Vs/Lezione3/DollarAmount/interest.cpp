#include<iostream>
#include<iomanip>
#include<string>
#include "Dollar.h"
using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main(){
    DollarAmount d1{12345}; //123.45
    DollarAmount d2{1576};

    cout<<"After adding d2("<<d2.toString()<<") into d1("
        << d1.toString() <<"), d1=";
    d1.add(d2);
    cout<<d1.toString()<<"\n";

    cout<<"After subtracting d2("<<d2.toString()<<") from d1("
        <<d1.toString()<<"), d1=";
    d1.subtract(d2);
    cout<< d1.toString()<<"\n";

    cout<<"After subtracting d1("<<d1.toString()<<") from d2("
        <<d2.toString()<<"), d2=";
    d2.subtract(d1);
    cout<< d2.toString()<<"\n\n";

    cout<<"Inserisci tasso di interesse e divisore, per esempio:\n"
        <<" per     2%, inserisci: 2 100\n"
        <<" per   2.3%, inserisci: 23 1000\n";

    int rate;
    int divisor;
    cin>>rate>>divisor;

    DollarAmount balance{100000};
    cout<<"\nInitial balance:"<<balance.toString()<<endl;

    cout<<"\nYear"<<setw(20)<<"Amount on deposit"<<endl;

    for(unsigned int year{1}; year<=10;year++){
        balance.addInterest(rate,divisor);

        cout<<setw(4)<<year<<setw(20)<<balance.toString()<<endl;
    }

}