#ifndef STUDENTE_H
#define STUDENTE_H

#include "Insegnamento.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

class Studente
{
public:
    Studente(std::string n, std::string c, std::string mat )
        : nome{n}, cognome{c}, matricola{mat}, esamiSuperati{ } {}

    void addEsamiSuperati(const Insegnamento &i)
    {
                esamiSuperati.push_back(i);
           
        }
    
    
    std::vector<Insegnamento> getEsamiSuperati()const{
        return esamiSuperati;
    }

    int calcolaCrediti()
    {   
        int somma{0};
        for (int j = 0; j < esamiSuperati.size(); j++)
        {
            somma += esamiSuperati[j].getCfu();
        }
        if (somma <= 180)
        {
            return somma;
        }
    }

    std::string getNome() const{
        return nome;
    }
    std::string getCognome() const{
        return cognome;
    }
    std::string getMatricola() const{
        return matricola;
    }
private:
    std::string nome;
    std::string cognome;
    std::string matricola;
    std::vector<Insegnamento> esamiSuperati;
};
#endif