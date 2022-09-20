#include"Book.h"
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
using std::string;
using std::vector;
using std::cout;
using std::setw;
using std::endl;

Book::Book(int id, const vector<string>& aut, const string& t,int y ,const string& pos, double v){
    setId(id);
    setAuthors(aut);
    setTitle(t);
    setYear(y);
    setPosition(pos);
    setValue(v);
}

void Book::setId(int id){
    book_id=id;
}
int Book::getId() const{
    return book_id;
}

void Book::setAuthors(const vector<string>& aut){
    authors=aut;
}
string Book::getAuthors() const{
    for(int i=0; i<authors.size(); i++){    
        cout<<authors[i]<<"\t";
    }
}

void Book::setTitle(const string& t){
    title=t;
}
string Book::getTitle() const{
    return title;
}

void Book::setYear(int y){
    year=y;
}
int Book::getYear() const{
    return year;
}

void Book::setPosition(const string& pos){
    position=pos;
}
string Book::getPosition() const{
    return position;
}

void Book::setValue(double v){
    value=v;
}
double Book::getValue() const{
    return value;
}


bool Book::operator<(const Book& rhs) const{
    if(authors==rhs.authors){
        return this->year<rhs.year;
    }else{
        return this->authors<rhs.authors;
    }
}

void Book::print() const{
    cout<<std::left<<setw(4)<<book_id<<": "
        <<setw(25)<<title<<" ("<<year<<") "
        <<setw(8)<<position<<" "<<value<<"$"
        <<"\nAuthors: ";
        for(int i=0; i<authors.size();i++){
            cout<<authors[i]<<", ";
        }
        cout<<endl;
        return;
}