#ifndef BORROW_H
#define BORROW_H

#include"Book.h"
#include"Date.h"

class Borrow: public Book{
    public:
        Borrow(const Book& = Book(), Date=Date());
        Borrow(const Book&, Date, Date);

        bool operator<(const Borrow&) const;
        void print() const override;
        const Date& getDue() const;
       

    private:
        Date collectDate;
        Date dueDate;
};


#endif