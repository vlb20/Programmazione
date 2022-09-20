#ifndef LIBRERIA_H
#define LIBRERIA_H
#include"Book.h"
#include"Borrow.h"
#include<list>

class Library{
    public:
        Library();
        Library(std::vector<Book>);
        void borrowBook(int, const Date&); //bookID e Data del prestito
        void print() const;
        double valueExpired(const Date&) const;
        void insertOrder(const Borrow&);
        int returnBook(int, const Date&) const;
    private:
        std::vector<Book> books;
        std::list<Borrow> borrows;
        
};


#endif
