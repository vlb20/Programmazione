#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include<string>
#include"Date.h"
#include<sstream>

class Prenotazione{
    friend std::ostream& operator<<(std::ostream& out, const Prenotazione& cl);
    friend bool operator<(const Prenotazione& lhs, const Prenotazione& rhs);
    friend bool operator>(const Prenotazione& lhs, const Prenotazione& rhs);
    friend bool operator==(const Prenotazione& lhs, const Prenotazione& rhs);
    
private:
    std::string nomeCliente;
    std::string codiceCarta;
    Date dataPrenotazione{1,1,2000};

public:
    friend class Albergo;
    Prenotazione(): nomeCliente{""}, codiceCarta{""}, dataPrenotazione() {}
    Prenotazione(const std::string& nome, const std::string& cod, const Date& data): nomeCliente{nome}, codiceCarta{cod}, dataPrenotazione{data} {}
    //big three
    ~Prenotazione();
    Prenotazione(const Prenotazione& pr);
    Prenotazione& operator= (const Prenotazione& pr);

    void setData(const Date& data);
    void setNomeCliente(const std::string& nome);
    void setCarta(const std::string& carta);
    Date getData() const;
    std::string getNomeCliente() const;
    std::string getCarta() const;

    std::string toString() const;

};


#endif