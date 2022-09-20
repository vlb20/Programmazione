#include "Studenti.h"
#include "Insegnamenti.h"
#include<vector>
#include<array>
#include<iostream>
using std::array;
using std::vector;

template<typename T>
void printVector(vector<T>&v);
array<vector<Studente*>,181> istogramma;
void creaIstogamma(vector<Studente*>&studenti);
void IstogrammaCrediti();

int main(){
    vector<Studente*> studenti;
    vector<Insegnamento*> insegnamenti;
    Insegnamento a1{"Analisi 1", 9, "Gabriella Zecca"};
    Insegnamento f1{"Fisica 1", 6, "Ofelia Pisanti"};
    Insegnamento fI{"Fondamenti di Informatica",9, "Antonio Maria Rinaldi"};
    Insegnamento f2{"Fisica 2", 6, "Davide Massarotti"};
    Insegnamento a2{"Analisi 2", 6, "Gabriella Zecca"};

    insegnamenti.push_back(&a1);
    insegnamenti.push_back(&f1);
    insegnamenti.push_back(&fI);
    insegnamenti.push_back(&f2);
    insegnamenti.push_back(&a2);
    std::cout<<"----LISTA INSEGNAMENTI----\n";
   // printVector(insegnamenti);

    Studente vlb{"Vincenzo Luigi", "Bruno", "N46005698"};
    Studente cc{"Cristina", "Carleo", "N46005492"};
    Studente ndg{"Nike", "Di Giacomo", "N46002006"};
    studenti.push_back(&vlb);
    studenti.push_back(&cc);
    studenti.push_back(&ndg);

    vlb.esameSuperato(&a1);
    vlb.esameSuperato(&a2);
    vlb.esameSuperato(&f1);
    cc.esameSuperato(&a1);  
    cc.esameSuperato(&a2);
    cc.esameSuperato(&f1);
    cc.esameSuperato(&f2);
    cc.esameSuperato(&fI);
    ndg.esameSuperato(&a1);
    std::cout << "*----------Lista Studenti----------* \n\n";
   // printVector(studenti);

    creaIstogramma(studenti);  
    std::cout<<"Istogramma: ";
    IstogrammaCrediti();

    return 0;


}

void creaIstogramma(vector<Studente*>&studenti){
    for(Studente* i: studenti ){
        istogramma[i->calcoloCFU()].push_back(i);
    }
}

void IstogrammaCrediti(){
    for(int i=0; i<181; i++){
        std::cout<<"Numero di studenti con "<<i<<" crediti sono:"<<istogramma.size()<<std::endl;
    }
}

/*template<typename T>
void printVector(vector<T>&v){

  for (int i = 0; i<v.size(); i++){
    std::cout <<*(v[i])<< "\n";
  }
}*/