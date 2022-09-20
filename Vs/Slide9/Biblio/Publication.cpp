#include "Publication.h"
#include <iostream>
#include <sstream>

 Publication::Publication(std::vector<std::string> au, std::string ti, int yr):
    authors{au}, title{ti}, year{yr} {}
    
const std::vector<std::string> & Publication::getAuthors() {return authors;}  
Publication & Publication::setAuthors( const std::vector<std::string>& au){
    authors=au;
    return *this;
    }
    //...
    //comparison
    bool Publication::operator<(const Publication& B){
        if(authors==B.authors){
            return year < B.year;
        }
        return authors < B.authors;
    }
    //print
    std::string Publication::toString(){
        std::ostringstream out;
        out <<" -\t";
        for(int i=0; i < authors.size(); ++i){
            out<<authors[i];
            out<<((i==authors.size()-1)?" ":","); //se è l'ultimo autore non mette la virgola
        }
        out <<"("<<year<<")"<<title<<".";
        return out.str();
    }