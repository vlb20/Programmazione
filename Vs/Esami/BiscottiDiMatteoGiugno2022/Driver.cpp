#include "Azienda.h"
#include <iostream>
using std::cout;

int main()
{
    Azienda a;
    cout<<a.toString();
    a.buildGrafo();
    cout<<a.displayGrafo();
    cout<<a.cluster(2);
}