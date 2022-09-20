#include<iostream>
#include"DLinkedList.h"

int main(){
    DLinkedList<std::string> L;
    L.addFront("ORD");
    L.addFront("JFK");
    L.addFront("SCO");
    L.addBack("SFO");
    std::cout<<L.toString()<<std::endl;

    std::cout<<"Rimuovo l'ultimo elemento...\n";
    L.removeBack();
    std::cout<<L.toString()<<std::endl;

    std::cout<<"Rimuovo il primo elemento...\n";
    L.removeFront();
    std::cout<<L.toString()<<std::endl;
    
    DLinkedList<std::string> L1;
    L1=L;
    std::cout<<L1.toString()<<std::endl;
}