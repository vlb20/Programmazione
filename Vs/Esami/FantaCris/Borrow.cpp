#include<iostream>
#include"Borrow.h"

Borrow::Borrow(const Book& book,Date dat,Date due)
        :Book{book},collectdate{dat},dueDate{due}{}

Borrow::Borrow(const Book& book,Date dat)
        :Book{book},collectdate{dat},dueDate{dat}{
            for(int i=0;i<30;++i) 
                dueDate++;
        }

bool Borrow::operator<(const Borrow& rhs) const{
        return this->dueDate < rhs.dueDate;
}
void Borrow::print() const{
        Book::print();
        std::cout<<"   Was barrowed: "<<collectdate<<'\n';
        std::cout<<"   due date: "<<dueDate<<'\n';
}
const Date& Borrow::getDue() const{
        return dueDate;
}