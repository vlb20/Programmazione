#include "Mobilificio.h"
#include<string>
#include<list>
#include<iostream>

Mobilificio::Mobilificio() {}

void Mobilificio::insertTable(Tavolo* t){
    std::list<Tavolo*>::iterator it;
    it=tavoli.begin();
    std::cout<<"Tipo: ";
    t->type();
    if(tavoli.empty()){
        tavoli.insert(it,t);
        std::cout<<"Primo elemento della lista:\n";
    }else{
        bool temp;
        do{
            if(tavoli.end() == it){
                tavoli.insert(it,t);
                temp=true;
            }else if(t->getArea() <= (*it)->getArea()){
                tavoli.insert(it,t);
                temp=true;
            }
            it++;
        }while(!temp);
    }
}

double Mobilificio::summarizeWharehouse(){
    double totale{0.0};
    int temp;
    std::list<Tavolo*>::iterator it;
    it=tavoli.begin();

    do{
        temp=(*it)->getPrezzo();
        totale += temp;
        it++;
    }while(it != tavoli.end());

    std::cout<<"Prezzo totale: "<<totale<<std::endl;
    return totale;
}

std::list<Tavolo*> Mobilificio::getLista() const{
    return tavoli;
}