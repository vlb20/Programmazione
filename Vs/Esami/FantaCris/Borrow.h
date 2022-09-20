#ifndef BORROW_H
#define BORROW_H

#include "Book.h"
#include"Date.h"

class Borrow:public Book{
    private:
        Date collectdate; //giorno in cui il libro viene preso in prestito
        Date dueDate;//giorno entro cui deve essere restituito il libro
    public:
        Borrow(const Book& = Book(), Date=(Date())); //constructor con default argument
        //due date inserita in automatico
        Borrow(const Book&,Date,Date);
        //per inserire una duedate diversa
        bool operator<(const Borrow&) const;
        void print() const override;
        const Date& getDue() const;
};

#endif