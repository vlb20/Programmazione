/*• Doctors suggest individuals exercise to stay healthy and that they monitor their heart rate while exercising to
ensure that they are not doing too much or too little. The Maximal Heart rate (MHR) is a guideline that is used
to indicate when an individual should ease off a little. The equation that is commonly used is
220 − age = Maximum Heart Rate (MHR)
• This formula was empirically derived from young athletes. A broader age distribution in a study by Tanaka in
2001 showed that this formula often underestimated the MHR in older subjects. Hence the formula
MHR = 208 − 0.7(age)
• Gellish in 2007 showed good correlation to stress-testing results using
MHR = 207 − 0.7(age)
and a later study by Nes et al in 2012 suggested that the equation be
MHR = 211 − 0.64(age)
Write a program that requests the user to enter their age and then displays the suggested
• MHR values using each of these equations. As a conclusion, suggest the range of values that the user should
consider by displaying the smallest and largest MHR values calculated. Test your pro-gram by entering several
ages that are a few decades apart. (Take a look at “Age-predicted maximal heart rate in healthy subjects: The
HUNT Fitness Study” published in the Scandinavian Journal of Medicine and Science in Sports for a discussion
about these MHR equatio*/

#include<iostream>

using std::cout;
using std::cin;

int main(){
    int age{0};
    float MHR{0};

    cout<<"Inserisci eta':"<<std::endl;
    cin>>age;

    MHR=220-age;
    float max=MHR;
    float min=MHR;

    //Tanaka's Formula
    MHR=208-(0.7*age);
    
    if(MHR<min){
        min=MHR;          
    }
    if(MHR>max){
        max=MHR;        
    }
    //formula di gellish
    MHR=207-(0.7*age);
    if(MHR<min){
        min=MHR;          
    }
    if(MHR>max){
        max=MHR;        
    }

    //formula di Nes
    MHR=211-(0.64*age);

    if(MHR<min){
        min=MHR;          
    }
    if(MHR>max){
        max=MHR;        
    }
    

    cout<<"Il range di valori consigliato e':"<<" "<<"MAX:"<<max<<" "<<"MIN:"<<min;




    return 0;
}
