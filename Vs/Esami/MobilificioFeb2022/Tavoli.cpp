#include "Tavoli.h"
#include<string>
#include<sstream>
#include<iostream>

Tavolo::Tavolo(int c, const std::string& legno, const std::string& f, float p):
    colore{c}, tipoLegno{legno}, fornitore{f}, prezzo{p} {}

void Tavolo::setColore(int c){
    colore=c;
}
int Tavolo::getColore() const{return colore;}

void Tavolo::setLegno(const std::string& legno){tipoLegno=legno;}
std::string Tavolo::getLegno() const{return tipoLegno;}

void Tavolo::setFornitore(const std::string& f){fornitore=f;}
std::string Tavolo::getFornitore() const{return fornitore;}

void Tavolo::setPrezzo(float p){prezzo=p;}
float Tavolo::getPrezzo() const{return prezzo;}


void Tavolo::print() const{
    std::cout<<"\n CODICE COLORE: "<<colore
    <<"\n TIPOLOGIA LEGNO: "<<tipoLegno
    <<"\n FORNITORE: "<<fornitore
    <<"\n PREZZO: "<<prezzo;
}

void Tavolo::type() const{
    std::cout<<"Tavolo";
}