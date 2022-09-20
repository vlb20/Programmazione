#include "Sensor.h"

Sensor::Sensor(int id, int x ,int y):
    id_sensor{id}, coord_x{x}, coord_y{y} {}

void Sensor::insertMeasurement(Date d, double mes){
    Measurment m(d,mes);
    //measures.push_back(m);
    //devo scorrere la lista e trovare la prima misura che ha la data maggiore di quella da inserire (m)
    auto cursor = measures.begin();
    auto end = measures.end();
    while(cursor!=end){
        Measurment tmp=*cursor; //oggetto corrente che voglio confrontare
        if(d < tmp.d){
            break;
        }
        cursor++;
    }//cursor i da la posizione in cui inserire l'oggetto
    measures.insert(cursor,m);
}

double Sensor::meanPPMInterval(Date d1, Date d2){ //calcolo la media delle ppm
    double sum{0.0};
    int count {0};
    for(auto curs=measures.begin(); curs != measures.end(); ++curs){
        Measurment m=*curs; //misura attuale
        if(d1 < m.d && m.d < d2){ //se è compreso nell'intervallo temporale
            sum += m.ppm;
            count++;
        }
        if(d2 < m.d) break;
    }
    if(count>0){
        return sum/count; //media
    }else return 0.0;
}