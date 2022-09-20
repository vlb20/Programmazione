/*• A palindrome is a number or a text phrase that reads the
same backward as forward. For example, each of the
following five-digit integers is a palindrome: 12321,
55555, 45554 and 11611. Write a program that reads in a
five-digit integer and determines whether it’s a
palindrome.*/


#include<iostream>
#include<string.h>

using std::cin;
using std::cout;
using std::endl;

bool isPalindrome(unsigned int seq[], int len);

bool isPalindrome(unsigned int seq[],int len){
    bool answer{true};
    int i{0};
    while(i<len/2){
        if(seq[i]!=seq[len-i-1]){
            answer=false;
        }
        i++;
    }
    return answer;
}
int main(){
    unsigned int num{0};
    unsigned int nDigits{0};
    unsigned int digits[20];

    cout<<"Inserisci il numero:";
    cin>>num;
    while(num!=0){
        digits[nDigits]=num%10;
        num/=10;
        nDigits++;
    }

    if (isPalindrome(digits,nDigits)){
        cout<<"Il numero e' palindromo";
       }else{
        cout<<"Il numero non e' palindromo";
       }
}





/*
int main(){
    int n1, n2, n3, n4, n5;
    bool pal{true};

    cout<<"Cifra 1:";
    cin>>n1;
    cout<<"Cifra 2:";
    cin>>n2;
    cout<<"Cifra 3:";
    cin>>n3;
    cout<<"Cifra 4:";
    cin>>n4;
    cout<<"Cifra 5:";
    cin>>n5;

    if (n1==n5){
        if(n2==n4){
             pal=true;
        }
    }
    else{
        pal=false;
    }

    if(pal=true){
        cout<<"La sequenza e' palindroma";

    }else if(pal=false){
        cout<<"La sequenza non e' palindroma";
    }

    return 0;*/
    
    





    


