#ifndef ALBERGO_H
#define ALBERGO_H
#include<list>
#include<string>
#include"Prenotazione.h"
#include<sstream>
class Albergo{
    public:
        Albergo(std::string n={}, int s=2, double pr=0): name{n}, price{pr}, bookings()  {if(s>=2 && s<=5) stars=s;}
        Albergo& setName(const std::string& n){name=n;return*this;}
        std::string getName() const{return name;}
        Albergo& setStars(const int& s){stars=s; return*this;}
        int getStars() const{return stars;}
        Albergo& setPrice(const double& p){price=p;return*this;}
        double getPrice() const{return price;}
        Albergo& setBookings(const std::list<Prenotazione>& p){bookings=p; return *this;}
        std::list<Prenotazione> getBookings() const{return bookings;}
        bool operator<(const Albergo& a){
            return bookings.size() < a.bookings.size();
        }
        Albergo& book(const Prenotazione& p){
            std::list<Prenotazione>::iterator it;
            for(it=bookings.begin(); it!=bookings.end(); ++it){
                if(*(it)<p){
                    break;
                }
            }
            bookings.insert(it,p);
            return *this;
        }

        bool free(const Date& d){
            for(auto it=bookings.begin(); it!=bookings.end(); ++it){
                if(it->getDate()==d){
                    return false;
                }
            }
            return true;
        }

        std::string toString(){
            std::ostringstream out;
            out<<"Albergo: "<<name;
            out<<"\nCategoria: "<<stars<<" stelle.";
            out<<"\nPrezzo per notte: "<< price <<"$\n";
            out<<"Prenotazioni: \n";
            for(auto it=bookings.begin(); it!=bookings.end(); ++it){
                out<< it->toString() <<"\n";
            }
            return out.str();
        }

    private:
        std::string name;
        int stars;
        double price;
        std::list<Prenotazione> bookings;
};

#endif