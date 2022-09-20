#include "JournalPaper.h"
#include<string>
#include<sstream>
#include<vector>

JournalPaper::JournalPaper(std::vector<std::string> au, std::string ti, int yr, std::string jti, int num, int in, int end):
    Publication::Publication(au,ti,yr), journalTitle{jti}, number{num}, inPage{in}, endPage{end} {++nJournalP;}

JournalPaper::~JournalPaper(){
    --nJournalP;
}

const std::string& JournalPaper::getJournalTitle(){return journalTitle;}
JournalPaper& JournalPaper::setJournalTitle(const std::string& jti){
    journalTitle=jti;
    return *this;
}

const int JournalPaper::getNumber(){return number;}
void JournalPaper::setNumber(const int num){
    number=num;
}

const int JournalPaper::getInPage(){return inPage;}
void JournalPaper::setInPage(const int in){
    inPage=in;
}

const int JournalPaper::getEndPage(){return endPage;}
void JournalPaper::setEndPage(const int end){
    endPage=end;
}

std::string JournalPaper::toString(){
    std::ostringstream out;
    out<<Publication::toString();
    out<<" "<<journalTitle<<" "<<number<<" Pagina iniziale:"<<inPage<<" -  Pagina finale:"<<endPage<<std::endl;
    return out.str();
}