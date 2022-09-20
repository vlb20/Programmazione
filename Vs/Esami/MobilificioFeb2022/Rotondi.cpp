#include "Rotondi.h"
#include<iostream>
#include<string>

Rotondo::Rotondo(int c, const std::string& legno, const std::string& f, float p, double r):
    Tavolo::Tavolo(c,legno,f,p), raggio{r} {}

void Rotondo::setRaggio(double r){raggio=r;}
double Rotondo::getRaggio() const{return raggio;}

double Rotondo::getArea() const{
    return (raggio*raggio*pi);
}

void Rotondo::print() const{
    Tavolo::print();
    std::cout<<"Tipo: Tavolo Rotondo "
    <<"\n Raggio:"<<raggio<<std::endl;
}

void Rotondo::type() const{
    std::cout<<"Tondo";
}