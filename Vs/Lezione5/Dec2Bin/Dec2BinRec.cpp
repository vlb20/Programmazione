#include<iostream>

using std::cin;
using std::cout;

std::string RecD2B(int num){
    if(num==0){
        return "0";
    }else{
        return RecD2B(num/2)+std::to_string(num%2);
    }
}

int main(){
    int num;
    cout<<"Inserisci sequenza da convertire:";
    cin>>num;
    cout<<"\nLa sequenza convertita e':"<<RecD2B(num);
    
}