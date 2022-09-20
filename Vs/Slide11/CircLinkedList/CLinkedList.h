#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include<iostream>
#include<sstream>
#include"CNode.h"

template<typename T>
class CircleList{
public:
    CircleList(); //costruttore
    ~CircleList();
    bool empty() const;
    const T& front() const;
    const T& back() const;
    void advance();
    void add(const T& e);
    void remove();
    std::string toString();
private:
    CNode<T>* cursor;
};

template<typename T>
CircleList<T>::CircleList()
    : cursor{nullptr} { }

template<typename T>
CircleList<T>::~CircleList(){
    while(!empty()){
        remove();
    }
}

template<typename T>
bool CircleList<T>::empty() const{
    return cursor==nullptr;
}

template<typename T>
const T& CircleList<T>::back() const{
    return cursor->elem;
}

template<typename T>
const T& CircleList<T>::front() const{
    return cursor->next->elem;
}

template<typename T>
void CircleList<T>::advance(){
    cursor=cursor->next;
}

template<typename T>
void CircleList<T>::add(const T& e){ //add after cursor
    CNode<T>* v=new CNode<T>;
    v->elem=e;
    if(cursor==nullptr){
        v->next=v;  //v punta a se stesso
        cursor=v;   //cursor punta a v
    }else{
        v->next=cursor->next; //linko v dopo il cursore
        cursor->next=v;
    }
}

template<typename T>
void CircleList<T>::remove() { //rimuovi nodo dopo il cursore
    CNode<T>* old=cursor->next;//nodo che deve essere rimosso
    if(old==cursor){ //rimuovi l'unico nodo?
        cursor=nullptr;
    }else{
        cursor->next=old->next; 
        delete old;
    }
}

template<typename T>
std::string CircleList<T>::toString(){
    std::ostringstream out;
    CNode<T>* u=cursor;
    out<<"Cursor--> ";
    out << u->elem <<" --> ";
    u=u->next;
    while(u!=cursor){
        out<<u->elem<<" --> ";
        u=u->next;
    }
    out<<"Cursor";
    return out.str();
}


#endif