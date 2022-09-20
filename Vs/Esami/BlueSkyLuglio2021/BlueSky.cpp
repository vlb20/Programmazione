#include "BlueSky.h"
#include <vector>

double BlueSky::meanCO2Zone(int x_u_l, int y_u_l, 
    int x_l_r, int y_l_r, Date d1, Date d2){
        int count{0};
        double sum{0.0};
        double mean{0.0}; //media
        for(int i=0; i < sensors.size(); ++i){
            //check if sensors[i] is in the zone
            int x = sensors[i].getX();
            int y = sensors[i].getY();
            if(x>=x_u_l && y>=y_u_l && x<=x_l_r && y<y_l_r){
                sum += sensors[i].meanPPMInterval(d1,d2);
                count++;
            }
        }
        if(count > 0){
            mean=sum/count;
            return mean;
        }else{
            return 0.0;
        }
    }

void BlueSky::addMeasurment(int id, Date d, double m){
    sensors[id].insertMeasurement(d,m);
}

void BlueSky::addSensor(int x, int y){
    Sensor s(n_sensors,x,y);
    sensors.push_back(s);
    n_sensors ++;
}