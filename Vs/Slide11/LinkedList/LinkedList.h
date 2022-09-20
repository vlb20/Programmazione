//LinkedList.h
//A generic LinkedList class template
#include "Node.h"
#include <iostream>

template<typename NODETYPE>
class LinkedList { 							// a singly linked list
	friend bool operator==(const LinkedList<NODETYPE> &lhs, const LinkedList<NODETYPE> &rhs);
	public:
		LinkedList();						//empty list constructor
		~LinkedList();						//destructor
		LinkedList(const LinkedList<NODETYPE> & lhs); 	// copy constructor;
	 	LinkedList<NODETYPE>& operator=(const LinkedList<NODETYPE> &lhs);
		bool empty() const;					//is list empty?
		const NODETYPE& front() const;			//return front element
		void addFront(const NODETYPE& e); 		//add to front of list
		void removeFront();						// remove front item list
		void reversal();						// reverse the LinkedList
		void print();							// print the element in the list
		void addBack(const NODETYPE& e); 		// add to back of the list
		int size(); 							//gives the size of the LinkedList
		//void add(const NODETYPE& e, Node<NODETYPE>* p);	//adding into the list giving the precedent node
		void addPosition(const NODETYPE& e, int i);		//adding into the list giving the position
		void addOrder(const NODETYPE& e);
		void addOrderVinc(const NODETYPE& e);
        bool find(const NODETYPE& e);
		std::string toString() const;
		const NODETYPE&	operator [](int i);		// returns the ith element of the list
	private:	
		Node<NODETYPE>* head; 				 //head of the list 
};

#include "LinkedList.cpp"
