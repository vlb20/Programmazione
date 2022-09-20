#ifndef ROTONDI_H
#define ROTONDI_H
#include"Tavoli.h"
#include<string>

class Rotondo: public Tavolo{
    public:
        Rotondo(int, const std::string&, const std::string&, float, double);
        virtual ~Rotondo()=default;

        void setRaggio(double);
        double getRaggio() const;

        virtual double getArea() const override;
        void print() const override;
        void type() const override;
    private:
        double raggio;
        const double pi{3.14};
};


#endif