
#ifndef NODE_H
#define NODE_H
#include<iostream>

//definiamo qui la lista così può essere dichiarata come friend
template<typename NODETYPE> class LinkedList;

template<typename NODETYPE>
class Node{
    private:
    NODETYPE elem; //elemento del nodo
    Node<NODETYPE>* next; //puntatore al prossimo elemento

    friend class LinkedList<NODETYPE>;
};
#endif