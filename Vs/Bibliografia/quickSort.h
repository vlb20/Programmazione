#include <vector>

template<typename Q>
void quickSort(std::vector<Q>&A, int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort(A,p, q);
        quickSort(A,q+1,r);
    }
}
template<typename Q>
int partition(std::vector<Q>&A, int p, int r){
    int i = p-1;
    int j = r+1;
    Q x = A[p];
    while (true) //while i<j
    {   
        do {j=j-1;} while (*x<*A[j]);//NOTA BENE: per tipi elementari togliere gli asterischi

        do {i=i+1;} while (*A[i]<*x);//NOTA BENE: per tipi elementari togliere gli asterischi

        if(i < j){swap(A, i,j);}

        else {return j;}
    }
    
}
template<typename Q>
void swap(std::vector<Q>& A,int i,int j){
    Q temp= A[i];
    A[i]=A[j];
    A[j]=temp;
}

template<typename Q>
void quickSort(std::vector<Q>&A){quickSort(A, 0, A.size()-1);}
