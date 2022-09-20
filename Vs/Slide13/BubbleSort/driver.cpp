#include<iostream>
#include"DLinkedList.h"

int main(){
    DLinkedList<int> list;
    list.addFront(1);
    list.addBack(7);
    list.addBack(4);
    list.addBack(10);
    list.addBack(3);
    std::cout<<"Lista non ordinata: "<<list.toString()<<std::endl;
    list.bubblesort();
    std::cout<<"Lista ordinata tramite bubblesort: "<<list.toString()<<std::endl;
}