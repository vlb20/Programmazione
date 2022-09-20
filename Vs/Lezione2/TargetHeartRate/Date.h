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