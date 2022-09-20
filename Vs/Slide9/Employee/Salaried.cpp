#include<iomanip>
#include<stdexcept>
#include<sstream>
#include"Salaried.h"

using std::string;

//costruttore
SalariedEmployee::SalariedEmployee(const string& first, const string& last,
    const string& ssn, double salary)
    :Employee{first,last,ssn} {
        setWeeklySalary(salary);
    }

void SalariedEmployee::setWeeklySalary(double salary){
    if(salary<0.0){
        throw std::invalid_argument("Weekly salary must be >=0.0");
    }
    weekSalary=salary;
}
double SalariedEmployee::getWeeklySalary() const{
    return weekSalary;
}

double SalariedEmployee::earnings() const{
    return getWeeklySalary();
}

string SalariedEmployee::toString() const{
    std::ostringstream output;
    output<<std::fixed<<std::setprecision(2);
    output<<"Salaried Employee:"<<Employee::toString()
        <<"\nWeekly salary: "<<getWeeklySalary();
    return output.str();
}
