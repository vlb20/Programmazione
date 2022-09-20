//LinkedList.cpp
//Implementation of the generic Linked List
//this file should be included in the client source file
//in order to avoid linking errors
#include <sstream>
template<typename NODETYPE>
LinkedList<NODETYPE>::LinkedList(const LinkedList<NODETYPE>& list) {
	Node<NODETYPE>* p1 = nullptr;
	if(list.head ==nullptr){head = nullptr;}
	else{
		head = new Node<NODETYPE>;
		head ->elem = list.head ->elem;		
		p1 = list.head->next;
	}
	while(p1 != nullptr){
		addBack(p1->elem);
		p1 = p1->next;
	}

}

template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList() 					//constructor
	: head(nullptr) {}
template <typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const 				// is list empty?
{ return head == nullptr; }

template <typename NODETYPE>
const NODETYPE & LinkedList<NODETYPE>::front() const 			//return front element
{return head -> elem; }

template <typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList() 					//destructor
{while(!empty() ) removeFront(); }

template <typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE &e) { 			//add to front of list
	Node<NODETYPE>* v = new Node <NODETYPE>;
	v-> elem = e;
	v-> next = head;
	head = v;
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::removeFront(){
	if(head == nullptr){
		throw std::invalid_argument("List is empty");
	}
	Node<NODETYPE>*old = head;					//save current head
	head = old -> next;						//skip over old head
	delete old;							//delete the old head
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::print(){
	Node<NODETYPE>*c = head;
	if(empty()) std::cout << "\n VUOTO \n";
	else
	{
		std::cout << "Header <--";
		while(c != nullptr){
			std::cout << " "<<c->elem << " <-- ";
			c = c->next;
		}
		std::cout << " trailer \n";
	}
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::addBack(const NODETYPE &e){
	Node<NODETYPE> *v = new Node<NODETYPE>; v->elem = e;
	if(!empty()){
		Node<NODETYPE> *n = head;
		while(n->next != nullptr){n= n->next;}
		n->next = v;
		v->next = nullptr;
	}
	else
	{
		head = v;
		head ->next = nullptr;
		
	}
	
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::reversal(){
	Node<NODETYPE> *current, *next, *prev; 		 //storing the current, the next and the previous node
	current = head;	//starting from the head of the pointer
	prev = nullptr;
	while(current != nullptr){
		next = current->next;		//placing the next node
		current->next = prev;		//the next node of the current one will be the previous
		prev = current;				//the previous node will be the current one
		current = next;				//the current node will be the next one
	}
	head = prev;					//the new head will be the prev.  at the end of the while, current and next will be nullptr
}



template <typename NODETYPE>
int LinkedList<NODETYPE>::size(){
	int count = 0;
	Node<NODETYPE> *i = head;
	if(head != nullptr){
		do{
			count++;
			i= i->next;
		}while(i != nullptr);
	}
	return count;
}

template <typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::operator[](int i){
	if(i>=0 && i < size()){
		Node<NODETYPE> *x = head;
		for(int j = 0; j<i; j++){ x = x->next ;}
		return x->elem;
	}
	else {
		throw std::invalid_argument("The given element is not valid");
	}
}
 
template<typename NODETYPE>

LinkedList<NODETYPE>& LinkedList<NODETYPE>::operator=(const LinkedList<NODETYPE> &lhs) {
	if (&lhs != this) {	//checks if the current list is different from the lhs
        Node<NODETYPE> *tmp = lhs.head; 	// stores the head of the other list

        while (!empty()) { 	 // deleting the element from the old list
            removeFront();
        }

        while (tmp != nullptr) {	//giving the elements from the other list
            addBack(tmp->elem);
            tmp = tmp -> next;
        }
    }

    return *this;
}
/*
template<typename NODETYPE>
void LinkedList<NODETYPE>::add(const NODETYPE& e, Node<NODETYPE>* p){
	Node<NODETYPE>* n = new Node<NODETYPE>;
	n->elem = e;
	n->next = p->next;
	p->next = n;
}
*/
template<typename NODETYPE>
void LinkedList<NODETYPE>::addPosition(const NODETYPE& e, int i){
	if(i == 0){addFront(e);}
	else if(i==size()-1){addBack(e);}
	else{
		Node<NODETYPE>* n = new Node<NODETYPE>;
		n->elem = e;
		Node<NODETYPE>* v = head;
		for(int j=0; j<i-1; j++){v=v->next;}
		n->next = v->next;
		v->next = n;

	}
	
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::addOrder(const NODETYPE& e){
    Node<NODETYPE>* u= new Node<NODETYPE>;
    if(empty()){
        head = u;
        head->next = nullptr;
    }
    else{
        Node<NODETYPE> * v = head;
        Node<NODETYPE> * p = nullptr;
        while (v != nullptr){
            if (u->elem < v->elem) break;
            p = v;
            v = v->next;      
        }
        if(p != nullptr){
            p->next = u;
            u->next = v;
        }
        else{
            u->next = head;
            head = u;
        }
    }

}
template<typename NODETYPE>
 bool operator==(const LinkedList<NODETYPE> &lhs, const LinkedList<NODETYPE> &rhs){
	if(lhs.size() != rhs.size())return false;
	Node<NODETYPE>* ln = lhs.head;
	Node<NODETYPE>* rn = rhs.head;
	while (ln != nullptr)
	{
		if(ln->elem != rn->elem){
			return false;
		}
		ln= ln->next;
		rn= rn->next;
	}
	return true;
	
}
template<typename NODETYPE>
bool LinkedList<NODETYPE>::find(const NODETYPE& e){
    Node<NODETYPE>* v = head;
    while(v != nullptr){
        if (v->elem == e){
            return true;
        }
        v=v->next;
    }
    return false;
}

template<typename NODETYPE>
std::string LinkedList<NODETYPE>::toString() const{
	std::ostringstream o;
	Node<NODETYPE>*c = head;
	if(empty()) o << "\n VUOTO \n";
	else
	{
		o << "Header <--";
		while(c != nullptr){
			std::cout << " "<<c->elem << " <-- ";
			c = c->next;
		}
		o << " trailer \n";
	}
	return o.str();
	
}

