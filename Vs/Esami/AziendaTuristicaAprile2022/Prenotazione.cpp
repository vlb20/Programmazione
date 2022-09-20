#include "Prenotazione.h"
#include <sstream>

//le prenotazioni vanno mantenuti in ordine di data

bool operator<(const Prenotazione& lhs, const Prenotazione& rhs){
    return (lhs.dataPrenotazione < rhs.dataPrenotazione);
}
bool operator>(const Prenotazione& lhs, const Prenotazione& rhs){
    return(lhs.dataPrenotazione > rhs.dataPrenotazione);
}
bool operator==(const Prenotazione& lhs, const Prenotazione& rhs){
    return(lhs.dataPrenotazione == rhs.dataPrenotazione);
}

std::ostream& operator<<(std::ostream& out, const Prenotazione& pr){
    out<< pr.toString();
    return out;
}

Prenotazione::Prenotazione(const Prenotazione& pr){
    setData(pr.getData());
    setNomeCliente(pr.getNomeCliente());
    setCarta(pr.getCarta());
}

Prenotazione::~Prenotazione(){}

Prenotazione& Prenotazione::operator=(const Prenotazione& pr){
    if(!(this==&pr)){
        setData(pr.getData());
        setNomeCliente(pr.getNomeCliente());
        setCarta(pr.getCarta());
    }
    return *this;
}

void Prenotazione::setCarta(const std::string& carta){codiceCarta=carta;}
void Prenotazione::setData(const Date& data){dataPrenotazione=data;}
void Prenotazione::setNomeCliente(const std::string& nome){nomeCliente=nome;}
Date Prenotazione::getData() const {return dataPrenotazione;}
std::string Prenotazione::getNomeCliente() const{return nomeCliente;}
std::string Prenotazione::getCarta() const{return codiceCarta;}

std::string Prenotazione::toString() const{
    std::ostringstream out;
    out<<"  PRENOTAZIONE:    \n"
       <<"NOME: "<<nomeCliente<<"\n"
       <<"NUMERO CARTA: "<<codiceCarta<<"\n"
       <<"DATA: "<<dataPrenotazione<<"\n";
       return out.str(); 
}

