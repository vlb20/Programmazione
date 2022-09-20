#include<iostream>
#include<algorithm>
#include"Biblioteca.h"

int main(){
    Date today{16,5,2022};
    int multa{0};
    std::vector<Book> books;

    Book b1(1,"Bartleby lo scrivano",{"Herman Melville"},1853,"A/1",10.00);
    Book b2(2,"Siddharta",{"Herman Hesse"},1900,"A/2",8.00);
    Book b3(3,"La nausea",{"Jean-Paule Sartre"},1938,"A/2",6.00);
    Book b4(4,"Il calcolatore universale",{"Martin Davis"},2003,"B/1",13.50);
    Book b5(5,"Il mondo nuovo",{"Aldous Huxley"},1932,"B2",14.00);
    //inseriamo i libri nel vettore
    books.push_back(b1);
    books.push_back(b2);
    books.push_back(b3);
    books.push_back(b4);
    books.push_back(b5);
    //ordiniamo il vettore
    std::sort(books.begin(),books.end());

    //creiamo la nostra libreria
    Biblioteca myBib(books);
    myBib.print();
    myBib.borrowBook(1,Date(1,1,2021));
    myBib.borrowBook(2,Date(1,5,2022));
    myBib.print();
    std::cout<<"The value of Books with expired due date: "<<myBib.valueExpired(today)<<std::endl;
    multa=myBib.returnBook(1,Date(12,07,2022));
    std::cout<<"\nPer il libro 1 paga: "<<multa<<std::endl;

}