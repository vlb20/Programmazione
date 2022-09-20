#include<iostream>
#include"Account2.h"

using std::cout;
using std::endl;

int main(){
    Account acc{1000.0};
    acc.credit(1000.0);
    acc.debit(100.0);
    cout<<"Account balance is: $"<<acc.getBalance()<<endl;

    CheckingAccount checking(1000.0, 2.00);
    checking.credit(1000.0);
    checking.cashWithdrawal(100.0);
    cout<<"Checking balance is: $"<<checking.getBalance()<<endl;
    cout<<"Checking total fees is: $"<<checking.getTotalFees()<<endl;

    SavingsAccount saving(1000.0, 0.05);
    saving.credit(1000.0);
    cout<<"Savings balance is: $"<<saving.getBalance()<<endl;

    return 0;
}