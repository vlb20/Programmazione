#ifndef ALBERGO_H
#define ALBERGO_H
#include<list>
#include<string>
#include"Prenotazione.h"

class Albergo{
    friend bool operator<(const Albergo& lhs, const Albergo& rhs);
    friend bool operator>(const Albergo& lhs, const Albergo& rhs);
    friend bool operator==(const Albergo& lhs, const Albergo& rhs);
private:
    std::string nomeAlbergo;
    int stelle=2;
    float prezzo;
    std::list<Prenotazione*> prenotazioni;

public:
    Albergo();
    Albergo(const std::string& nome, float p, int s);
    //big three
    Albergo(const Albergo& al);
    ~Albergo();
    Albergo& operator=(const Albergo& al);

    void setNomeAlbergo(const std::string& nome);
    void setStelle(int s);
    void setPrezzo(float p);
    std::string getNomeAlbergo() const;
    int getStelle() const;
    float getPrezzo() const;
    int getNumeroPrenotazioni() const;
    std::string toString() const;
    Albergo& insertOrder( Prenotazione* pr);
    std::list<Prenotazione*>& getListaPrenotazioni();
    bool findDate( Prenotazione* pr);




};




#endif