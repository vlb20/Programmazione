#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include"Borrow.h"
#include"Book.h"
#include<list>

class Biblioteca{
    private:
        std::vector<Book> books;
        std::list<Borrow> borrows;
    public:
        Biblioteca();//default constuctor
        Biblioteca(std::vector<Book>);//constuctor
        void borrowBook(int, const Date&);//add della Borrowlist
        void print() const;//stmapa prestiti
        //calcolo eventuale multa per la mancata restituione
        double valueExpired(const Date&) const;//argomento const per Least privilege Principle
        void insertOrder(const Borrow&);//inser Borrowlist, lista ordinata
        double returnBook(int, const Date&);
};

#endif