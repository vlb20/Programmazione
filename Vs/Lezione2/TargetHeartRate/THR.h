/*• While exercising, you can use a heart-rate monitor to see that your heart rate
stays within a safe range suggested by your trainers and doctors. According to the
American Heart Association (AHA) (http://bit.ly/AHATargetHeartRates), the formula
for calculating your maximum heart rate in beats per minute is:
220 - age.
• Your target heart rate is a range that’s 50–85% of your maximum heart rate. [
• Create a class called HeartRates. The class attributes should include the person’s
first name, last name and date of birth
• Your class should have a constructor that receives this data as parameters. For
each attribute provide set and get functions.
• The class also should include a member function that calculates and returns the
person’s age (in years), a member function that calculates and returns the person’s
maximum heart rate and a member function that calculates and returns the person’s
target heart rate.
• Write a program that prompts for the person’s information, instantiates an object
of class HeartRates and prints the information from that object—including the
person’s first name, last name and date of birth—then calculates and prints the
person’s age in (years), max-imum heart rate and target-heart-rate range.*/
#ifndef THR_H
#define THR_H


#include<iostream>
#include<string>
#include"Date.h"

class HeartRates{
    public:
        
        HeartRates(std::string fname, std::string lname, int=0, int=0, int=0);

        void setFname(std::string fname);
        void setLname(std::string lname);
        void setDate(int, int, int);
        std::string getFname();
        std::string getLname();
        void getDate();

        int ageCalc();
        float mhrCalc();
        float thrMin();
        float thrMax();
        void displayThr();
        void displayInfo();



    private:
        std::string firstName;
        std::string lastName;
        Date data;
        float MHR;
        float min;
        float max;
        int age;


};

#endif 