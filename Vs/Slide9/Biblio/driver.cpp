#include "Publication.h"
#include "Book.h"
#include "quickSort.h"
#include <iostream>

int Book::nBooks = 0;
int main(){
    std::vector<Publication*>bib;

    bib.push_back(new Publication({"Cristina Carleo", "Cecilia Carleo"},"Turbolenze", 2019) );
    bib.push_back(new Book({"Aho ALbert, Jeoffrye Horcroft", "Ullman"}, "Introduction to Computer Algorithms", 1974, "98981981", "prentice All"));
    bib.push_back(new Book({"Damiano Bruno"}, "I problemi", 2019, "98972006", "Mondadori"));

    quickSort(bib,0,bib.size()-1);// oppure std::sort(bib.begin(), bib.end(), comparePubsPtr);
    for(int i=0; i<bib.size(); ++i){
        std::cout<<bib[i]->toString()<< std::endl;
    }
    std::cout<<"Numero di libri nella bibliografia:"<< Book::nBooks << std::endl;
}

/* Per usare il sort della libreria <alghoritm> invece del quicksort
bool comparePubsPtr(Publication* A, Publication* B) {return *A < *B}*/
