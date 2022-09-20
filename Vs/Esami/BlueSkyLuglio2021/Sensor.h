#ifndef SENSOR_H
#define SENSOR_H
#include<list>
#include"Date.h"

class Sensor{
public:
    class Measurment{
        public:
            Measurment(Date data, double mes): d{data}, ppm{mes} {}
            friend class Sensor;
        private:
            Date d;
            double ppm;
    };
    Sensor(int, int, int);
    void insertMeasurement(Date d, double mes);
    double meanPPMInterval(Date d1, Date d2);
    int getX(){return coord_x;}
    int getY(){return coord_y;}
private:
    int id_sensor;
    int coord_x;
    int coord_y;
    std::list<Measurment> measures; 
};

#endif