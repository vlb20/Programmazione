#include "Node.h"//reindirizza a Node template
#include<iostream>
#include<sstream>
using std::cout;
using std::endl;

template<typename NODETYPE>
class LinkedList{               //una singola lista concatenata
    public:
        //costruttori
        LinkedList();                   //costruttore
        LinkedList(const LinkedList& ll);//copy constructor
        ~LinkedList();                  //distruttore

        //default member function
        bool empty() const;             //verifica se la lista è vuota
        const NODETYPE& front() const;  //da come ritorno in nodo il testa
        void addFront(const NODETYPE& e); //aggiungi alla testa
        void removeFront();               //rimuovi un elemento dalla lista
        
        //member function assegnate
        int size();                       //da in uscita il numero di elementi della lista
        LinkedList<NODETYPE>& operator=(const LinkedList<NODETYPE>& ll);//Rule of Three
        NODETYPE& operator[](int i);//da in uscita l'i-esimo elemento della lista
        int search(const NODETYPE& e);    //in uscita ho la posizione dell'elemento cercato
        void deleteelem(const NODETYPE& e);//cancelliamo un nodo dalla lista in base all'elemnto che contiene
        void reverse();                  //invertiamo la lista senza un copy constructor
        std::string toString();
        void swap();                     //invertiamo nodi pari con nodi dispari
        

    private:
        Node<NODETYPE>* head;
};

//Implementiamo la lista in modo generico, cioè in modo che l'elemento possa essere di qualunque tipo attraverso template

//costruttore
template<typename NODETYPE>
LinkedList<NODETYPE>::LinkedList()
    :head(nullptr){ }

//copy constructor
template<typename NODETYPE>
LinkedList<NODETYPE>::LinkedList(const LinkedList& ll):head{nullptr}{
    Node<NODETYPE>*cursor{ll.head};
    while(cursor!=nullptr){
        addFront(cursor->elem);
        cursor=cursor->next;
    }
}

//implementiamo il distruttore
template<typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList(){
    while(!empty())
        removeFront();
}

//emptylist
template<typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const{ return head==nullptr;}

//restituiamo l'elemento alla testa della lista
template<typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::front() const{ return head->elem; }


//aggiungiamo un nodo alla testa
template<typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE& e){
    Node<NODETYPE>* v=new Node<NODETYPE>;//creiamo un nuovo nodo 
    v->elem=e;//settiamo il valore
    v->next=head;//adesso la testa punta al nuovo nodo
    head=v;//v è la nuova testa
}

//rimuoviamo il nodo alla testa
template<typename NODETYPE>
void LinkedList<NODETYPE>::removeFront(){
    if(head==nullptr){
        throw std::invalid_argument{"List is empty"};
    }
    Node<NODETYPE>* old=head; //salviamo la testa corrente
    head=old->next;//modifichiamo il puntatore alla testa
    delete old; //deallochiamo il nodo precedentemente alla testa
}

//vediamo quanti elementi ci sono nella nostra lista
template<typename NODETYPE>
int LinkedList<NODETYPE>::size(){
        int size{0};
        Node<NODETYPE>* cursor{head};
        while(cursor!=nullptr){
            ++size;
            cursor=cursor->next;
        }
        return size;
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

//overloading puntatore,da in uscita l'i-esimo elemento della lista
template<typename NODETYPE>
NODETYPE& LinkedList<NODETYPE>::operator[](int i){
    if(i>=0 && i<=size()){
        Node<NODETYPE>* it{head};
        for(int j=0;j<size();j++){
            if(i==j){
                return it->elem;
            }
            it=it->next;
        }
    }else{
        throw std::invalid_argument{"L'elemento non è valido"};
    }
    
    
}


//implementiamo la funzione di ricerca
template<typename NODETYPE>
int LinkedList<NODETYPE>::search(const NODETYPE& e){
            Node<NODETYPE>* cursor=head;
            int i{0};
            while(cursor!=nullptr){
                if(cursor->elem==e){
                    return i+1;
                }
                ++i;
                cursor=cursor->next;
            }
            cout<<"Elemento non trovato!"<<endl;
            return -1;
        }

//voglio poter cancellare un nodo dato l'elemento ch contiene
template<typename NODETYPE>
void LinkedList<NODETYPE>::deleteelem(const NODETYPE& e){
        Node<NODETYPE>* cursor{head};
            while(cursor!=nullptr){
                    if(e==cursor->elem){
                        Node<NODETYPE>* old=cursor;
                        cursor=cursor->next;
                        delete old;
                        break;
                    }
                cursor=cursor->next;
            }
}
template<typename NODETYPE>
void LinkedList<NODETYPE>::reverse(){
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
//Soluzione di Ceccarelli
template<typename NODETYPE>
void LinkedList<NODETYPE>::reverse(){
    Node<NODETYPE>* prev{nullptr};
    Node<NODETYPE>* curr{head};
    Node<NODETYPE>* next{nullptr};
    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    //quando curr==nullptr siamo alla fine
    head=prev;
}*/

//Soluzione di Ceccarelli
template<typename NODETYPE>
std::string LinkedList<NODETYPE>::toString(){
    std::ostringstream out;
    Node<NODETYPE>* cursor{head};
    while(cursor!=nullptr){
        out<<cursor->elem<<"-->";
        cursor=cursor->next;
    }
    out<<"0";//elemento estetico
    return out.str();
}

//swap pari dispari
template<typename NODETYPE>
void LinkedList<NODETYPE>::swap(){
    Node<NODETYPE>* curr{head};
    Node<NODETYPE>* next{nullptr};
    Node<NODETYPE>* temp{nullptr};
    while(curr!=nullptr){
        next=curr->next;
        curr->next=next->next;
        next->next=curr;

        curr=curr->next;
    }
}