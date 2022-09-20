#ifndef JOURNALPAPER_H
#define JOURNALPAPER_H

#include "Publication.h"
#include<string>
#include<vector>

class JournalPaper: public Publication{
public:
    static int nJournalP;
    JournalPaper(std::vector<std::string>, std::string, int, std::string, int, int, int);
    ~JournalPaper();

    const std::string& getJournalTitle();
    JournalPaper& setJournalTitle(const std::string&);
    const int getNumber();
    void setNumber(const int);
    const int getInPage();
    void setInPage(const int);
    const int getEndPage();
    void setEndPage(const int);

    std::string toString(); //override

private:
    std::string journalTitle;
    int number;
    int inPage;
    int endPage;

};

#endif