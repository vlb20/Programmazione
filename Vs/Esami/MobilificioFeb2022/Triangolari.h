#ifndef TRIANGOLARI_H
#define TRIANGOLARI_H
#include"Tavoli.h"
#include<string>

class Triangolo : public Tavolo{
public:
    Triangolo(int, const std::string&, const std::string&, float, double, double);
    virtual ~Triangolo()=default;

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