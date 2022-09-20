#include<iostream>
#include<string>
#include "THR.h"
#include "Date.h"

using std::cout;
using std::cin;
using std::string;

HeartRates::HeartRates(std::string fname, std::string lname, int m, int d, int y)
    {
        setFname(fname);
        setLname(lname);
        setDate(m,d,y);
    }

void HeartRates::setFname(std::string fname){
    firstName=fname;
}

void HeartRates::setLname(std::string lname){
    lastName=lname;
}

void HeartRates::setDate(int m, int d, int y){
    data.setMonth(m);
    data.setDay(d);
    data.setYear(y);    
}

std::string HeartRates::getFname(){
    return firstName;
}

std::string HeartRates::getLname(){
    return lastName;
}

void HeartRates::getDate(){
    return data.displayDate();
}


int HeartRates::ageCalc(){
    age=2022-data.getYear();
    return age;
}

float HeartRates::mhrCalc(){
    MHR=220-age;
    return MHR;
}

float HeartRates::thrMin(){
    min=MHR/2;
    return min;
}

float HeartRates::thrMax(){
    max=MHR*0.85;
    return max;
}

void HeartRates::displayThr(){
    cout<<"Il Target Heart Rate Range e': "<<min<<" - "<<max;
}

void HeartRates::displayInfo(){
    cout<<"\n-----Scheda paziente-----\n";
    cout<<"Nome:"<<firstName;
    cout<<"\nCognome:"<<lastName;
    cout<<"\nData di nascita:";
    data.displayDate();
    cout<<"\nMax. Heart Rate:"<<MHR;
    cout<<"\nTarget Heart Rate Range:";
    displayThr();

    

}



