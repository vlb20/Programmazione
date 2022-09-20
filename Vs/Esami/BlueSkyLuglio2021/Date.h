#ifndef DATE_H
#define DATE_H

class Date{
public:
    Date(int day, int month, int year): d{day}, m{month}, y{year} {}
    bool operator<(Date rhs){
        if(y<rhs.y){
            return true;
        }else if(y==rhs.y && m<rhs.m){
            return true;
        }else if(y==rhs.y && m==rhs.m && d<rhs.d){
            return true;
        }else return false;
    }
    
private:
    int d;
    int m;
    int y;
};


#endif