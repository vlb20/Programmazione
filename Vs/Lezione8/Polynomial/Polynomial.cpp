#include<iostream>
#include"Polynomial.h"

//costruttore
//crea un polinomio di deafault p(x)=0.0
Polynomial::Polynomial()
    : size{1}, coefs{new double[1]}{
        coefs[0]=0.0;
    }

//Costruttore
//Array di coefficienti C(con il proprio size N)->crea un polinomio
//p(x)=C[N-1]x^[N-1]+...+C[2]x^2+C[1]x+C[0]
Polynomial::Polynomial(double coefficients[], int number)
    :size{number}, coefs{new double[number]}{
        for(int i=0; i<size; i++){
            coefs[i]=coefficients[i];
        }
    }

//Costruttore
//Da un termine costante A, crea il polinomio p(x)=A
Polynomial::Polynomial(double const_term)
    : size{1}, coefs{new double[1]}{
        coefs[0]=const_term;
    }

//Copy Constructor
//crea un polynomio partendo da un dato polynomio
Polynomial::Polynomial(const Polynomial& rhs)
    : size{rhs.size}, coefs{new double[rhs.size]}{
        for(int i=0; i<size; i++){
            coefs[i]=rhs.coefs[i];
        }
    }

//Distruttore
Polynomial::~Polynomial(){
    delete [] coefs;
}

//overload =
Polynomial& Polynomial::operator=(const Polynomial& rhs){
    if(this==&rhs){
        return *this;
    }
    else{
        delete [] coefs;
        coefs=new double[rhs.size];
        size=rhs.size;
        for(int i=0; i<size; i++){
            coefs[i]=rhs.coefs[i];
        }
    }
    return *this;
}

//overload +=
Polynomial& Polynomial::operator+=(const Polynomial& rhs){
    int newSize=(rhs.size>size) ? rhs.size : size;
    double *newCoef= new double[newSize];

    for(int i=0; i<newSize; i++){
        newCoef[i]=0;
    }
    for(int i=0; i<rhs.size; i++){
        newCoef[i]+=rhs.coefs[i];
    }
    for(int i=0; i<size; i++){
        newCoef[i]+=coefs[i];
    }
    delete [] coefs;
    coefs=newCoef;
    size=newSize;
    return *this;
}

//overload *= per le moltiplicazioni scalari
Polynomial& Polynomial::operator*=(double rhs){
    for(int i=0; i<size; i++){
        coefs[i]*=rhs;
    }
    return *this;
}

//overload ==
bool operator==(const Polynomial& lhs, const Polynomial& rhs){
    if(lhs.size != rhs.size){
        return false;
    }
    for(int i=0; i<lhs.size; i++){
        if(lhs.coefs[i]!=rhs.coefs[i]){
            return false;
        }
    }
    return true;
}

//overload +
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
    Polynomial answer{lhs};
    answer += rhs;
    return answer;
}

//overload * ->polynomial*scalar
Polynomial operator*(const Polynomial& lhs, double rhs){
    Polynomial answer{lhs};
    answer *=rhs;
    return answer;
}

//overload * ->scalar*Polynomial
Polynomial operator*(double rhs,const Polynomial& lhs){
    Polynomial answer{lhs};
    answer *=rhs;
    return answer;
}

//stampa polinomio
void Polynomial::print(std::ostream& out) const{
    if(size==0){
        return;
    }

    for(int i=size-1; i>0; i--){
        out<< coefs[i]<<"x^"<<i<<" + ";
    }
    out<<coefs[0];
}

//overload << for output
std::ostream& operator<<(std::ostream& out, const Polynomial& p){
    p.print(out);
    return out;
}

Polynomial operator*( const Polynomial& lhs, const Polynomial& rhs){
    int newSize= (lhs.degree()+rhs.degree()+1);
    double *newCoefs=new double[newSize]{0};

    for(int i=0; i<newSize; i++){
        newCoefs[i]=0;
    }
    for(int i=0; i<lhs.degree(); i++){
        for(int j=0; j<rhs.degree(); j++){
            newCoefs[i+j]+= lhs.coefs[i]*rhs.coefs[j];
        } 
    }
    Polynomial answer{newCoefs, newSize};
    return answer;
}




