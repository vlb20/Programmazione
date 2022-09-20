/*n this exercise you’ll investigate a simple scheme for
encrypting and decrypting data. A company that wants to send
data over the In-ternet has asked you to write a program that
will encrypt the data so that it may be transmitted more
securely. All the data is transmitted as four-digit integers.
Your application should read a four-digit integer entered by the
user and encrypt it as follows: Replace each digit with the
result of adding 7 to the digit and getting the remainder after dividing the new value by 10. Then swap the first digit with the
third, and swap the second digit with the fourth. Then print the
encrypted integer. Write a separate application that inputs an
encrypted four-digit integer and decrypts it (by reversing the
encryption scheme) to form the original number.

#include<iostream>

using std::cout;
using std::cin;

int main(){
    int n1,n2,n3,n4;
    
    
    cout<<"Inserisci cifra 1:";
    cin>>n1;
    n1=n1+7;
    n1=n1%10;
    cout<<"\n"<<n1;

    cout<<"\nInserisci cifra 2:";
    cin>>n2;
    n2=n2+7;
    n2=static_cast<int>(n2)%10;
    cout<<n3;
    
    cout<<"\nInserisci cifra 3:";
    cin>>n3;
    n3=n3+7;
    n3=static_cast<int>(n3)%10;
    cout<<n3;

    cout<<"\nInserisci cifra 4 :";
    cin>>n4;
    n4=n4+7;
    n4=static_cast<int>(n4)%10;
    cout<<n4;
    
    float temp1;
    n1=temp1;
    n1=n3;
    n3=temp1;

    float temp2;
    n2=temp2;
    n2=n4;
    n4=temp2;

    cout<<"La sequenza criptata e':"<<n1<<" "<<n2<<" "<<n3<<" "<<n4;

    
    

    return 0;
}*/
#include <iostream>
#include <stdlib.h>
#include <math.h>

using std::cin;
using std::cout;
using std::string;
using std::endl;

void positioning(int array[]);
void encrypt(int array[]);
void decrypt(int array[]);
void swap(int &n1, int &n2);
void print(int array[]);

int main(){
    int array[4];
    int option = 0;
    while(option != -1){
        do{
            cout <<"*******MENU******* \n select an option \n press 1 to encrypt \n press 2 to decrypt \n press -1 to quit \n ";
            cin >> option;
        }while(option <-1 || option >2);
        
        switch (option)
        {
        case 1:
            positioning(array);
            encrypt(array);
            cout <<"the output number is ";
            print(array);
            break;
        
        case 2:
            positioning(array);
            decrypt(array);
            cout <<"the output number is ";
            print(array);
            break;

        default:
            cout <<"exiting... ";
        }
        

    } 
}

int power(int base, int exp){
    if(exp == 0)return 1;
    else
    return base * pow(base, exp-1);
}
void swap(int &n1, int &n2){
    int change;
    change=n1;
    n1=n2;
    n2=change;
}
void positioning(int array[]){
    for(int i=0; i<4;i++){
        cout <<"inserting the " <<i<<" digit ";
        cin >> array[i];
    }
    cout << "the input number is ";
    print(array);
}
void encrypt(int array[]){
    cout << "encrypting the number ... \n";
    swap(array[1], array[3]);
    swap(array[0], array[2]);
     for(int i=0; i<4;i++){
        array[i]=(array[i]+7)%10; 
    }
}
void decrypt(int array[]){
    cout <<"decrypting the number ... \n";
    swap(array[1], array[3]);
    swap(array[0], array[2]);
    for(int i=0; i<4;i++){
        array[i]=((array[i]+3) %10);
    }
}
void print(int array[]){
    for (int i = 0; i < 4; i++)
    {
       cout << array[i]<<" ";
    }
    cout << "\n ";
    
}

