#ifndef ACCOUNT2_H
#define ACCOUNT2_H
#include<iostream>

class Account{
    public:
    Account(): balance{0.0} {}
    Account(double initial) : balance{initial}{}

    void credit(double amt){
        balance+=amt;
    }
    void debit(double amt){
        balance-=amt;
    }
    double getBalance() const{
        return balance;
    }

    private:
    double balance;
};

class CheckingAccount : public Account{

    public:
        CheckingAccount(double initial, double atm) 
            : Account(initial), totalFees{0.0}, atmFee{atm} {}

        void cashWithdrawal(double amt){
            totalFees+=atmFee;
            debit(amt + atmFee);
        }

        double getTotalFees() const {
            return totalFees;
            }
        std::string type() const{
            return "Checking Account";
            }
    private:
        double totalFees;
        double atmFee;        
};

class SavingsAccount : public Account{
    public:
        SavingsAccount(double initial, double rate)
            : Account(initial), annualRate{rate} {}
        double totalAfterYears(int years) const;    
    private:
        double annualRate;
};

#endif