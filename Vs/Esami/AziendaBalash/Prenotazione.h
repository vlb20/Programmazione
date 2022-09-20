#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include<string>
#include"Date.h"
#include<sstream>
class Prenotazione{
    public:
        Prenotazione() : name{""}, code{""}, bookingdate() {}
        Prenotazione(std::string n, std::string c, Date b) : name{n}, code{c}, bookingdate{b} {}
        Prenotazione& setName(const std::string& n){name=n;return *this;}
        std::string getName() const {return name;}
        Prenotazione& setCode(const std::string& c){code=c;return *this;}
        std::string getCode() const {return code;}
        Prenotazione& setDate(const Date& b){bookingdate=b;return *this;}
        Date getDate() const{return bookingdate;}

        bool operator<(const Prenotazione& p){
            return bookingdate<p.bookingdate;
        }

        std::string toString(){
            std::ostringstream out;
            out<<"Nome Cliente: "<<name;
            out<<"\nNumero Carta di credito: "<<code;
            out<<"\nData di prenotazione: "<<bookingdate;
            return out.str();
        }

    private:
        std::string name;
        std::string code;
        Date bookingdate;
};

#endif