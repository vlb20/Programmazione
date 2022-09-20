#ifndef AZIENDA_H
#define AZIENDA_H
#include<sstream>
#include<vector>
#include<list>
#include<string>
#include"Date.h"
#include"Prenotazione.h"
#include"Albergo.h"
#include<algorithm>
class Azienda{
    public:
        Azienda() = default;
        Azienda(const std::vector<Albergo>& vec){
            v=vec;
            std::sort(v.begin(), v.end());
        }
        Azienda& setVector(const std::vector<Albergo>& vec) {v=vec; return *this;}
        std::vector<Albergo> getVector() const{return v;}
        Azienda& insert_booking(const std::string& n, const std::string& c, const Date& d, const int& s){
            Prenotazione a(n,c,d);
            std::vector<Albergo>::iterator it;
            for(it=v.begin(); it!=v.end(); ++it){
                if(it->getStars()==s){
                    if(it->free(d)){
                        it->book(a);
                    }
                }
            }
            return *this;
        }
        std::string toString(){
            std::ostringstream out;
            out<<"Azienda di gestione alberghi.\n\n";
            for(auto it=v.begin(); it!=v.end(); ++it){
                out<< it->toString()<<"\n\n";
            }
            return out.str();
        }
    private:
        std::vector<Albergo> v;
};


#endif