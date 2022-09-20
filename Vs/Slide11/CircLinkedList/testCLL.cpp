#include<iostream>
#include"CLinkedList.h"
using std::string;
using std::cout;
int main(){
    CircleList<std::string> playList;
    cout<<"Salve, questa e' la tua playList"<<std::endl;
    playList.add("Feel Good Inc.");
    playList.add("The Adults Are Talking");
    playList.add("Stan");
    playList.add("Come e quando");
    playList.advance();
    playList.advance();
    cout<<playList.toString()<<std::endl;
    playList.remove();
    playList.add("Let There Be Love");
    cout<<playList.toString()<<std::endl;
    return 0;
}