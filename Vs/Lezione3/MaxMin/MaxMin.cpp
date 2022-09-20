/*The process of finding the maximum and minimum number
(i.e., the maximum of a group of numbers) of a sequence
give in input.
• Use 0 as sentinel variable*/

#include<iostream>
#include<string>
using std::cin;
using std::cout;

int main(){

    float num{0};
    float max{0};
    float min{0};
    cout<<"Inserisci numeri-Per terminare inserire 0:\n";
    cin>>num;
    min=num;
    while(num!=0){
        
        if(num>=max){
            max=num;
        }else if(num<=min){
            min=num;
        }

        cout<<"Inserisci numero:";
        cin>>num;

    }

    cout<<"\nIl max e':"<<max;
    cout<<"\nIl min e':"<<min;

}

