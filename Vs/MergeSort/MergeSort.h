#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::vector;

//merge
template<typename T>
void merge(vector<T>&A, int p, int r, int q){
    int i,j,k;
    static vector<T> c(A.size());
    i=p;
    k=p;
    j=q+1;
    while(i<=q && j<=r){
        if(A[i]<A[j]){
            c[k]=A[i];
            k++;
            i++;
        }
        else{
        c[k]=A[j];
        k++;
        j++;
        }
    }
    while(i<=q){
        c[k]=A[i];
        k++;
        i++;
    }
    while(j<=q){
        c[k]=A[j];
        k++;
        j++;
    }
    for(i=p;i<k;i++){
        A[i]=c[i];
    }
}

//mergesort
template<typename T>
void mergeSort(vector<T>& A, int p, int r){
    int q;
    if(p<r){
        q=(p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,r,q);
    }
}