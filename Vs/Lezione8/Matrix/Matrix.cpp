#include "Matrix.h"
#include<stdexcept>
#include<iostream>

//costruttore
Matrix::Matrix(int r, int c){
    nrow=r;
    ncol=c;
    array=new double* [nrow];
    for(int i=0; i<r; i++){
        array[i]=new double[ncol]{};//inizializzo a 0
    }
}

//copy constructor
Matrix::Matrix(const Matrix& m){
    nrow=m.nrow;
    ncol=m.ncol;

    array=new double* [m.nrow];
    for(int i=0; i<nrow; ++i){
        array[i]=new double[ncol];
    }
    for(int i=0; i<nrow; ++i){
        for(int j=0; j<ncol; ++j){
            array[i][j]=m.array[i][j];
        }
    }
}

//distruttore
//cancello prima le colonne e poi le righe
Matrix::~Matrix(){
    for(int i=0; i<nrow; ++i){
        delete[] array[i];
    }
    delete[] array;
}

//operatore=
Matrix& Matrix::operator=(const Matrix& m){
    if(this==&m){
        return *this;
    }

    //release memory
    for(int i=0; i<nrow; ++i){
        delete[] array[i];
    }
    delete[] array;

    nrow=m.nrow;
    ncol=m.ncol;
    array=new double*[m.nrow];
    for(int i=0; i<nrow; i++){
        array[i]=new double[m.ncol];
    }
    for(int i=0; i<nrow; ++i){
        for(int j=0; j<ncol; ++j){
            array[i][j]=m.array[i][j];
        }
    }
    return *this;
}

//operatore +
Matrix Matrix::operator+(const Matrix& m){
    if(nrow != m.nrow || ncol != m.ncol){
        throw std::invalid_argument{"Le matrici devono avere le stesse dimensioni"};
    }
    Matrix newMat{m};
    for(int i=0; i<nrow; i++){
        for(int j=0; j<ncol; j++){
            newMat.array[i][j] += array[i][j];
        }
    }
    return newMat;
}

Matrix Matrix::operator*(const Matrix& m){
    if(ncol != m.nrow){
        throw std::invalid_argument{"La matrici devono avere dimensioni compatibili"};
    }
    Matrix newMat(nrow, m.ncol);
    for(int i=0; i<nrow; i++){
        for(int k=0; k<m.ncol; ++k){
            newMat.array[i][k]=0.0;
            for(int j=0; j<ncol; j++){
                newMat.array[i][k]+=array[i][j]*m.array[j][k];
            }
        }
    }
}
/*
Matrix Matrix::operator-(const Matrix& m){
    if(ncol==m.ncol && nrow==m.nrow){
        for(int i=0; i<m.nrow; ++i){
            for(int j=0; j<m.ncol; ++j){
                array[i][j]=array[i][j]-m.array[i][j];
            }
        }
        return *this;
    }
    else throw std::invalid_argument("Le matrici devono avere le stesse dimensioni");
}*/

Matrix& Matrix::setValue(int r, int c, double e){
    array[r][c]=e;
    return *this;
}

double Matrix::getValue(int r, int c) const{
    return array[r][c];
}

std::ostream& operator<<(std::ostream& out, const Matrix& m){
    for(int i=0; i<m.nrow; ++i){
        for(int j=0; j<m.ncol; ++j){
            out<<m.getValue(i,j)<<"\t";
        }
        out<<"\n";
    }
    return out;
}
