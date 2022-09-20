#include "Rettangolari.h"
#include<iostream>
#include<string>

Rettangolo::Rettangolo(int c, const std::string& legno, const std::string& f, float p, double b, double h):
    Tavolo::Tavolo(c,legno,f,p), base{b}, altezza{h} {}

void Rettangolo::setBase(double b){base=b;}
double Rettangolo::getBase() const{return base;}

void Rettangolo::setAltezza(double h){altezza=h;}
double Rettangolo::getAltezza() const{return altezza;}

double Rettangolo::getArea() const{
    return (base*altezza);
}

void Rettangolo::print() const{
    Tavolo::print();
    std::cout<<"Tipo:Piano Rettangolare"
             <<"\n Base: "<<base<<"\n Altezza: "<<altezza<<std::endl;
}

void Rettangolo::type() const{
    std::cout<<"Rettangolare";
}