#include <iostream>
#include<list>
#include<string>

int main(){
    std::list<std::string> Resistenza;
    std::list<std::string>::iterator it;

    Resistenza.push_front("Cristina");
    Resistenza.push_front("VLB");
    Resistenza.push_back("Giggi");
    Resistenza.push_back("Teresa");
    Resistenza.push_back("Peppe");
    Resistenza.push_back("Gaia");
    Resistenza.push_back("MC");
    Resistenza.push_back("Simone");
    Resistenza.push_back("Carmine");
    Resistenza.push_back("Cunc");
    Resistenza.push_back("Balassone");
    Resistenza.push_back("Giorgio");
    Resistenza.push_back("Nello");

    std::cout<<"RESISTENZA:\n\n";
    for(it=Resistenza.begin(); it != Resistenza.end(); it++)
        std::cout<<*it<<std::endl;
    
    Resistenza.pop_back();
    Resistenza.pop_back();
    Resistenza.pop_back();
    Resistenza.pop_back();
    Resistenza.sort();
    std::cout<<"\n---Mettiamo ordine---"<<std::endl;
    std::cout<<"---FFDS---"<<std::endl;
    for(it=Resistenza.begin(); it!=Resistenza.end(); it++)
        std::cout<<*it<<std::endl;
}