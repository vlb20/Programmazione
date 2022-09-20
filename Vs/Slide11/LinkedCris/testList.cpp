#include<iostream>
#include<string>
#include"LinkedList.h"
using std::string;
using std::cout;
using std::endl;

template<typename T>
void printFront(LinkedList<T>& L);

int main(){
    LinkedList<int> L;
    L.addFront(22);
    L.addFront(5);
    L.addFront(20);
    L.addFront(6);
    L.addFront(21);
    cout<<"La lista inizializzata e':"<<endl;
    cout<<L.toString()<<endl;
    system("Pause");
    L.reverse();
    cout<<L.toString()<<endl;


    LinkedList<int> L1;
    L1=L;
    L1.reverse();
    cout<<"La lista rovesciata e':"<<endl;
    cout<<L1.toString()<<endl;
    system("Pause");

    cout<<"Dov'e' VLB?\n"<<L1.search(20)<<endl;
    
    /*L1.deleteelem(21);
    cout<<"La lista aggiornata e':"<<endl;
    cout<<L1.toString()<<endl;
    system("Pause");*/

    LinkedList<int> L2;
    L2=L;
    cout<<"La lista di interi e':"<<endl;
    cout<<L2.toString()<<endl;
    L2.swap();
    cout<<L2.toString()<<endl;


}

template<typename T>
void printFront(LinkedList<T>& L){
    cout<<L.front()<<"\n";
}