#ifndef BOOK_H
#define BOOK_H
#include "Publication.h"


class Book : public Publication{
public:
    static int nBooks; //ci servira per calcolare il tipo di pubblicazioni
    Book(std::vector<std::string>, std::string, int, std::string, std::string); //autori titolo anno ISBN publisher
    ~Book();
    
    //get set
    const std::string& getISBN();
    Book& setISBN(const std::string&);
    const std::string& getPublisher();
    Book& setPublisher(const std::string&);

    //override toString
    std::string toString();

private:
    std::string ISBN;
    std::string publisher;

};



#endif