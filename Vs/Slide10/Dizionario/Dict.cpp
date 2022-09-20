#include"Dict.h"
using std::string;

Word::Word(string eng, string it)
    : engWord(eng), itWord(it) {}

void Word::setEngWord(string word){
    engWord=word;
}
string Word::getEngWord(){
    return engWord;
}

void Word::setItWord(string word){
    itWord=word;
}
string Word::getItWord(){
    return itWord;
}
