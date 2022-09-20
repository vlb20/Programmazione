#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "Salaried.h"
#include "Commission.h"
#include "BasePlus.h"
using std::cout;
using std::vector;
void virtualViaPointer(const Employee* const);
void virtualViaReference(const Employee&);

int main(){
    cout<<std::fixed<<std::setprecision(2);

    SalariedEmployee salariedEmployee{
        "Cristina", "Carleo", "222-22-2222", 800};
    CommissionEmployee commissionEmployee{
        "Vincenzo Luigi", "Bruno", "201-20-2020", 10000, .06};
    BasePlusComEmp basePlusComEmp{
        "Damiano", "Bruno", "777-77-7777", 5000, .04, 300};

    cout<<"EMPLOYED PROCESSED INDIVIDUALLY USING STATIC BINDING\n"
        << salariedEmployee.toString()
        <<"\nearned $"<< salariedEmployee.earnings()<<"\n\n"
        << commissionEmployee.toString()
        <<"\nearned $"<< commissionEmployee.earnings()<<"\n\n"
        <<basePlusComEmp.toString()
        <<"\nearned $"<< basePlusComEmp.earnings()<<"\n\n";

    //creo e inizializzio un vettore di tre base-class puntatori
    vector<Employee*> employees{&salariedEmployee, &commissionEmployee,
        &basePlusComEmp};

    cout<<"EMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNAMIC BINDING\n\n";

    cout<<"VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS POINTERS\n";
    for(const Employee* employeePtr : employees){
        virtualViaPointer(employeePtr);
    }

    cout<<"VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCES\n";
    for(const Employee* employeePtr: employees){
        virtualViaReference(*employeePtr);
    }
}

//dynamic binding
void virtualViaPointer(const Employee* const baseClassPtr){
    cout<< baseClassPtr->toString()
        <<"\nearned $"<<baseClassPtr->earnings()<<"\n\n";
}

void virtualViaReference(const Employee& baseClassRef){
    cout<<baseClassRef.toString()
        <<"\nearned $"<<baseClassRef.earnings()<<"\n\n";
}
