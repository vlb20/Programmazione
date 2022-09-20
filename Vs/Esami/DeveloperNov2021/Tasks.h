/* Una task contiene il nome della task, la data di scadenza, il numero di ore uomo (intero),  
  il riferimento al programmatore responsabile di quel task. 
  La lista dei task e’ mantenuta ordinata per data di scadenza.*/
#ifndef TASKS_H
#define TASKS_H
#include<string>
#include"Programmatori.h"
#include"Date.h"

class Task{
    public:
        Task() : nometask{""},datascadenza(),numerore{0} {prog=nullptr;}
        Task(std::string n,Date d, int num, Programmatore& p ):nometask{n}, datascadenza{d}, numerore{num}  {this->prog=&p;}
        Task& setNomeTask(const std::string& n){nometask=n; return *this;}
        std::string getNomeTask() const{return nometask;}
        Task& setData(const Date& d){datascadenza=d; return *this;}
        Date getData() const{return datascadenza;}
        Task& setNumeroUomo(const int& num){numerore=num; return *this;}
        int getNumeroUomo() const{return numerore;}
        Task& setProgrammatore(Programmatore& p){prog=&p; return *this;}
        Programmatore getProgrammatore() const {return *prog;}

        bool operator<(const Task& t){
            return (datascadenza<t.datascadenza);
        }

        std::string toString(){
            std::ostringstream out;
            out<<"\nTask:\n";
            out<<"Nome: "<<nometask;
            out<<"\nData di scadenza: "<<datascadenza;
            out<<"\nNumero di ore uomo: "<<numerore;
            out<<"\nProgrammatore responsabile: "<<prog->toString();
            return out.str();
        }

    private:
        std::string nometask;
        Date datascadenza;
        int numerore;
        Programmatore* prog;

};





#endif