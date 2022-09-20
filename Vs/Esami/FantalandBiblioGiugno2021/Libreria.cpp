#include"Libreria.h"
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stdexcept>
using std::string;
using std::vector;
using std::cout;



Library::Library()
    : books{}, borrows{} {}

Library::Library(vector<Book> libri)
    : books{libri}, borrows{} {}

void Library::insertOrder(const Borrow& prestito){
    std::list<Borrow>::iterator it;
    it=borrows.begin();
    do{
        if(*it<prestito){ //LIFO quindi il più piccolo va per ultimo (prestito più in scadenza va per ultimo)
            break;
        }        
    }while(it!=borrows.end());
    borrows.insert(it, prestito);
}

void Library::borrowBook(int id, const Date& date){
    std::vector<Book>::iterator it;
    it=books.begin();
    do{
        if(it->getId()==id){
            //crea un nuovo nodo
            Borrow b(*it, date);
            insertOrder(b);
            return;
        }

    }while(it!=books.end());
    throw std::invalid_argument("Il libro non e' stato trovato");
    return;
}

void Library::print() const{
    cout<<"Libreria:\n";
    if(books.empty()){
        cout<<"---Non ci sono libri---\n";
    }else{
        for(Book b: books){
            b.print();
        }
    }
    cout<<"\nLibri attualmente in prestito:\n ";
    if(borrows.empty()){
        cout<<"---Nessun libro in prestito---\n";
    }else{
        for(Borrow p: borrows){
            p.print();
        }
    }
}

double Library::valueExpired(const Date& today) const{
    double val{0};
    auto it=borrows.begin();
    do{
        if(it->getDue()<today){
            val += it->getValue();
        }
    }while(it!=borrows.end());  
    return val;  
}

int Library::returnBook(int id, const Date& today) const{
    int multa{0};
    auto it=borrows.begin();
    do{
        if(it->getId()==id){
            if(it->getDue()<today){
                Date date(it->getDue());
                while(date==today){
                    date++;
                    multa++;
                }
            }
        }
        else{
            throw std::invalid_argument("Book not found!");
        }
    }while(it!=borrows.end());
}