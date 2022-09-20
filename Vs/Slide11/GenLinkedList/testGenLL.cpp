#include<iostream>
#include<string>
#include"LinkedList.h"

using std::string;
using std::cout;

int main(){
    LinkedList<int> L;
    L.addFront(20);
    L.addFront(10);
    L.addFront(2001);
    L.addFront(77);
    cout<<L.toString()<<std::endl;
    L.pairwiseSwap();
    cout<<L.toString()<<std::endl;
    cout<<"Elimina un elemento:";
    int e;
    std::cin>>e;
    L.deleteElem(e);
    cout<<"\nElemento eliminato---"<<L.toString()<<std::endl;
    L.reversal();
    cout<<L.toString()<<std::endl;
    L.swapElem(10,2001);
    cout<<L.toString()<<std::endl;

    LinkedList<int> L2;
    L2=L;
    L2.reversal();
    cout<<L.toString()<<std::endl;


}