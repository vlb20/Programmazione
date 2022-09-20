#include "BlueSky.h"
#include "Sensor.h"
#include "Date.h"
#include<iostream>
#include<vector>

int main(){
    BlueSky myBlueSky;
    myBlueSky.addSensor(5,5);
    myBlueSky.addSensor(5,6);
    myBlueSky.addSensor(6,6);
    myBlueSky.addSensor(7,5);
    myBlueSky.addSensor(7,7);

    myBlueSky.addMeasurment(0,Date(1,1,2021),0.5);//aggiungo al primo sensore una data e una misura
    myBlueSky.addMeasurment(0,Date(2,1,2021),0.7);
    myBlueSky.addMeasurment(0,Date(3,1,2021),0.9);
    myBlueSky.addMeasurment(0,Date(4,1,2021),0.4);

    myBlueSky.addMeasurment(1,Date(1,1,2021),0.8);
    myBlueSky.addMeasurment(1,Date(2,1,2021),1.0);
    myBlueSky.addMeasurment(1,Date(3,1,2021),0.5);

    myBlueSky.addMeasurment(2,Date(1,1,2021),0.5);
    myBlueSky.addMeasurment(2,Date(2,1,2021),0.2);
    myBlueSky.addMeasurment(2,Date(3,1,2021),0.6);
    myBlueSky.addMeasurment(2,Date(4,1,2021),0.9);
    myBlueSky.addMeasurment(2,Date(5,1,2021),0.8);

     double media = myBlueSky.meanCO2Zone(4,4,6,6,Date(1,1,2021),Date(4,1,2021));
    std::cout<<"Media:"<<media<<std::endl;
    return 0;
}