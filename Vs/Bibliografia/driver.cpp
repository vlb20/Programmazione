#include"Publication.h"
#include"Book.h"
#include"JournalPaper.h"
#include"ConfPaper.h"
#include"quickSort.h"
#include<iostream>
#include<vector>
#include<string>

//bool comparePubPtr(Publication* A, Publication* B) {return *A < return *B}
//se vogliamo usare il sort di alghorithm al posto di quicksort
//std::sort(bib.begin(),bib.end(),comparePubPtr);


int Book::nBooks{0}; //inizializzo la variabile
int JournalPaper::nJournalP{0};
int ConfPaper::nConfP{0};
int main(){
    std::vector<Publication*> bib; //vettore di riferimenti a pubblicazioni
    Publication P1({"Herman Hesse","Hermanno Hesse"},"Siddharta",1922);
    Book b1({"Cristina Carleo","Cecilia Carleo"},"Turbolenze",2017,"CC22-CC06","InstaPublisher");
    Book b2({"VLB"},"AO",2022,"VLB20-VL01","AOAOEDIT");
    JournalPaper j1({"Vincenzo Lippiello"},"RoboPizza",2016,"AlmaLaurea", 2828, 1, 228);
    ConfPaper c1({"Damiano Bruno, Francesco Viola"},"Ping-Pong master",2020,"ATP MASTER", "Latronico", 300);
    
    bib.push_back(&P1);
    bib.push_back(&b1);
    bib.push_back(&b2);
    bib.push_back(&j1);
    bib.push_back(&c1);
    quickSort(bib,0,bib.size()-1);
    for(int i=0; i<bib.size(); ++i){
        std::cout<< bib[i]->toString()<<std::endl;
    }
    std::cout<<"Numero di libri nella bibliografia: "<<Book::nBooks <<std::endl;
    std::cout<<"Numero di articoli su riviste nella bibliografia: "<<JournalPaper::nJournalP<<std::endl;
    std::cout<<"Numero di articoli su atti di convegni nella bibliografia: "<<ConfPaper::nConfP<<std::endl;



    return 0;
}