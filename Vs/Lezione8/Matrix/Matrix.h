//• Implement a Matrix class that stores a nxm matrix of double
//• Overload sum (+), difference(-) and product(*) operators;
#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
    public:
        //costruttore
        Matrix(int=3, int=3);
        //big three
        Matrix(const Matrix&); //copy constructor
        ~Matrix();
        Matrix& operator=(const Matrix&);

        //operatori
        Matrix operator+(const Matrix&);
        Matrix operator-(const Matrix&);
        Matrix operator*(const Matrix&);

        Matrix& setValue(int, int, double); //setta i valori e restituisce la matrice
       //per abilitare la cascata non mettiamo void
        double getValue(int,int) const;//restiruisce il valore della matrice in una certa posizione
        friend std::ostream& operator<<(std::ostream&, const Matrix& m);
    private:
        int nrow;
        int ncol;
        double** array;
};

#endif