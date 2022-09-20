#include "DNode.h"
#include <iostream>
#include<sstream>
template <typename T>
class DLinkedList{
    public:
        DLinkedList();
        ~DLinkedList();
        bool empty() const;
        const T& front() const;
        const T& back() const;
        void addFront(const T& e);
        void addBack(const T& e);
        void removeFront();
        void removeBack();
        std::string toString();

        void bubblesort();
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
void DLinkedList<T>::bubblesort(){
    bool swapped{true};
    DNode<T>* curr; //primo elemento
    DNode<T>* last=nullptr; //tiene traccia di quanto dobbiamo muoverci
    if(empty()) return;
        do{
        curr=header->next;
        swapped=false;
        //scorri lista
        while(curr->next!=last){
            //confronta ogni elemento con il successivo
            //fino alla fine della lista
            if(curr->elem > curr->next->elem){
                std::swap(curr->elem, curr->next->elem);
                swapped=true;
            }
            curr=curr->next;
        }
        last=curr;
    }while(swapped);
}