#include"Albergo.h"
#include<list>
#include<sstream>
#include<stdexcept>
Albergo::Albergo():
    nomeAlbergo{}, prezzo{}, stelle{2}, prenotazioni() {}

Albergo::Albergo(const std::string& nome, float p, int s):
    nomeAlbergo{nome}, prezzo{p}, stelle{s}, prenotazioni() {}

Albergo::Albergo(const Albergo& al):
    nomeAlbergo{al.nomeAlbergo}, prezzo{al.prezzo}, stelle{al.stelle}, prenotazioni{al.prenotazioni} {}
Albergo::~Albergo(){
    prenotazioni.clear();
}
Albergo& Albergo::operator=(const Albergo& al){
    if(!(this==&al)){
        setNomeAlbergo(al.getNomeAlbergo());
        setPrezzo(al.getPrezzo());
        setStelle(al.getStelle());
        prenotazioni=al.prenotazioni;
    }
    return *this;
}

void Albergo::setNomeAlbergo(const std::string& nome){nomeAlbergo=nome;}
void Albergo::setStelle(int s){
    if(s>=2 && s<=5){
        stelle=s;
    }else{
        throw std::invalid_argument("Le stelle devono essere comprese tra 2 e 5");
    }
}
void Albergo::setPrezzo(float p){prezzo=p;}
std::string Albergo::getNomeAlbergo() const{return nomeAlbergo;}
int Albergo::getStelle() const{return stelle;}
float Albergo::getPrezzo() const{return prezzo;}

int Albergo::getNumeroPrenotazioni() const{return prenotazioni.size();}

bool operator<(const Albergo& lhs, const Albergo& rhs){
    return(lhs.getNumeroPrenotazioni() < rhs.getNumeroPrenotazioni());
}
bool operator>(const Albergo& lhs, const Albergo& rhs){
    return(lhs.getNumeroPrenotazioni() > rhs.getNumeroPrenotazioni());
}
bool operator==(const Albergo& lhs, const Albergo& rhs){
    return(lhs.getNumeroPrenotazioni() == rhs.getNumeroPrenotazioni());
}

std::string Albergo::toString() const{
    std::ostringstream out;
    out<<"\n    DATI ALBERGO    \n"
       <<"NOME ALBERGO: "<<nomeAlbergo
       <<"\n"<<stelle<<" STELLE"
       <<"\nPREZZO: "<<prezzo<<"\n";
        std::list<Prenotazione*>::iterator it;
       for(auto it=prenotazioni.begin(); it!=prenotazioni.end();it++){
            (*it)->toString();
       }
       return out.str();
}

Albergo& Albergo::insertOrder(Prenotazione* pr){
    std::list<Prenotazione*>::iterator it;
    for(auto it=prenotazioni.begin(); it!=prenotazioni.end(); ++it){
        if(*(it)<pr){
            break;
        }
    }
    prenotazioni.insert(it,pr);
    return *this;
}

std::list<Prenotazione*>& Albergo::getListaPrenotazioni(){
    return prenotazioni;
}

bool Albergo::findDate(Prenotazione* pr){
    bool found=false;
    std::list<Prenotazione*>::iterator it;
    for(auto it=prenotazioni.begin(); it!=prenotazioni.end(); ++it){
        if((*it)->getData()==pr->getData()){
            found=true;
            break;
        }
    }
    return found;
    
}