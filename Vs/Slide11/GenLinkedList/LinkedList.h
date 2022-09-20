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
        void print();
        const NODETYPE& front() const; //return front element
        void addFront(const NODETYPE& e); //add to front of list
        void removeFront(); //remove front item list
        void printFront(LinkedList<NODETYPE>& L); //stampa il front
        void addBack(const NODETYPE& e); //add to back of the list
        int size(); //gives the size of Linked List
        const NODETYPE& operator [](int i); // returns the ith element of the list
        int search(const NODETYPE& e);//trova l'elemento e restituisce la pos
        void reversal(); //reverse the linked list
        std::string toString() const;
        void deleteElem(const NODETYPE& e); //elimina elemento alla posizione n
        void swapElem(const NODETYPE& e1, const NODETYPE& e2);
        void pairwiseSwap(); //scambia elementi in posizione pari con elementi in pos dispari
        
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
        p1=list.head->next; //il nuovo nodo punta al next della testa
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
int LinkedList<NODETYPE>::search(const NODETYPE& e){
    Node<NODETYPE>* v= head;
    int i=0;
    while(v != nullptr){
        if(v->elem == e){
            return i+1;
        }
        ++i;
        v=v->next;
    }
    std::cout<<"Elemento non trovato!"<<std::endl;
    return -1;
}
template<typename NODETYPE>
void LinkedList<NODETYPE>::reversal(){
    Node<NODETYPE> *prev{nullptr};
    Node<NODETYPE> *curr{head};
    Node<NODETYPE> *temp;
    while(curr != nullptr){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
}
/*
template<typename NODETYPE>
void LinkedList<NODETYPE>::reversal(){
    Node<NODETYPE>* curr, *prev, *next;
    curr=head;
    prev=nullptr;
    while(curr != nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;        
    }
    head=prev;
}*/

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
//operatore di assegnazione per la Rule of Three
template<typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::operator=(const LinkedList<NODETYPE>& ll){
    if(this== &ll){
        return *this;
    }else{
            Node<NODETYPE>*cursor{ll.head};
            while(cursor!=nullptr){
                addFront(cursor->elem);
                cursor=cursor->next;
            }
        } 
    return *this;
}
/*
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
}*/


template <typename NODETYPE>
void LinkedList<NODETYPE>::print(){
	Node<NODETYPE>*c = head;
	if(empty()) std::cout << "\n VUOTO \n";
	else
	{
		while(c != nullptr){
			std::cout <<c->elem << " <-- ";
			c = c->next;
		}
		std::cout << " 0 \n";
	}
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::deleteElem(const NODETYPE& e){
    int n=search(e);
    Node<NODETYPE>* tmp1=head; //tmp1 punta al nodo puntato da head
    if(n==1){//se voglio eliminare l'elemento alla prima posizione
        head=tmp1->next; //head punta al secondo nodo
        delete tmp1;
        return;
    }
    for(int i=0; i<n-2; i++){ //devo arrivare al nodo n-1
        tmp1=tmp1->next;//temp1 punta al nodo in posizione n-1
    }
    Node<NODETYPE>* tmp2=tmp1->next; //tmp2 punta al nodo in pos n
    tmp1->next=tmp2->next; //nodo n-1 punta al nodo n+1
    delete tmp2; //eliminiamo il nodo n
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::swapElem(const NODETYPE& e1,const NODETYPE& e2){
    if(e1==e2) return; //se i due elemento sono uguali non c'è nulla da fare

    //cerchiamo e1, tenendo traccia di prev e curr
    Node<NODETYPE>* prevE1{nullptr};
    Node<NODETYPE>* currE1=head;
    while (currE1 != nullptr && currE1->elem!=e1){
        prevE1=currE1;
        currE1=currE1->next;
    }
    //cerchiamo e2
    Node<NODETYPE>* prevE2{nullptr};
    Node<NODETYPE>* currE2=head;
    while(currE2 != nullptr && currE2->elem!=e2){
        prevE2=currE2;
        currE2=currE2->next;
    }

    //se e1 o e2 non sono presenti non c'è nulla da fare
    if(currE1==nullptr || currE2==nullptr) return;

    //se e1 non è in testa alla linkedlist
    if(prevE1 != nullptr){
        prevE1->next=currE2;
    }else{
        head=currE2; //e2 nuova testa
    }

    //se e2 non è in testa alla linked
    if(prevE2 != nullptr){
        prevE2->next=currE1;
    }else{
        head=currE1;
    }

    //swapp i next pointers
    Node<NODETYPE>* temp=currE2->next;
    currE2->next=currE1->next;
    currE1->next=temp;
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::pairwiseSwap(){
    Node<NODETYPE>* curr{head};
    Node<NODETYPE>* next{nullptr};

    int disp{size()%2};
    if(disp==1){
        throw std::invalid_argument("Numero elementi dispari, aggiungere un nuovo numero");
    }
    while(curr!=nullptr){
        next=curr->next;
        NODETYPE temp;
        temp=curr->elem;
        curr->elem=next->elem;
        next->elem=temp;

        curr=curr->next->next;
    }
}
