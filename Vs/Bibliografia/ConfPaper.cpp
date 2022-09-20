#include"ConfPaper.h"
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

ConfPaper::ConfPaper(std::vector<std::string> au, std::string ti, int yr, std::string cti, std::string sede,int num):
    Publication::Publication(au,ti,yr), confTitle{cti}, sedeConf{sede},nPages{num} {++nConfP;}

ConfPaper::~ConfPaper(){
    --nConfP;
}

const std::string& ConfPaper::getConfTitle(){return confTitle;}
ConfPaper& ConfPaper::setConfTitle(const std::string& cti){
    confTitle=cti;
    return *this;
}

const std::string& ConfPaper::getSedeConf(){return sedeConf;}
ConfPaper& ConfPaper::setSedeConf(const std::string& sede){
    sedeConf=sede;
    return *this;
}

const int ConfPaper::getNPages(){return nPages;}
void ConfPaper::setNPages(const int num){
    nPages=num;
}

std::string ConfPaper::toString(){
    std::ostringstream out;
    out<<Publication::toString();
    out<<" "<<confTitle<<" "<<sedeConf<<" Pagine:"<<nPages<<std::endl;
    return out.str();
}