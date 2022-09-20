#include <iostream>
#include<string>
#include "THR.h"
#include "Date.h"

using std::cin;
using std::cout;

int main(){
    
    HeartRates paz{"Vincenzo Luigi","Bruno",10,20,2001};
    paz.ageCalc();
    paz.mhrCalc();
    paz.thrMin();
    paz.thrMax();
    paz.displayThr();
    paz.displayInfo();
    





    return 0;
}