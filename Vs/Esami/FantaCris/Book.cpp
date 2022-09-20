#include<iostream>
#include<iomanip>
#include"Book.h"
using std::cout;
using std::endl;

Book::Book(int id,std::string tit,std::vector<std::string> au,int y,std::string pos,double v)
            :book_id{id},title{tit},authors{au},year{y},position{pos},value{v}{ }

Book& Book::operator=(const Book& book){
    book_id=book.book_id;
    title=book.title;
    authors=book.authors;
    year=book.year;
    position=book.position;
    value=book.value;
}
bool Book::operator<(const Book& rhs) const{
    if(authors==rhs.authors)
        return this->year < rhs.year;
    else
        return this->authors<rhs.authors;
}
void Book::setId(int id){
        book_id=id;
}
void Book::setAuthors(std::vector<std::string>& aut){
    authors=aut;
}
void Book::setYear(int y){
    year=y;
}
void Book::setTitle(std::string tit){
    title=tit;
}
void Book::setPosition(std::string pos){
    position=pos;
}
void Book::setValue(double val){
    value=val;
}
int Book::getId() const{
    return this->book_id;
}
std::vector<std::string> Book::getAuthors() const {}
int Book::getYear() const{
    return this->year;
}
std::string Book::getTitle() const{
    return this->title;
}
std::string Book::getPosition() const{
    return this->position;
}
double Book::getValue() const{
    return this->value;
}

void Book::print() const{
    std::cout<<std::left<<std::setw(4)<<book_id<<": "<<std::setw(25)<<title<<" ("<<year<<") "<<std::setw(8)<<position<<" "<<value<<"$\n";
    std::cout<<"   Authors: ";
    for(auto aut : authors){
        std::cout<<aut<<", ";
    }
    std::cout<<'\n';
    return;
}