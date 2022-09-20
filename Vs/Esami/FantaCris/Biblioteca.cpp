#include"Biblioteca.h"
#include"Borrow.h"
#include"Date.h"
#include<iostream>

//default constructor
Biblioteca::Biblioteca()
        :books{},borrows{}{}

//constructor
Biblioteca::Biblioteca(std::vector<Book> bookSet)
        :books{bookSet},borrows{}{}
        
void Biblioteca::borrowBook(int id, const Date& date){
        for(auto it=books.begin();it!=books.end();++it){
            if(it->getId()==id){
                //creiamo un nuovo prestito
                Borrow b(*it,date);
                insertOrder(b);
                return;
            }
        }
        throw std::invalid_argument("Book cannot be found");
        return;
        }
void Biblioteca::print() const{
        std::cout<<"Stored books:\n";
        if(books.empty())
            std::cout<<"---Empty---\n";
        else for(Book b :books)
                b.print();
        std::cout<<"Currently borrowed books:\n";
        if (borrows.empty()){
            std::cout<<"---Empty---\n";
        }else for(Borrow b : borrows)
                    b.print();
        }
double Biblioteca::valueExpired(const Date& today) const{
        double res{0};
        for(auto it=borrows.begin();it!=borrows.end();++it){
            if(it->getDue()<today)
                    res+=it->getValue();
             }
            return res;    
        }
void Biblioteca::insertOrder(const Borrow& b){
        std::list<Borrow>::iterator it;
        for(it=borrows.begin();it!=borrows.end();++it){
            if(*it<b){
                break;
            }
        }
        borrows.insert(it,b);
        }
double Biblioteca::returnBook(int id, const Date& today){
    for(auto it=borrows.begin();it!=borrows.end();++it){
        if(it->getId()==id){
            if(it->getDue()<today){
                Date date=it->getDue();
                double multa=0.0;
                do{
                    date++;
                    multa=multa+1;
                }while(today!=date);
                return multa;
                }else{
                    std::cout<<"Libro consegnato in tempo"<<std::endl;
                    return 0.0;
                }
            }
    }
    throw std::invalid_argument("Libro non trovato");
}