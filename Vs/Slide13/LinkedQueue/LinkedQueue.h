#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include <iostream>
#include <stdexcept>
#include "CLinkedList.h"
template<typename E>
class LinkedQueue{
    public:
        LinkedQueue();
        int size() const;
        bool empty() const;
        const E& front();
        void enqueue(const E& e); //inserisce l'oggetto al fondo della coda
        void dequeue(); //rimuove l'oggetto dalla testa della coda
    private:
        CircleList<E> C;
        int n;
};

template<typename E>
LinkedQueue<E>::LinkedQueue()
    :C(), n{0} {}

template<typename E>
int LinkedQueue<E>::size() const{
    return n;
}

template<typename E>
bool LinkedQueue<E>::empty() const{
    return n==0;
}

template<typename E>
const E& LinkedQueue<E>::front(){
    if(empty()){
        throw std::runtime_error("front of empty queue");
    }
    return C.front(); //list front is queue front
}

template<typename E>
void LinkedQueue<E>::enqueue(const E& e){
    //enqueue element at rear
    C.add(e);   //inserisci dopo il cursore
    C.advance();//cursor=cursor->next
    n++; //aumenta il size
}

template<typename E>
void LinkedQueue<E>::dequeue(){
    //dequeue element at front
    if(empty()){
        throw std::runtime_error("dequeue of empty queue");
    }
    C.remove(); //remove from list front(nodo dopo il cursore)
    n--; 
}

#endif