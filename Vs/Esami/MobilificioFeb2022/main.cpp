#include "Mobilificio.h"
#include<iostream>
#include<list>

int main(){
    Mobilificio myList;
    Rotondo t1(142, "Betulla", "Ikea", 72.50, 50);
    Rettangolo t2(133, "Quercia", "Vinc&Co", 120.80, 120, 60);
    Triangolo t3(222, "Noce", "Maison du Vinz", 250, 170, 70);

    myList.insertTable(&t1);
    myList.insertTable(&t2);
    myList.insertTable(&t3);

    for(Tavolo *i: myList.getLista()){
        i->print();
    }

    std::cout<<myList.getLista().size();
    myList.summarizeWharehouse();
}