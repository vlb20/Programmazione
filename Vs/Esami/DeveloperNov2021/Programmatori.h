/*Per ogni programmatore manteniamo il nome, ed il costo orario.
I programmatori sono contenuti in un vettore ordinato per costo.*/
#ifndef PROGRAMMATORI_H
#define PROGRAMMATORI_H
#include<string>
#include<sstream>

class Programmatore{
        friend bool operator==(const Programmatore& lhs, const Programmatore&rhs){
            return (lhs.costo == rhs.costo && lhs.nome == rhs.nome);
        }
    public:
        Programmatore() : nome{""}, costo{0} {}
        Programmatore(std::string n, int c): nome{n}, costo{c} {}
        Programmatore& setNome(const std::string& n){nome=n; return *this;}
        std::string getNome() const{return nome;}
        Programmatore& setCosto(const int& c){costo=c; return *this;}
        int getCosto() const{return costo;}
        
        bool operator<(const Programmatore& p){
            return( costo<p.costo );
        }

        std::string toString(){
            std::ostringstream out;
            out<<"Programmatore:\n";
            out<<"Nome: "<<nome;
            out<<"\nCosto Orario: "<<costo<<"$\n";
            return out.str();

        } 
    private:
        std::string nome;
        int costo;
        
};



#endif
