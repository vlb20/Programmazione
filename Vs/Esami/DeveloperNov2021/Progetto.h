/*Ogni progetto ha un nome (stringa), un committente (stringa), un importo (float),
una data di inizio e una data di consegna del progetto.
Il progetto contiene inoltre una lista di tasks.*/
#ifndef PROGETTO_H
#define PROGETTO_H
#include"Tasks.h"
#include"Programmatori.h"
#include"Date.h"
#include<string>
#include<list>

class Progetto{
    public:
        Progetto(std::string n, std::string com, float imp, std::list<Task> tsk):nomeprogetto{n}, committente{com}, importo{imp}, tasks(tsk) {}
        Progetto& setNomeProgetto(const std::string& n){nomeprogetto=n; return *this;}
        std::string getNomeProgetto() const{return nomeprogetto;}
        Progetto& setCommittente(const std::string& com){committente=com; return *this;}
        std::string getCommittente() const{return committente;}
        Progetto& setImporto(const float& imp){importo=imp; return *this;}
        float getImporto() const {return importo;}
        Progetto& setTasks(const std::list<Task>& t){tasks=t; return *this;}
        std::list<Task> getTasks() const{return tasks;}

        Progetto& insertTask(const Task& t){
            std::list<Task>::iterator it;
            for(it=tasks.begin(); it!=tasks.end(); it++){
                if(*(it)<t){
                    break;
                }
            }
            tasks.insert(it,t);
            return *this;
        }

        std::string toString(){
            std::ostringstream out;
            out<<"Progetto: "<<nomeprogetto;
            out<<"\nCommittente: "<<committente;
            out<<"\nImporto: "<< importo <<"$\n";
            out<<"Tasks: \n";
            for(auto it=tasks.begin(); it!=tasks.end(); ++it){
                out<< it->toString() <<"\n";
            }
            return out.str();
        }

        int workloadDeveloper( Programmatore& p){
            int workLoad{0};
            for(auto it=tasks.begin();it!=tasks.end();it++){
                if((*it).getProgrammatore()==p){
                    workLoad += (*it).getProgrammatore().getCosto();
                }
            }
            return workLoad;
        }
    private:
        std::string nomeprogetto;
        std::string committente;
        float importo;
        std::list<Task> tasks;
};



#endif