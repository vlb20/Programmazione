#ifndef PACCO_H
#define PACCO_H
#include<string>
#include<iostream>
#include"Date1.h"

class Pacco{
public:
    Pacco(std::string m="",  std::string des = "", Date d=Date{}, int p =0):
        mittente{m}, destinatario{des}, data{d}, peso{p}  {}

    float getPeso() const{
        return peso;
    }
    virtual std::string type() const{
        return "Spedizione europea\n";
    }
    /*virtual void print() const{
        std::cout<<"\nMittente: "<<mittente<<"--->Destinatario: "<<destinatario
                 <<"\n Data di consegna:" << data <<"\n Peso: "<< peso<<" Kg\n";
    }*/

    virtual int earnings() const{
        return peso;
    }
    
    Date getData() const{
        return data;
    }

    bool operator<(const Pacco& p){
        return(this->data < p.data);
    }
protected:
    std::string mittente;
    std::string destinatario;
    Date data;
    int peso;

};

#endif