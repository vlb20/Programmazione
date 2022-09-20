#include"WWW.h"
#include<list>
#include<iostream>

WWW::WWW(int n)
:nPages{n}{                  //costruttore
    web = new std::list<int>[n];     //alloco l'array n liste di interi
    for(int i=0; i < n; ++i){
        Page p(i,0,static_cast<double>(1.0)/n); //creo le pagine senza link e con 1/n come peso
        pages.push_back(p); //le metto nel mio vettore di pages
    }
}

//per linkare le varie pagine
void WWW::addLink(int pa, int pb){
    web[pa].push_front(pb);
    if(pa!=pb){ //self links are not counted
        pages[pa].nLink++;
    }
}

void WWW::pageRank(){
    double *newP = new double[nPages];
    for(int i=0; i < nPages; ++i){
        for(auto j=web[i].begin(); j != web[i].end(); ++j){
            if(*j != i && pages[i].nLink != 0){
                newP[*j] += pages[i].P/pages[i].nLink;  //l'i esima pagina deve dare p/nlinks alle pagine di quella lista
            }
        }
    }
    for(int i=0; i<nPages; ++i){
        pages[i].P=(1.0-delta)/nPages + delta*newP[i];
    }
    delete [] newP;
}

void WWW::iteratePageRank(){
    //run pageRank multiple volte fino alla convergenza
    bool convergence{false};
    double* prevP= new double[nPages]; //array in cui memorizzare i rank delle pagine precendenti
    while(!convergence){
        for(int i=0; i<nPages;++i){
            prevP[i]=pages[i].P; //mi conservo l'insieme dei valori contenuti in ogni pagina mettendoli nel vettore prevP
        }
        //run pagerank
        pageRank();
        //check convergence
        //dobbiamo controllare la differenza prima e dopo l'aggiornamento
        double diff=0;
        for(int i=0; i<nPages; ++i){
            diff += (prevP[i]-pages[i].P)*(prevP[i]-pages[i].P);
        }
        std::cout<<"Diff: "<<diff<<std::endl;
        if(diff< 1e-20){ //se la differenza è minore di un valore molto piccolo
            convergence=true;
        }
    }
    delete[] prevP; //rilascio la memoria allocata;
}

void WWW::printRanks(){
    std::cout<<"Internet ranks: "<<std::endl;
    for(int i=0; i<nPages; ++i){
        std::cout<<"Page "<< i << "\t ranks: "<< pages[i].P <<std::endl;
    }
}
