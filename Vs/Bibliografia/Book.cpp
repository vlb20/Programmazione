#include "Book.h"
#include<sstream>

Book::Book(std::vector<std::string> au, std::string ti, int yr, std::string is, std::string pub): //autori titolo anno ISBN publisher
    Publication::Publication(au,ti,yr), ISBN{is}, publisher{pub} {++nBooks;}//incrementa anche la variabile statica

Book::~Book(){
    --nBooks;
}
    

//get set
const std::string& Book::getISBN() {return ISBN;}
Book& Book::setISBN(const std::string& is){
    ISBN=is;
    return *this;
}

const std::string& Book::getPublisher(){return publisher;}
Book& Book::setPublisher(const std::string& pub){
    publisher=pub;
    return *this;
}

//override toString
std::string Book::toString(){
    std::ostringstream out;
    out<<Publication::toString()<< " "<< ISBN << " "<< publisher<<".";
    return out.str();
}