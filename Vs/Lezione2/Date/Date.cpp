#include <iostream>
#include "Date.h"

using std::cout;
using std::cin;

int main(){
    Date anniversario{5,5,2021};
    Date comp;


    cout<<"\nL'anniversario e' il:";
    anniversario.displayDate();
    cout<<std::endl;
    
    cout<<"Inserisci data di compleanno:\n";
    cout<<"Mese:";
    int mese1;
    cin>>mese1;
    if (mese1>=1 && mese1<=12)
    {
        comp.setMonth(mese1);
    }else{
        cout<<"Il mese deve essere compreso tra 1 e 12";
    }   

    cout<<"\nGiorno:";
    int giorno1;
    cin>>giorno1;
    if(giorno1>=1 && giorno1<=31){
        comp.setDay(giorno1);
    }else{
        cout<<"Il giorno deve essere compreso tra 1 e 31";
    }
    
    cout<<"\nAnno:";
    int anno1;
    cin>>anno1;
    comp.setYear(anno1);

    cout<<"Il compleanno e' il:";
    comp.displayDate();




}