//Node.h

template <typename NODETYPE> class LinkedList; 	// forward declaration of LinkedList
											//so it can be declared as a frinend class

template <typename NODETYPE> 
class Node{									// Singly linked list node 
	private:
		NODETYPE 	elem; 				// linked list element value
		Node<NODETYPE>* next; 				// nest item in the list
		
		friend class LinkedList<NODETYPE>; 	// provide SLinkedList access
};
