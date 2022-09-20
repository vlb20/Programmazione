#include <iostream>
#include "Immagine.h"

int main(){
    Immagine i1(5, 5);
    i1.setValueR(2, 2, 13.2);
    i1.setValueB(1, 1, 12);
    std::cout <<i1.toString() <<std::endl;

    i1.filter();
    std::cout <<i1.toString() <<std::endl;

    Immagine i2(i1);
    std::cout <<"Immagine due:\n" <<i1.toString();
    return 0;
}