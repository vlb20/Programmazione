/*A right triangle can have sides whose lengths are all integers. 
The set of three integer values for the lengths of the sides of a right triangle is called a Pythagorean triple.
The lengths of the three sides must satisfy the relationship that the sum of the squares of two of the sides is equal
to the square of the hypotenuse. Write an application that displays a table of the Pythagorean triples for side1, side2 
and the hypotenuse, all no larger than 500. Use a triple-nested for loop that tries all possibilities. 
This is an example of “brute-force” computing. You’ll learn in more advanced computer-science courses 
that for many interesting problems there’s no known al-gorithmic approach other than using sheer brute force.*/
#include<iostream>

using std::cout;
using std::cin;

int main(){
    int countTriple{0};

    for(unsigned long side1=1;side1<500;side1++){
        for(unsigned long side2=side1;side2<500;side2++){
            for(unsigned long hyp=side2;hyp<500;hyp++){
                long int squareHyp=hyp*hyp;
                long int sides=(side1*side1)+(side2*side2);

                if(squareHyp==sides){
                    countTriple++;
                    cout<<"Tripletta->"<<"Hyp:"<<hyp<<"--Sides:"<<side1<<" "<<side2<<std::endl;
                }
            }
        }
    }

    cout<<"Le triplette trovate sono:"<<countTriple;
}
