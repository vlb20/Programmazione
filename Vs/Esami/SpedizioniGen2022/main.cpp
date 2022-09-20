#include "Spedizioni.h"
#include"Pacco.h"
#include"PaccoExtra.h"
#include"Date1.h"
#include<iostream>
#include<list>

int main(){
    Spedizione myList;
    
    Pacco p1("Vincenzo Luigi Bruno","Cristina Carleo",{06,07,2022},5);
    PaccoExtra p2("Damiano Bruno","Fabrizio Di Giulio",{11,01,2021},7,"Australia", "Oceania" );
    PaccoExtra p3("Ale","Franz",{1,1,2022},10,"California", "USA");

    myList.addPackage(&p1);
    myList.addPackage(&p2);
    myList.addPackage(&p2);
   
    /*for(Pacco *i: myList.getLista()){
        i->print();
    }*/
    
    myList.weeklyEarnings();
}