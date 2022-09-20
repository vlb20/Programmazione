#ifndef INSEGNAMENTO_H
#define INSEGNAMENTO_H

#include <string>

class Insegnamento{
    public:   
        Insegnamento(std::string n, int c, std::string d) : nome{n}, cfu{c}, docente{d} {}
        int getCfu() const{
            return cfu;
        } 
        std::string getNome() const{
            return nome;
        }
    private:
        std::string nome;
        int cfu;
        std::string docente;
};

#endif