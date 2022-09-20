#include<iostream>
#include"LStack.h"

int main(){
    LinkedStack<std::string> myStack;
    myStack.push("one");
    myStack.push("two");
    myStack.push("three");
    std::cout<<"Size:"<<myStack.size()<<std::endl;
    std::cout<<myStack.top()<<std::endl;
    myStack.pop();
    std::cout<<myStack.top()<<std::endl;
    myStack.pop();
    std::cout<<myStack.top()<<std::endl;
    myStack.pop();
}