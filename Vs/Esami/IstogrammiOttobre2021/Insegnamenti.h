/*Le informazioni minime per un insegnamento sono  il nome_insegnamento (stringa),
il numero di crediti n_crediti (intero) e il docente (stringa) */
#ifndef INSEGNAMENTI_H
#define INSEGNAMENTI_H
#include<string>
#include<sstream>

class Insegnamento{
    public:
        Insegnamento(): nomeInsegnamento{""}, crediti{0}, docente{""} {}
        Insegnamento(std::string n, int c, std::string d):nomeInsegnamento{n}, crediti{c}, docente{d} {}
        Insegnamento& setNomeIns(const std::string& n){nomeInsegnamento=n; return *this;}
        std::string getNomeIns() const{return nomeInsegnamento;}
        Insegnamento& setCrediti(const int& c){crediti=c; return *this;}
        int getCrediti() const{return crediti;}
        Insegnamento& setDocente(const std::string& d){docente=d; return *this;}
        std::string getDocente() const{return docente;}

        std::string toString(){
            std::ostringstream out;
            out<<"Nome Insegnamento: "<<nomeInsegnamento;
            out<<"\nNumero Crediti: "<<crediti<<" CFU\n";
            out<<"Docente: "<<docente<<"\n";
            return out.str();
        }

    private:
        std::string nomeInsegnamento;
        int crediti;
        std::string docente;
};



#endif