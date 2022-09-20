#ifndef TAVOLI_H
#define TAVOLI_H
#include<string>

class Tavolo{
public:
    Tavolo(int,const std::string&,const std::string&, float);
    virtual ~Tavolo()=default;

    void setColore(int);
    int getColore() const;
    void setLegno(const std::string&);
    std::string getLegno() const;
    void setFornitore(const std::string&);
    std::string getFornitore() const;
    void setPrezzo(float);
    float getPrezzo() const;

    virtual double getArea() const=0;//pure virtual
    virtual void print() const;
    virtual void type() const;

private:
    int colore;
    std::string tipoLegno;
    std::string fornitore;
    float prezzo; //prezzo per centimetro quadro
};


#endif