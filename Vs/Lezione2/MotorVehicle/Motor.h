/*• Create a class called MotorVehicle that represents a motorvehicle using: make (type string), fuelType (type string),
yearOfManufacture (type int), color (type string) and engineCapacity (type int).
• Your class should have a constructor that initializes the three data members. 
Provide a set and a get function foreach data member. 
Add a member function called displayCarDetails that displays the five data members in
five separate lines in the form "member name: membervalue". 
Write a test program to demonstrate MotorVehicle’s capabilities.*/

#include<string.h>
#include<iostream>

class MotorVehicle{
    public:
        MotorVehicle();
        
        MotorVehicle(std::string m, std::string fuel, int year, std::string c, int Ecapacity);

        void setMake(std::string m);
        std::string getMake();

        void setFuel(std::string fuel);
        std::string getFuel();

        void setYear(int year);
        int getYear();

        void setColor(std::string c);
        std::string getColor();

        void setECapacity(int Ecapacity);
        int getECapacity();

        void displayCarDetails();

    private:
        std::string make;
        std::string fuelType;
        int yearOfManufacture;
        std::string color;
        int engineCapacity;


};