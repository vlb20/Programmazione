#ifndef SPEDIZIONI_H
#define SPEDIZIONI_H
#include "Pacco.h"
#include "PaccoExtra.h"
#include<list>
#include<string>
#include<iostream>

class Spedizione{
    friend class Pacco;
public:
    
    Spedizione() {}

    void addPackage(Pacco* p){
        std::list<Pacco*>::iterator it;
        it=pacchi.begin();
        std::cout<<"Tipo: ";
        p->type();
        if(pacchi.empty()){
            pacchi.insert(it,p);
        }else{
            bool temp;
            do{
                if(p->getData() < (*it)->getData()){
                pacchi.insert(it,p);
                temp=true;
                }else if(pacchi.end() == it){
                    pacchi.insert(it,p);
                    temp=true;
                }
                it++;
            }while(!temp);
        }
    }

    int weeklyEarnings(){
        int totale{0};
        int temp;
        std::list<Pacco*>::iterator cur;
        cur=pacchi.begin();
        do{
            std::cout<<"Tipo:"<<(*cur)->type()<<"\n";
            temp=(*cur)->earnings();
            totale += temp;
        }while(cur != pacchi.end());
        std::cout<<"\nPrezzo totale: "<<totale<<std::endl;
        return totale;
    }

    std::list<Pacco*> getLista() const{
        return pacchi;
    }
private:
    std::list<Pacco*> pacchi;
};

#endif