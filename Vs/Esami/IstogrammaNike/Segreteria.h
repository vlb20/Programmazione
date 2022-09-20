
#ifndef SEGRETERIA_H
#define SEGRETERIA_H

#include "Insegnamento.h"
#include "Studente.h"

class Segreteria
{
public:
    Segreteria() {}
    void addStudente(const Studente &s)
    {
        studenti.push_back(s);
    }

    void calcoloIstogramma()
    {
        const int n{180};
        int istogramma[n] = {};

       
        for (int i = 0; i < studenti.size(); i++)
        {   int temp = studenti[i].calcolaCrediti();

            for (int j = 0; j < temp ; j++)

            { 
                istogramma[j] += 1;
            }
        }

        std::cout << "Istogramma: "<<std::endl;

        for(int k=0; k<n; k++){
            std::cout<<istogramma[k]<<" ";
        }
    }

private:
    std::vector<Studente> studenti;
};

#endif