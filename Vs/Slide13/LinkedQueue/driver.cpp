#include<iostream>
#include<string>
#include"LinkedQueue.h"

int main(){
    LinkedQueue<int> Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    std::cout<<"Size:"<<Q.size()<<std::endl;
    std::cout<<Q.front()<<std::endl;
    Q.dequeue();
    std::cout<<Q.front()<<std::endl;
    Q.dequeue();
    std::cout<<Q.front()<<std::endl;
    Q.dequeue();
    std::cout<<"Size:"<<Q.size()<<std::endl;
    return 0;
}