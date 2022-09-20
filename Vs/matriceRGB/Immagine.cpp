Immagine::Immagine(int r, int c){
    nrow = r;
    ncol = c;
    R =new double* [nrow];
    G =new double* [nrow];
    B =new double* [nrow];
    for(int i=0; i<nrow; i++){
        R[i] =new double[ncol]{};
        G[i] =new double[ncol]{};
        B[i] =new double[ncol]{};
    }
}

Immagine::Immagine(const Immagine &I){
    nrow = I.getRow();
    ncol = I.getCol();
    R =new double* [nrow];
    G =new double* [nrow];
    B =new double* [nrow];
    for(int i=0; i<nrow; i++){
        R[i] =new double[ncol]{};
        G[i] =new double[ncol]{};
        B[i] =new double[ncol]{};
    }
    for(int i=0; i<nrow; i++){
        for(int j=0; j<ncol; j++){
            R[i][j] = I.getValueR(i, j);
            G[i][j] = I.getValueG(i, j);
            B[i][j] = I.getValueB(i, j);
        }
    }
}

Immagine& Immagine::operator=(const Immagine &I){
    for(int i{0}; i<nrow; i++){
        delete [] R[i];
        delete [] G[i];
        delete [] B[i]; 
    }
    delete [] R;
    delete [] G;
    delete [] B;
    nrow = I.getRow();
    ncol = I.getCol();
    R =new double* [nrow];
    G =new double* [nrow];
    B =new double* [nrow];
    for(int i=0; i<nrow; i++){
        R[i] =new double[ncol]{};
        G[i] =new double[ncol]{};
        B[i] =new double[ncol]{};
    }
    for(int i=0; i<nrow; i++){
        for(int j=0; j<ncol; j++){
            R[i][j] = I.getValueR(i, j);
            G[i][j] = I.getValueG(i, j);
            B[i][j] = I.getValueB(i, j);
        }
    }
    return *this;
}

Immagine::~Immagine(){
    for(int i{0}; i<nrow; i++){
        delete [] R[i];
        delete [] G[i];
        delete [] B[i]; 
    }
    delete [] R;
    delete [] G;
    delete [] B;
}

void Immagine::filter(){
    //media matrici
    if(nrow%2==0 || ncol%2==0){
        throw std::invalid_argument("Queste matrici non hanno un centro!");
    }
    int numero = nrow*ncol;
    double totaleR{0}, mediaR{0};
    double totaleG{0}, mediaG{0};
    double totaleB{0}, mediaB{0};
    for(int i{0}; i<nrow; i++){
        for(int j{0}; j<ncol; j++){
            totaleR += R[i][j];
            totaleG += G[i][j];
            totaleB += B[i][j];
        }
    }
    mediaR = totaleR/numero;
    mediaG = totaleG/numero;
    mediaB = totaleB/numero;

    //inseriamo la media al posto del centro
    int centroR = (nrow/2);
    int centroC = (ncol/2);
    setValueR(centroR, centroC, mediaR);
    setValueG(centroR, centroC, mediaG);
    setValueB(centroR, centroC, mediaB);
}

std::string Immagine::toString() const{
    std::ostringstream out;
    out <<"Matrice R:\n";
    for(int i{0}; i<nrow; i++){
        for(int j{0}; j<ncol; j++){
            out <<"[" <<R[i][j] <<"]";
        }
        out <<"\n";
    }
    out <<"\nMatrice G:\n";
    for(int i{0}; i<nrow; i++){
        for(int j{0}; j<ncol; j++){
            out <<"[" <<G[i][j] <<"]";
        }
        out <<"\n";
    }
    out <<"\nMatrice B:\n";
    for(int i{0}; i<nrow; i++){
        for(int j{0}; j<ncol; j++){
            out <<"[" <<B[i][j] <<"]";
        }
        out <<"\n";
    }
    return out.str();
}