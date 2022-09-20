/*• Write a program that takes in input an integer number in
base 10 and outputs it’s representation in binary*/
#include<iostream>
#include<iomanip>

using std::cin;
using std::cout;

int main(){
    int num;
    short int rapprBinaria[32];
    int cifra{0};

    cout<<"Inserisci il numero da convertire:";
    cin>>num;

    while(num!=0){
        if (num%2==1)
        {
            rapprBinaria[cifra]=1;
        }else{
            rapprBinaria[cifra]=0;
        }
        
        num=num/2;
        cifra++;
    
    }
    int i=cifra-1;
    cout<<"Il numero convertito e':"<<std::endl;
    while(i>=0){
        cout<<rapprBinaria[i];
        --i;
    }

  /*  int i=cifra-1;
    while(i>=0){
        cout<<std::setw(1)<< rapprBinaria[1];
        --i;

    }*/
    return 0;


}