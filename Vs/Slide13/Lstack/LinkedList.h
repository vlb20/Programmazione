#include "Node.h"
#include <iostream>
#include<sstream>
#include<string>

template <typename NODETYPE>
class LinkedList{
    public:
        LinkedList(); //empty list costructor
        ~LinkedList();//destructor
        LinkedList(const LinkedList<NODETYPE>& list);//copyconstructor
        LinkedList<NODETYPE>& operator=(const LinkedList<NODETYPE> &lhs);
        bool empty() const; //is list empty?
        const NODETYPE& front() const; //return front element
        void addFront(const NODETYPE& e); //add to front of list
        void removeFront(); //remove front item list
        void printFront(LinkedList<NODETYPE>& L); //stampa il front
        void addBack(const NODETYPE& e); //add to back of the list
        int size(); //gives the size of Linked List
        const NODETYPE& operator [](int i); // returns the ith element of the list
        bool search(const NODETYPE& e);//trova se c'è l'elemento
        void reversal(); //reverse the linked list
        std::string toString() const;
        
    private:
        Node<NODETYPE>* head; //head of list
};

template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList() 					//constructor
	: head(nullptr) {}

template<typename NODETYPE>
LinkedList<NODETYPE>::LinkedList(const LinkedList<NODETYPE>& list){ //copyconstructor
    Node<NODETYPE>* p1=nullptr;
    if(list.head == nullptr){
        head=nullptr;
    }else{
        head= new Node<NODETYPE>;
        head->elem=list.head->elem;
        p1=list.head->next;
    }
    while(p1 != nullptr){
        addback(p1->elem);
        p1=p1->next;
    }
}


template<typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const{
    return head==nullptr;
}

template<typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::front() const{
    return head->elem;
}

template<typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList(){
    while(!empty()){
        removeFront();
    }
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE& e){
    Node<NODETYPE>* v=new Node<NODETYPE>;
    v->elem=e;
    v->next=head;
    head=v;
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::removeFront(){
    if(head==nullptr){
        throw std::invalid_argument{"List is empty"};
    }
    Node<NODETYPE>* old= head;
    head=old->next;
    delete old;
}

template<typename NODETYPE>
void printFront(LinkedList<NODETYPE>& L){
            std::cout<<L.front()<<"\n";
}

template<typename NODETYPE>
int LinkedList<NODETYPE>::size(){
    int count=0;
    Node<NODETYPE>* i=head;
    if(head !=nullptr){
        do{
            count++;
            i=i->next;
        }while(i != nullptr);
    }
    return count;
}

template<typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::operator[](int i){
    if(i>0 && i<size()){
        Node<NODETYPE>* x=head;
        for(int j=0; j<i; j++){
            x=x->next;
        }
        return x->elem;
    }
    else{
        throw std::invalid_argument("L'elemento non è valido");
    }
}

template<typename NODETYPE>
bool LinkedList<NODETYPE>::search(const NODETYPE& e){
    Node<NODETYPE>* v= head;
    while(v != nullptr){
        if(v->elem == e){
            return true;
        }
        v=v->next;
    }
    return false;
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::reversal(){
    Node<NODETYPE>* curr, prev, next;
    curr=head;
    prev=nullptr;
    next=nullptr;
    while(curr != nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;        
    }
    head=prev;
}

template<typename NODETYPE>
std::string LinkedList<NODETYPE>::toString() const{
    std::ostringstream out;
    Node<NODETYPE>* cursor=head;
    if(empty()){
        out << "\nLista vuota!\n";
    }else{
        while(cursor != nullptr){
            out<<cursor->elem<<"-->";
            cursor=cursor->next;
        }
        out<<"0"; //estetico
    }
    return out.str();
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::addBack(const NODETYPE& e){
    Node<NODETYPE>* v= new Node<NODETYPE>;
    v->elem=e;
    if(!empty()){
        Node<NODETYPE>* n=head;
        while(n->next != nullptr){
            n=n->next;
        }
        n->next=v;
        v->next=nullptr;
    }
}

template<typename NODETYPE>

LinkedList<NODETYPE>& LinkedList<NODETYPE>::operator=(const LinkedList<NODETYPE> &lhs) {
	if (&lhs != this) {	//checks if the current list is different from the lhs
        Node<NODETYPE>* tmp= lhs.head; //salva la testa dell'altra lista
    

        while(!empty()){
            removeFront(); //cancello gli elementi della vecchia lista;
        }

        while(tmp != nullptr){ //giving the elements from the other list
            addBack(tmp->elem);
            tmp=tmp->next;
        }
    }
    return *this;
}