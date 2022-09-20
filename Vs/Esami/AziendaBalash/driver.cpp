#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Prenotazione.h"
#include "Albergo.h"
#include "Azienda.h"
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
int main(){
    vector<Albergo> v;
    Albergo a1("Hotel Cristina",3,22);
    Albergo a2("Hotel JFK",4,35);
    Albergo a3("La Luna Rossa",5,80);
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);
    Azienda hotels(v);
    cout<<hotels.toString();
    Date today(16,7,2022);
    hotels.insert_booking("Vincenzo Luigi Bruno","VLB20NPL4564",today,4);
    cout<<endl<<endl;
    cout<<hotels.toString();
    return 0;
}