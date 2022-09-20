#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<iostream>
#include<sstream>
using std::ostream;
using std::cout;

class Polynomial{

    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
    friend Polynomial operator*(const Polynomial& lhs,const Polynomial& rhs);

    public:
        //costruttori
        Polynomial();
        Polynomial(double coefficients[], int number);
        Polynomial(const Polynomial& rhs);
        explicit Polynomial(double const_term);//costruttore copia explicit per evitare che il coefs dei due polinomi punti alla stessa area di memoria

        //distruttore
        ~Polynomial();

        //funzioni membro
        int degree() const{
            return size-1;
        }
        void print(ostream& out=cout) const;

        //operatori
        Polynomial& operator= (const Polynomial& rhs);
        Polynomial& operator+= (const Polynomial& rhs);
        Polynomial& operator*= (double rhs);

    private:
        int size; //size of array di coef (=degree+1)
        double *coefs;
};

Polynomial operator+(const Polynomial& lhs, const Polynomial rhs);
Polynomial operator*(const Polynomial& lhs, double rhs);
Polynomial operator*(double lhs, const Polynomial& rhs);

ostream& operator<<(ostream& out, const Polynomial& p);

#endif