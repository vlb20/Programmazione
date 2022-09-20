/*• Create an application that asks the user a temperature and
the scale (Celsis as “C” or Fahrenheit as “F”) and then
convert the temperature if the other scale:
• Celsius to Fahrenheit formula:
Tf=Tc*(9/5)+32
F to C: tc=(tf-32)*5/9*/

#include<iostream>

using std::cin;
using std::cout;

int main(){
    char unit;
    float Tf{0};
    float Tc{0};

    cout<<"Inserisci unita' di misura da convertire:"<<" "<<"(C-Celsius <-> F-Fahrenheit <-> altro=exit)"<<std::endl;
    cin>>unit;

    while(unit=='C'||unit=='c'||unit=='f'||unit=='F'){
        if(unit=='C'||unit=='c'){
            cout<<"Inserisci la temperatura in gradi Celsius:";
            cin>>Tc;
            Tf=Tc*9/5+32;
            cout<<"Celsius:"<<Tc<<"--->"<<"Fahrenehit:"<<Tf<<std::endl;

        }
        if(unit=='f'||unit=='F'){
            cout<<"Inserisci la temperatura in gradi Fahrenheit:";
            cin>>Tf;
            float x=Tf-32;
            Tc=x*5/9;

            cout<<"Fahrenehit:"<<Tf<<"--->"<<"Celsius:"<<Tc<<std::endl;

        }
        
        cout<<"Inserisci unita' di misura da convertire:"<<" "<<"(C-Celsius <-> F-Fahrenheit <-> altro=exit)"<<std::endl;
        cin>>unit;

        
    }

    return 0;
}