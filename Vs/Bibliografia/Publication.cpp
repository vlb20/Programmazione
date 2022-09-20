#include "Publication.h"
#include<vector>
#include<string>
#include<iostream>
#include<sstream>

Publication::Publication(std::vector<std::string> au, std::string ti, int yr): //costruttore
    authors{au}, title{ti}, year{yr} {}
    //get and set
const std::vector<std::string>& Publication::getAuthors() {return authors;}
Publication& Publication::setAuthors(const std::vector<std::string>& au){//restituisce un puntator a this, abilità la cascata
    authors=au;
    return *this;    
}

const std::string& Publication::getTitle(){return title;}
Publication& Publication::setTitle(const std::string& ti){
    title=ti;
    return *this;
}

const int Publication::getYear(){return year;}
void Publication::setYear(int yr){
    year=yr;
}

//comparison
bool Publication::operator<(const Publication& B){
    if(authors == B.authors){
        return year<B.year;
    }
    return authors<B.authors;
}

    //virtual print
std::string Publication::toString(){
    std::ostringstream out; //flusso che colleghiamo ad una stringa
    out << " - \t";
    for(int i=0; i<authors.size(); i++){
        out << authors[i];
        out << ((i==authors.size()-1)? " ": ", "); //se è l'ultimo autore non mettere la virgola
    }
    out<< "("<<year<<") "<<title<<". ";
    return out.str();    
}