/*Write a program that prints the Fibonacci sequence 0, 1, 1,
2, 3, 5, 8, etc. Use 0 and 1 as your seed values. Each
subsequent number in the Fibonacci sequence is the sum of
the previous two numbers. Your while loop should not
terminate (i.e., you should create an infinite loop). To do
this, simply use the keyword true as the expression for the
while statement. What happens when you run this program?*/

#include<iostream>
#include<string.h>

using std::cin;
using std::cout;

int main(){
    int n, prec, succ;

    //0 1 1 2 3
    do{
    cout<<"Scegli un numero tra 0 e 1:";
    cin>>n;
    }while(n==0&&n==1);

    
    prec=n;
    while(n!=0){
        succ=n;
        n+=prec;
        cout<<n<<" ";
        prec=succ;
    }
    return 0;

}