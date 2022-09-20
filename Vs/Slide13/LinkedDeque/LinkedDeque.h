#include "DLinkedList.h"

template <typename T>
class LinkedDeque{
    public:
        LinkedDeque();
        int size() const;
        bool empty() const;
        const T& front();
        const T& back();
        void insertFront(const T& e);
        void insertBack(const T& e);
        void removeFront();
        void removeBack();
    private:
        DLinkedList<T> D;
        int n;
};

template<typename T>
void LinkedDeque<T>::insertFront(const T& e){
    D.addFront(e);
    n++;
}

template<typename T>
void LinkedDeque<T>::insertBack(const T& e){
    D.addBack(e);
    n++;
}

template<typename T>
void LinkedDeque<T>::removeFront(){
    if(empty()){
        throw std::runtime_error("deque empty");
    }
    D.removeFront();
    n--;
}

template<typename T>
void LinkedDeque<T>::removeBack(){
    if(empty()){
        throw std::runtime_error("deque empty");
    }
    D.removeBack();
    n--;
}

template<typename T>
int LinkedDeque<T>::size() const{
    return n;
}

template<typename T>
bool LinkedDeque<T>::empty() const{
    return n==0;
}

template<typename T>
const T& LinkedDeque<T>::front() {
    if(empty()){
        throw std::runtime_error("Deque empty");
    }
    return D.front();
}

template<typename T>
const T& LinkedDeque<T>::back(){
    if(empty()){
        throw std::runtime_error("Deque empty");
    }
    return D.back();
}