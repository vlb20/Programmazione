#ifndef DATE_H
#define DATE_H

#include<array>
#include<iostream>

class Date{
    friend std::ostream& operator<<(std::ostream&,const Date&);
    friend Date operator+(int, const Date&);
    friend Date operator+(const Date&, int);
public:
    //Date();
    Date(int d=1, int m=1, int y=1900); //costruttore di default 
    void setDate(int,int,int);
    Date& operator++();
    Date operator++(int);
    Date& operator+=(unsigned int);
    Date& operator=(const Date&);
    static bool leapYear(int);
    bool endOfMonth(int) const;
    bool operator<(const Date&) const;
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
    static const std::array<unsigned int,13> days;
    void helpIncrement();
};

#endif