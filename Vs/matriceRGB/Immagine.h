#ifndef IMMAGINE_H
#define IMMAGINE_H
#include <stdexcept>
#include <sstream>
#include <string>

class Immagine{
    public:
        Immagine(int = 3, int = 3); //costruttore
        Immagine(const Immagine&); //costruttore copia
        Immagine& operator=(const Immagine&); //operatore assegnazione 
        ~Immagine(); //distruttore

        //help set-get
        void setRow(int r){nrow = r; }
        void setCol(int c){ncol = c; }
        void setValueR(int r, int c, double val){R[r][c] = val; }
        void setValueG(int r, int c, double val){G[r][c] = val; }
        void setValueB(int r, int c, double val){B[r][c] = val; }
        int getRow() const{return nrow; }
        int getCol() const{return ncol; }
        double getValueR(int r, int c) const{return R[r][c]; }
        double getValueG(int r, int c) const{return G[r][c]; }
        double getValueB(int r, int c) const{return B[r][c]; }

        void filter();
        std::string toString() const;
    private:
        int nrow;
        int ncol;
        double **R;
        double **G;
        double **B;
};

#include "Immagine.cpp"
#endif