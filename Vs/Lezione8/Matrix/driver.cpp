#include"Matrix.h"
#include<iostream>
#include<cstdlib>
using std::cout;
using std::endl;

int main(){
    int r=4;
    int c=4;
    Matrix matA(r,c);
    Matrix matB(r,c);
    Matrix matC(r,c);
    Matrix matE(r,c);
    srand(1);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            matA.setValue(i,j,1.1);
            matB.setValue(i,j,static_cast<double> (rand()&100)/100);
        }
    }
    cout<<matA;
    cout<<"Matrice A"<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<matA.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Matrice B"<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<matB.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Matrice C prima dell'addizione"<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<matC.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

    Matrix matD=matA*matB;
    cout<<"matrice D dopo la moltiplicazione"<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<matD.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }
    matE=matA;
}


