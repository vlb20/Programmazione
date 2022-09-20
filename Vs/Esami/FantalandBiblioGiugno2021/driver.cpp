#include<iostream>
#include"Libreria.h"
#include<vector>
#include<algorithm>

int main(){
    Date today{10,7,2022};
    std::vector<Book> books;

    Book b1(1,{"Antoine De Saint-Exupéry"},"Il piccolo principe", 1943,"A/1", 12.50);
    Book b2(2,{"Piergiorgio Odifreddi"},"C'era una volta un paradosso",2006,"A/2", 14.20);
    Book b3(3,{"Herman Hesse"},"Siddharta",1922,"B/1",8.90);
    Book b4(4,{"Khaled Hosseini"},"Mille splendidi soli",2007,"B/2",17);
    Book b5(5,{"Cristina Carleo"},"Turbolenze", 2017, "C/6",300000);
    books.push_back(b1);
    books.push_back(b2);
    books.push_back(b3);
    books.push_back(b4);
    books.push_back(b5);

    std::sort(books.begin(),books.end());

    Library myLib(books);
    myLib.print();
    myLib.borrowBook(1,Date(8,7,2022));
    myLib.borrowBook(5,Date(6,7,2021));
    myLib.print();
    std::cout<<"Il valore dei libri la cui data di restituzion e' scaduta e':"<<myLib.valueExpired(today)<<std::endl;


}