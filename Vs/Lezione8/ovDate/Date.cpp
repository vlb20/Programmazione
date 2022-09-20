#include <iostream>
#include <string>
#include "Date.h"
#include<stdexcept>

using std::array;
using std::invalid_argument;
using std::cin;
using std::cout;
using std::ostream;

const array<unsigned int, 13> Date::days{
    0, 31, 28, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int day, int month, int year){
    setDate(day, month, year);
}

void Date::setDate(int dd, int mm, int yy){
    if(mm>=1 && mm<=12){
        month==mm;
    }
    else{
        throw invalid_argument{"Il mese deve essere 1-12"}; 
    }

    if(yy>= 1900 && yy<=2100){
        year==yy;
    }
    else{
        throw invalid_argument{"L'anno deve essere >=1900 e <=2100"};
    }

    if((month==2 && leapYear(year) && dd>=1 && dd<=29) || (dd>=1 && dd<=days[month])){
        day=dd;
    }
    else{
        throw invalid_argument{
            "Day is out of range for cuurent month and year"};
    }
}

bool Date::operator<(const Date& second) const{
    if(year<second.year)    
        return true;
    if(year==second.year && month<second.month)
        return true;
    if(year==second.year && month==second.month && day<second.day)
        return true;
    return false;
}

Date operator+(int numdays, const Date& dd){
    Date newdate=dd;
    for(int i=1;i<=numdays;i++)
        newdate.helpIncrement();
    return newdate;
}

Date operator+(const Date& dd, int numdays)
{
	Date newdate = dd;
	for(int i = 1 ; i<= numdays; i++) {
        newdate.helpIncrement();}
	return newdate;
}

Date& Date::operator++(){
    helpIncrement();
    return *this;
}

Date Date::operator++(int){
    Date temp(*this);
    helpIncrement();

    return temp;
}

Date& Date::operator+=(unsigned int additionalDays){
    for(unsigned int i=0; i<additionalDays; ++i){
        helpIncrement();
    }

    return *this;
}

bool Date::leapYear(int testYear){
    return (testYear % 400==0 || (testYear % 100 !=0 && testYear % 4==0));
}

bool Date::endOfMonth(int testDay) const{
    if(month==2 && leapYear(year)){
        return testDay==29;
    }
    else{
        return testDay==days[month];
    }
}



void Date::helpIncrement(){
	if(!endOfMonth(day)){ //day is not end of the month
		++day;
}
else{
		if(month<12){
			++month;
			day=1;
		}
		else{ //last day of year
			++year;
			month=1;
			day=1;
		}
	}
}

ostream& operator<<(ostream& output, const Date& d){
    static std::string monthName[13]{" ","Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", 
    "Giugno","Luglio","Agosto","Settembre","Ottobre","Novembre","Dicembre"};
    output<<d.day<<" "<<monthName[d.month]<<" "<<d.year;
    return output;
}

bool Date::operator>(const Date& second) const{
    if(year>second.year)
        return true;
    if(year==second.year && month>second.month)
        return true;
    if(year==second.year && month==second.month && day>second.day)
        return true;
    return false;
}

bool Date::operator>=(const Date& second) const{
    if(year>=second.year)
        return true;
    if(year==second.year && month>=second.month)
        return true;
    if(year==second.year && month==second.month && day>=second.day)
        return true;
    return false;
}

bool Date::operator<=(const Date& second) const{
    if(year<=second.year)    
        return true;
    if(year==second.year && month<=second.month)
        return true;
    if(year==second.year && month==second.month && day<=second.day)
        return true;
    return false;
}

bool Date::operator!=(const Date& second) const{
    if(year!=second.year)    
        return true;
    if(year==second.year && month!=second.month)
        return true;
    if(year==second.year && month==second.month && day!=second.day)
        return true;
    return false;
}

bool Date::operator==(const Date& second) const{
    if(year==second.year && month==second.month && day==second.day)
        return true;
    return false;
}

void Date::helpDecrement(){
    if(day!=1){
        --day;
    }
    else{
        if(month>1){ //primo giorno del mese e il mese non è il primo dell'anno
            --month;
            day=days[month];
        }else{       //primo giorno dell'anno
            --year;
            month=12;
            day=days[month];
        }
    }
}

Date operator-(const Date& dd, int numdays){
    Date newdate=dd;
    for(int i=1; i<numdays; i++){
        newdate.helpDecrement();
        return newdate;
    }
}