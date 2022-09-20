#include<iomanip>
#include<stdexcept>
#include<sstream>
#include"BasePlus.h"
using std::string;
using std::ostringstream;
using std::fixed;
using std::setprecision;
using std::invalid_argument;

//costruttore
BasePlusComEmp::BasePlusComEmp( const string& first, const string& last,
    const string& ssn, double sales, double rate, double salary)
    : CommissionEmployee{first,last,ssn,sales,rate}{
        setBaseSalary(salary);
    }

void BasePlusComEmp::setBaseSalary(double salary){
    if(salary<0.0){
        throw invalid_argument("Salary must be>0.0");
    }
    baseSalary=salary;
}
double BasePlusComEmp::getBaseSalary() const{
    return baseSalary;
}

double BasePlusComEmp::earnings() const{
    return getBaseSalary() + CommissionEmployee::earnings();
}

string BasePlusComEmp::toString() const{
    ostringstream output;
    output<<fixed<<setprecision(2);
    output<<"Base salaried:"<<CommissionEmployee::toString()
        <<": Base salary: "<<getBaseSalary();
    return output.str();
}

