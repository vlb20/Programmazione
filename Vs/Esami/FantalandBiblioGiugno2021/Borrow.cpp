#include"Borrow.h"
#include<iostream>

Borrow::Borrow(const Book& lib, Date dat)
    :Book{lib}, collectDate{dat}, dueDate{dat}{
        for(int i=0; i<30; i++){
            dueDate++;
        }
    }

Borrow::Borrow(const Book& lib, Date coll, Date due)
    :Book{lib}, collectDate{coll}, dueDate{due} {}


const Date& Borrow::getDue() const{
    return dueDate;
}

bool Borrow::operator<(const Borrow& rhs) const{
    return this->dueDate<rhs.dueDate;
}

void Borrow::print() const{
    Book::print();
    std::cout<<"    e' stato prestato il: "<<collectDate<<"\n";
    std::cout<<"    data di restituzione: "<<dueDate<<"\n";
}

