#include "Insegnamento.h"
#include "Studente.h"
#include "Segreteria.h"

int main(){
    
    Insegnamento i1{"Analisi", 9, "Mallozzi"};
    Insegnamento i2{"Fisica", 6, "Valore"};
    Insegnamento i3{"Fondamenti di informatica", 9, "Chianese"};
    
    Studente s1{"Nike", "Di Giacomo", "N46005738"};
    Studente s2{"Nello", "Di Chiaro", "N39000000"};

    s1.addEsamiSuperati(i1);
    s1.addEsamiSuperati(i2);
    s1.addEsamiSuperati(i3);

    std::cout << "La somma dei cfu dello studente e' " ;
    std::cout<<s1.calcolaCrediti()<<std::endl;

    s2.addEsamiSuperati(i1);
    s2.addEsamiSuperati(i2);

    std::cout << "La somma dei cfu dello studente e'" ;
    std::cout<<s2.calcolaCrediti()<<std::endl;

    
    Segreteria Myseg;

    Myseg.addStudente(s1);
    Myseg.addStudente(s2);

    Myseg.calcoloIstogramma();

    }
