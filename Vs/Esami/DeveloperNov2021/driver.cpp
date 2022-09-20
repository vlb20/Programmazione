#include"Date.h"
#include"Progetto.h"
#include"Programmatori.h"
#include"Tasks.h"
#include<vector>
#include<iostream>
#include<list>
#include<string>
#include<sstream>
#include<algorithm>
using std::vector;
using std::string;

void insertProgrammatore(vector<Programmatore*>&, Programmatore&);
std::string printVector(vector<Programmatore*>& );

int main(){
    vector<Programmatore*> programmatori;
    Programmatore p1{"Vincenzo Luigi Bruno", 20};
    Programmatore p2{"Cristina Carleo", 50};
    Programmatore p3{"Francesco Balassone", 30};
    insertProgrammatore(programmatori,p1);
    insertProgrammatore(programmatori,p2);
    insertProgrammatore(programmatori,p3);

    std::list<Task> tsk;
    Task BlueSky{ "BlueSky", {21,6,2021}, 30, p1};
    Task Fantaland{ "Fantaland", {22,7,2021}, 25, p2};
    Task Mobilificio{"Mobilificio", {18,9,2021}, 25, p1};
    Task Tavoli{ "Tavoli rettangolari, rotondi e triangolari", {25,1,2022}, 40, p3};
    
    Progetto pr("Esami Programmazione","Michele Ceccarelli",44.4, tsk);
    pr.insertTask(BlueSky);
    pr.insertTask(Fantaland);
    pr.insertTask(Mobilificio);
    pr.insertTask(Tavoli);
    std::cout<<pr.toString()<<std::endl;
    std::cout<<printVector(programmatori)<<std::endl;
    
    std::cout<<"\nCalcolando le ore di "<<p1.getNome();
    std::cout<<"\nQueste sono:"<<pr.workloadDeveloper(p1);

    
    return 0;
}
void insertProgrammatore(vector<Programmatore*>& A, Programmatore& p){
    A.push_back(&p);
    std::sort(A.begin(),A.end());
}
std::string printVector(vector<Programmatore*>& A){
    std::ostringstream out;
    out<<"I Programmatori sono: \n";
    for(int i=0; i<A.size(); i++){
        out<<A[i]->toString()<<"\n";
    }
    return out.str();
}
