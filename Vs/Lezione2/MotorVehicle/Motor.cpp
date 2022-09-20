#include<iostream>
#include<string.h>
#include "Motor.h"
MotorVehicle::MotorVehicle(){}

MotorVehicle::MotorVehicle(std::string m, std::string fuel, int year, std::string c, int Ecapacity)
    :make{m}, fuelType{fuel}, yearOfManufacture{year}, color{c}, engineCapacity{Ecapacity}{

    }

void MotorVehicle::setMake(std::string m){
    make=m;
}
std::string MotorVehicle::getMake(){
    return make;
}

void MotorVehicle::setFuel(std::string fuel){
    fuelType=fuel;
}
std::string MotorVehicle::getFuel(){
    return fuelType;
}

void MotorVehicle::setYear(int year){
    if(year>1885){
        yearOfManufacture=year;
    }
}
int MotorVehicle::getYear(){
    return yearOfManufacture;
}

void MotorVehicle::setColor(std::string c){
    color=c;
}
std::string MotorVehicle::getColor(){
    return color;
}

void MotorVehicle::setECapacity(int ECapacity){
    if(ECapacity>0)
    engineCapacity=ECapacity;
}
int MotorVehicle::getECapacity(){
    return engineCapacity;
}

void MotorVehicle::displayCarDetails(){
    std::cout<<"MARCA:"<<make<<std::endl;
    std::cout<<"CARBURANTE:"<<fuelType<<std::endl;
    std::cout<<"ANNI DI MANIFATTURA:"<<yearOfManufacture<<std::endl;
    std::cout<<"COLORE:"<<color<<std::endl;
    std::cout<<"ENGINE CAPACITY:"<<engineCapacity<<std::endl;
}
