#ifndef MOBILIFICIO_H
#define MOBILIFICIO_H

#include"Tavoli.h"
#include"Rotondi.h"
#include"Rettangolari.h"
#include"Triangolari.h"
#include<list>

class Mobilificio{
    public:
        Mobilificio();
        void insertTable(Tavolo*);
        double summarizeWharehouse();
        std::list<Tavolo*> getLista() const;

    private:
        std::list<Tavolo*> tavoli;
    
};


#endif