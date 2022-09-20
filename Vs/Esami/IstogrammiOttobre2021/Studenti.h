/*Per ogni studente invece conserveremo il nome (stringa), cognome (stringa), matricola (stringa)
e la lista degli insegnamenti (riferimenti) che lo studente ha superato.*/
#ifndef STUDENTI_H
#define STUDENTI_H
#include"Insegnamenti.h"
#include<list>
#include<sstream>
#include<string>
#include<iostream>

class Studente{
    public:
        Studente(std::string n={""},std::string c={""}, std::string m={""}): nomeStudente{n}, cognome{c}, matricola{m}, insegnamenti() {}
        Studente& setNomeStudente(const std::string& n){nomeStudente=n; return *this;}
        std::string getNomeStudente() const{return nomeStudente;}
        Studente& setCognome(const std::string& c){cognome=c; return *this;}
        std::string getCognome() const{return cognome;}
        Studente& setMatricola(const std::string& m){matricola=m; return *this;}
        std::string getMatricola() const{return matricola;}

        void esameSuperato(Insegnamento* materia){
            std::list<Insegnamento*>::iterator it;
            for(it=insegnamenti.begin();it!=insegnamenti.end();it++){
                if((*it)==materia){
                    std::cout<<"Esame già superato!";
                    return;
                }
            }
            insegnamenti.insert(it,materia);
        }

        int calcoloCFU() const{
            int totale{0};
            for(auto it=insegnamenti.begin(); it!=insegnamenti.end(); it++){
                totale += (*it)->getCrediti();
            }
            return totale;
        }
        
        std::string toString(){
            std::ostringstream out;
            out<<"Studente:";
            out<<"\nNome: "<<nomeStudente<<" Cognome:"<<cognome;
            out<<"\nMatricola: "<<matricola;
            out<<"\nEsami superati: ";
            for(auto it=insegnamenti.begin(); it!=insegnamenti.end(); it++){
                out<<(*it)->toString();
            }
            return out.str();
        }

    private:
        std::string nomeStudente;
        std::string cognome;
        std::string matricola;
        std::list<Insegnamento*> insegnamenti;
};




#endif