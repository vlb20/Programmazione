#include<iostream>
#include"Account.h"

using std::cin;
using std::cout;

int main(){
    Account account1{"Damiano Bruno", 1800};
    Account account2{"Vincenzo Luigi Bruno", 250};

    cout<< "Conto 1:"<< account1.getName()<< "--> il bilancio e'"<< " " <<account1.getBalance()<<" "<<"euro"<<std::endl;
    cout<< "Conto 2:"<< account2.getName()<< "--> il bilancio e'"<< " " <<account2.getBalance()<<" "<<"euro"<<std::endl;

    cout<<"Deposita euro per il conto di Damiano:\n";
    int depositAmount;
    cin >> depositAmount;
    cout << "aggiunti"<<" "<<depositAmount<<" "<<"euro al conto di Damiano"<<std::endl;
    account1.deposit(depositAmount);

    cout<<"Deposita euro per il conto di Vincenzo:\n";
    int depositAmount1;
    cin >> depositAmount1;
    cout << "aggiunti"<<" "<<depositAmount1<<" "<<"euro al conto di Vincenzo"<<std::endl;
    account2.deposit(depositAmount1);

    cout<< "Conto 1:"<< account1.getName()<< "--> il bilancio e' "<<" "<< account1.getBalance()<<" "<<"euro"<<std::endl;
    cout<< "Conto 2:"<< account2.getName()<< "--> il bilancio e' "<<" "<< account2.getBalance()<<" "<<"euro"<<std::endl;

    cout<<"Prelievo dal conto di Damiano:\n";
    int withdrawalAmount1;
    cin >> withdrawalAmount1;
    account1.withdraw(withdrawalAmount1);
    cout<< "Conto 1:"<< account1.getName()<< "--> il bilancio e' "<<" "<< account1.getBalance()<<" "<<"euro"<<std::endl;


    

}