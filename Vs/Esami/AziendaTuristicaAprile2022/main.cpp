#include "Prenotazione.h"
#include "Albergo.h"
#include "Date.h"
#include<list>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

void insertBooking(const std::string& nome, const std::string& num, const Date& data, int s, std::vector<Albergo*> &alb);
void vectorPrint(std::vector<Albergo*>&alb);

int main(){
    std::vector<Albergo*> alberghi;
    std::list<Prenotazione*> prenotazioni;

    Albergo a1{"HOTEL CRISTINA",38.50,4};
    Albergo a2{"HOTEL JFK",25.70,4};
    Albergo a3{"LA LUNA ROSSA",60.0,5};
    Albergo a4{"HOTEL RAMADA",15.50,2};
    Albergo a5{"MOTEL CIRCUMVALLAZIONE",20.0,2};

    alberghi.push_back(&a1);
    alberghi.push_back(&a2);
    alberghi.push_back(&a3);
    alberghi.push_back(&a4);
    alberghi.push_back(&a5);

    std::sort(alberghi.begin(),alberghi.end(),std::greater<Albergo*>());

    Prenotazione p1{"CRISTINA","CC22GLN",{06,07,2022}};
    Prenotazione p2{"VINCENZO LUIGI BRUNO","VLB20NPL",{28,06,2022}};
    Prenotazione p3{"DAMIANO BRUNO","DMN30BRN",{21,07,2022}};
    Prenotazione p4{"SAVIO","SVRTEN",{23,10,2022}};

    std::cout<<alberghi.size()<<std::endl;

    /*a1.insertOrder(&p1);
    a1.insertOrder(&p2);
    a2.insertOrder(&p3);
    a3.insertOrder(&p4);*/

    std::sort(alberghi.begin(),alberghi.end(),std::greater<Albergo*>());
    vectorPrint(alberghi);

    insertBooking("PINO","RETNF",{10,10,2022},4,alberghi);
    
    vectorPrint(alberghi);

    return 0;

    

}

void vectorPrint(std::vector<Albergo*>&alb){   // stampa tutti gli alberghi con relative prenotazioni
    for(int i = 0; i< alb.size(); i++){
         std::cout <<alb[i]->toString();
        std::cout << "\n *----------------------------------* \n";
    }
}

void insertBooking(const std::string& nome, const std::string& num, const Date& data, int s, std::vector<Albergo*> &alb){
    Prenotazione pr(nome,num,data);
    bool temp;//vera se abbiamo trovato un albergo
    for(int i=0; i<alb.size(); i++){
        if(s==alb[i]->getStelle()){
            if(!(alb[i]->findDate(&pr))){
                //alb[i]->insertOrder(&pr);
                temp=true;
                std::sort(alb.begin(),alb.end(),std::greater<Albergo*>());
            }
            
        }
    }
    if(temp=true){
        std::cout<<"Prenotazione inserita!\n";
    }else{
        std::cout<<"Data non disponibile\n";
    }
}

