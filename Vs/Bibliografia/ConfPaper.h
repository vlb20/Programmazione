#ifndef CONFPAPER_H
#define CONFPAPER_H
#include"Publication.h"
#include<string>
#include<vector>

class ConfPaper: public Publication{
public:
    static int nConfP;
    ConfPaper(std::vector<std::string>, std::string, int, std::string, std::string, int);
    ~ConfPaper();

    const std::string& getConfTitle();
    ConfPaper& setConfTitle(const std::string&);
    const std::string& getSedeConf();
    ConfPaper& setSedeConf(const std::string&);
    const int getNPages();
    void setNPages(const int);
    

    std::string toString(); //override

private:
    std::string confTitle;
    std::string sedeConf;
    int nPages;

};

#endif