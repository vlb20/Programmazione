#ifndef RETTANGOLARI_H
#define RETTANGOLARI_H
#include"Tavoli.h"
#include<string>

class Rettangolo: public Tavolo{
public:
    Rettangolo(int, const std::string&, const std::string&, float, double, double);
    virtual ~Rettangolo()=default;

    void setBase(double);
    double getBase() const;
    void setAltezza(double);
    double getAltezza() const;

    virtual double getArea() const override;
    void print() const override;
    void type() const override;

private:
    double base;
    double altezza;
};



#endif