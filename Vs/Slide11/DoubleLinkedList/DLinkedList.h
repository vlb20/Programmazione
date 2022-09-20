#include "DNode.h"
#include <iostream>
#include<sstream>
template <typename T>
class DLinkedList{
    public:
        DLinkedList();
        ~DLinkedList();
        DLinkedList(const DLinkedList<T>& D);//copyconstructor
        bool empty() const;
        const T& front() const;
        const T& back() const;
        void addFront(const T& e);
        void addBack(const T& e);
        void removeFront();
        void removeBack();
        std::string toString();
        DLinkedList<T>& operator=(const DLinkedList<T>& dl);
    private:
        DNode<T>* header;
        DNode<T>* trailer;
    protected:
        void add(DNode<T>* v, const T& e);
        void remove(DNode<T>* v);
};

template<typename T>
DLinkedList<T>::DLinkedList(){
    header=new DNode<T>;
    trailer=new DNode<T>;
    header->next=trailer;
    header->prev=nullptr;
    trailer->prev=header;
    trailer->next=nullptr;
}

template<typename T>
DLinkedList<T>::~DLinkedList(){
    while(!empty()){
        removeFront();
    }
    delete header;
    delete trailer;
}

template<typename T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& D){
    if(D.header==nullptr){
        header=trailer=nullptr;
    }

    //inizializzo Lista
    header=new DNode<T>; //creo nodi sentinella
    trailer=new DNode<T>;
    header->next=trailer; //faccio in modo che i nodi si puntino l'un l'altro
    header->prev=nullptr;
    trailer->next=nullptr;
    trailer->prev=header;

    DNode<T>* cursor{D.header->next};
    T e;
    while(cursor!=trailer){
        e=cursor->elem;
        addFront(e);
        cursor=cursor->next;
    }
}

template<typename T>
bool DLinkedList<T>::empty() const{
    return (header->next==trailer); //se testa e coda sono consecutivi la lista è vuota
}

template<typename T>
const T& DLinkedList<T>::front() const{
    return header->next->elem;
}

template<typename T>
const T& DLinkedList<T>::back() const{
    return trailer->prev->elem;
}

template<typename T>
void DLinkedList<T>::add(DNode<T>* v, const T& e){
    DNode<T>* u= new DNode<T>; //creo un nuovo nodo per l'elemento
    u->elem=e;  

    u->next=v; //nodo deve puntare a v;
    u->prev=v->prev; //prev di u punta al prev di v (u deve prendere il posto di v)
    v->prev->next= u; //u puntato dal next del prev di v
    v->prev=u;
}//se la lista è vuota passiamo trailer

template<typename T>
void DLinkedList<T>::addFront(const T& e){
    add(header->next, e); //sposto il primo nodo cosi' da fare spazio
}

template<typename T>
void DLinkedList<T>::addBack(const T& e){
    add(trailer, e); //sposto il trailer così da far spazio
}

template<typename T>
void DLinkedList<T>::remove(DNode<T>* v){ //remove nodo v
    if(empty()){
        throw std::runtime_error("The list is empty");
    }
    DNode<T>* u=v->prev;
    DNode<T>* w=v->next;
    u->next=w;
    w->prev=u;
    delete v;
}

template<typename T>
void DLinkedList<T>::removeFront(){
    remove(header->next);
}

template<typename T>
void DLinkedList<T>::removeBack(){
    remove(trailer->prev);
}

template<typename T>
std::string DLinkedList<T>::toString(){
    std::ostringstream out;
    DNode<T>* u=header->next;
    out<<"Header<-->";
    while(u!=trailer){
        out<<u->elem<<"<-->";
        u=u->next;
    }
    out<<"Trailer";
    return out.str();
}

template<typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& dl){
    if((&dl==this)){
        return *this;
    }else{
            DNode<T>* cursor=dl.header->next;
            while(cursor != dl.trailer){
            addBack(cursor->elem);
            cursor=cursor->next;
        }
    }
}