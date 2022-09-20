#include<iostream>
#include<string>
#include"Date.h"

using std::cout;
using std::array;
using std::invalid_argument;

const array<unsigned int,13> Date::days{
    0,31,28,31,30,31,30,31,31,30,31,30,31};

//costruttore 
Date::Date(int day,int month,int year){
    setDate(day,month,year);
}

/*/default constructor
Date::Date(){
    setDate(1,1,1999);
}*/

//settiamo giorno mese e anno
void Date::setDate(int dd,int mm,int yy){
    //Validiamo l'inserimento del mese
    if(mm>=1&&mm<=12){
        month=mm;
    }
    else{
        throw invalid_argument{"Month must be 1-12"};
    }

    //Validiamo l'inserimento dell'anno
    if(yy>=1900 && yy<=2100){
        year=yy;
    }
    else{
        throw invalid_argument{"Year must be >=1900 and <=2100"};
    }

    //Validiamo per l'anno bisestile caso di febbraio
    if((month==2&&leapYear(year)&&dd>=1&&dd<=29)||(dd>=1&&dd<=days[month])){
        day=dd;
    }
    else{
        throw invalid_argument{"Day is out of range for current month and year"};
    }
}

bool Date::operator<(const Date& second) const{
    if(year<second.year)
        return true;
    if(year==second.year&&month<second.month)
        return true;
    if(year==second.year&&month==second.month&&day<second.day)
        return true;
    return false;
}

bool Date::operator==(const Date& test) const{
    if(year==test.year && month==test.month && day==test.day){
        return true;
    }
    return false;
}

bool Date::operator!=(const Date& second) const{
    if(!(year==second.year&&month==second.month&&day==second.day)){
        return true;
    }
    return false;
}

//overloaded dell'operatore output
std::ostream& operator<<(std::ostream& output,const Date& d){
    static std::string monthname[13]{"","January","February","March","April","May","June","July","August","September","October","November","December"};
    output<<d.day<<' '<<monthname[d.month]<<' '<<d.year;
    return output;//enables cascading
}

//aggiunguiamo uno specifico numero di giorni
Date operator+(int numdays,const Date& dd){
    Date newdate =dd;
    for(int i=1;i<=numdays;i++)
        newdate.helpIncrement();
    return newdate;
}

//facciamo che questa assegnazione valga anche a posti invertiti
Date operator+(const Date& dd,int numdays){
    Date newdate =dd;
    for(int i=1;i<=numdays;i++)
        newdate.helpIncrement();
    return newdate;
}

//overloading del preincremento
Date& Date::operator++(){
    helpIncrement();
    return *this;
}

//overloading del post-incremento (nel farlo usiamo un copyconstructor+dummy integer)
Date Date::operator++(int){
    Date temp{*this};//mantengo il valore della data prima di incrementarla
    helpIncrement();

    //return del valore non incrementato(da l'illusione che lo incrementi poi)
    return temp;
}

Date& Date::operator+=(unsigned int addionalDays){
    for(unsigned int i=0;i<addionalDays;++i){
        helpIncrement();
         }
    }

Date& Date::operator=(const Date& data){
    setDate(data.day,data.month,data.year);
}

//Controllo sull'incremento dei giorni
void Date::helpIncrement(){
    //controllo se il giorno non sta alla fine del mese
    if(!endOfMonth(day)){
        ++day;//incrementiamo in giorno
    }else{
        if(month<12){
            ++month;
            day=1;
        }else{
            ++year;
            month=1;
            day=1;
        }
    }
}

//controllo fine mese
bool Date::endOfMonth(int testDay) const{
    if(month==2&&leapYear(year)){
        return testDay==29;
    }else{
        return testDay==days[month];
    }
}

//verifichiamo di non essere in un anno bisestile
bool Date::leapYear(int testyear){
    return(testyear%400==0 || (testyear%100!=0 && testyear%4==0));
}