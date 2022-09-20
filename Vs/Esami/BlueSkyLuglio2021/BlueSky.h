#ifndef BLUESKY_H
#define BLUESKY_H
#include"Sensor.h"
#include"Date.h"
#include<vector>

class BlueSky{
public:
    BlueSky(){n_sensors=0;}
    double meanCO2Zone(int, int, int, int, Date, Date);//cordinate del quariere in alto a sinsitra e basso a destra + date
    void addMeasurment(int, Date, double);
    void addSensor(int, int);

private:
    int n_sensors;
    std::vector<Sensor> sensors;
};


#endif