#ifndef PACCOEXTRA_H
#define PACCOEXTRA_H
#include"Date1.h"
#include"Pacco.h"
#include<iostream>
#include<string>

class PaccoExtra : public Pacco{
public:
    PaccoExtra(std::string m="", std::string des="", Date d=Date{}, int p=0,std::string naz="",std::string con="")
        :Pacco::Pacco(m,des,d,p), nazioneSped{naz}, continente{con} {}

    std::string type() const {
       return "Spedizione extra-europea";
    }

    /*void print() const override{
        Pacco::print();
        std::cout<<"Nazione di spedizione: "<<nazioneSped<<"\n Continente:"<<continente<<std::endl;
    }*/

    int earnings() const override{
        if(continente=="USA"){
            return (peso+10);
        }else{
            return (peso+15);
        }

    }

private:
    std::string nazioneSped;
    std::string continente;
};


#endif