#include "bst.h"
#include<iostream>

int main(){
    BST<int> T;
    T.insert(10);
    T.insert(12);
    T.insert(4);
    T.inorderTreeWalk();
    std::cout<<"\n";
   // BSTNode<int> *root=getRoot();
    //T.deleteNode(4,12);
    //T.inorderTreeWalk();
    T.preorderTreeWalk();
    std::cout<<"\n";
    T.postorderTreeWalk();
}