#include<iostream>
#include<string.h>

using std::cin;
using std::cout;
using std::endl;

bool isPalindromeRec(unsigned int seq[],int left, int right); 

bool isPalindromeRec(unsigned int seq[], int left, int right){
    if(left<right){
        return seq[left]==seq[right] && isPalindromeRec(seq,left+1,right-1);
    }
    else{
        return true;
    }
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

    if (isPalindromeRec(digits,0,nDigits-1)){
        cout<<"Il numero e' palindromo";
       }else{
        cout<<"Il numero non e' palindromo";
       }
       return 0;
}

