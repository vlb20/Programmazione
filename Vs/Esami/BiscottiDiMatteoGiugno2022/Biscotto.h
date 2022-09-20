#ifndef BISC_H
#define BISC_H
#include <string>
#include <array>
using std::string;
using std::array;
#include <sstream>
using std::ostringstream;

class Biscotto
{
    public:
        Biscotto(int i, string n, string p, array<float,10> v): id{i}, nome{n}, prod{p}, valori{v} {}
        int getId() const {return id;}
        int setId(int i) { id=i;}

        string toString()
        {
            ostringstream out;
            out<< id <<") "<< nome<< " prodotto da "<< prod<< " - TABELLA VALORI:";
            for (int i=0; i<valori.size(); i++) out<< "["<< valori[i]<<"] ";
            return out.str();
        }

        array<float,10> getValori() const { return valori;}
        

    private:
        int id;
        string nome;
        string prod;
        array<float,10> valori;


};
#endif