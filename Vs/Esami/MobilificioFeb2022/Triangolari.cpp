#include"Triangolari.h"
#include<string>
#include<iostream>

Triangolo::Triangolo(int c, const std::string& legno, const std::string& f, float p, double b, double h):
    Tavolo::Tavolo(c,legno,f,p), base{b}, altezza{h} {}

void Triangolo::setBase(double b){base=b;}
double Triangolo::getBase() const{return base;}

void Triangolo::setAltezza(double h){altezza=h;}
double Triangolo::getAltezza() const{return altezza;}

double Triangolo::getArea() const{
    return ((base*altezza)/2);
}

void Triangolo::print() const{
    Tavolo::print();
    std::cout<<"Tipo: Tavolot Triangolare "
             <<"\n Base: "<<base<<"\n Altezza: "<<altezza<<std::endl;            
}

void Triangolo::type() const{
    std::cout<<"Triangolare ";
}