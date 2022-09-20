#include <string.h>
#include<iostream>

class Account{
    public:
        Account(std::string accountName, int initialBalance)
            : name{accountName} {

                if(initialBalance > 0){
                    balance=initialBalance;
                }

            }

        void deposit(int depositAmount){
            if(depositAmount>0){
                balance = balance + depositAmount;
            }
        }

       void withdraw(int withdrawalAmount){
            if(withdrawalAmount>0){
                if(withdrawalAmount<=balance){
                    balance = balance - withdrawalAmount;
                }else{
                    std::cout<<"L'importo del prelievo supera il saldo del conto\n";
                }
            }else{
                std::cout<<"Cifra inserita non valida!\n";
            }
        }

        int getBalance() const{
            return balance;
        } 

        void setName(std::string accountName){
            name = accountName;
        }

        std::string getName() const{
            return name;
        }



    private:
        std::string name;
        int balance{0};       
};
