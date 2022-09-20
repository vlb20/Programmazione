/*
• 
Create a class called Date that includes three pieces of
information as data members—a month (type int), a day (type int)
and a year (type int).
• Your class should have a constructor with three parameters that
uses the parameters to initialize the three data members.
• For the purpose of this exercise, assume that the values
provided for the year and day are correct, but ensure that the
month value is in the range 1–12; if it isn’t, set the month to
1. –
• provide a set and a get function for each data member. Provide a
member function displayDate that displays the month, day and
year separated by forward slashes (/).
• Write a test program that demonstrates class Date’s
capabilities.*/

#include<iostream>

class Date{
    public:    
        Date(int m, int d, int y)
        : month{m},day{d},year{y}{}

        Date(){}

        void setMonth(int m){
            if(month>=1&&month<=12){
                 month=m;
            }else{
                std::cout<<"Il mese deve essere compreso tra 1 e 12";
            }
           

        }

        int getMonth(){
            return month;
        }

        void setDay(int d){
            if(day>=1 && day<=31){
                 day=d;

            }
           
        }

        int getDay(){
            return day;
        }

        void setYear(int y){
            year=y;
        }

        int getYear(){
            return year;
        }

        void displayDate(){
            std::cout<<month<<"\\"<<day<<"\\"<<year<<std::endl;
        }

    private:
        int month{1};
        int day{1};
        int year{1};
};        