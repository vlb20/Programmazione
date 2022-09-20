#include<iostream>
#include<stdexcept>
#include "Time.h"
using std::cin;
using std::cout;
using std::string;

void displayTime(const string& message, const Time& time){
    cout<<message<<"\nUniversal time:"<<time.toUniversalString()
        <<"\nStandard time:"<<time.toStandardString()<<"\n\n";
}

int main(){
    Time t;

    displayTime("Initial time:",t);
    t.setTime(13,27,6);
    displayTime("After setTime:",t);

    try{
        t.setTime(99,99,99);
    }
    catch (std::invalid_argument& e){
        cout<<"Eccezione:"<<e.what()<<"\n\n";
    }

    displayTime("After attempting to set an invalid time:",t);
}