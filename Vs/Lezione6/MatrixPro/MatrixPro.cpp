/*Given a 2D array A mxn and a 2D array B nxk:
• Compute the matrix product AxB*/
#include <iostream>
#include <array>

using std::array;
using std::cout;
using std::endl;

// defining prefixed size for both matrix
const size_t m = 2;
const size_t n = 3;
const size_t k = 4;

//function prototypes
template <size_t rows, size_t columns>
void printArray(array<array<int, columns>, rows>& matrice);
template <typename T, size_t u, size_t v, size_t w>
// u = rows first matrix, v = column first matrix, rows second matrix, w = column second matrix
void product(array<array<T, v>, u >&A, array<array<T, w>, v>&B);


template <typename T, size_t u, size_t v, size_t w> 
void product(array<array<T, v>, u >&A, array<array<T, w>, v>&B){
	// will be defined a temporary matrix, with the row count of the first matrix and the column count of the second matrix
	//This matrix will be able to host the product between the matrix A and the matrix B
	array<array<T, w>, u> product{0};
	
	// allows to do the product between matrix
	//first two for cycles allows to visit the matrix
	//given a mxn matrix and a nxk matrix, the index will have a max of m for the rows and a max of k for the columns
	// the index uses the 
	for (int i = 0; i<A.size(); i++){
		for(int j = 0; j < B[i].size(); j++){
			
			// the third for cycle allows us to do the product between the row and the column of the two matrix
			// given a mxn matrix and a nxk matrix, the index will pair the column of the first matrix
			// with the row of the second matrix 
			for (int k = 0; k < A[j].size(); k++)
			{
				product[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	printArray(product);
		
}
// prints the array
template <size_t rows, size_t columns>
void printArray(array<array<int, columns>, rows>& matrice)
{
	for(int i = 0; i < matrice.size(); i++){
		for(int j = 0; j < matrice[i].size(); j++) {
			cout << matrice[i][j] << " ";
		}
		cout<<endl;
	}
}

int main(){ // driver
	// array declarations
	array<array<int, n>,m> matrice1{1,2,3,4,5,6};
	array<array<int, k>, n> matrice2{1,2,3,4,5,6,7,8,9,10,11,12};
	
	
	//testing the program
	cout << "Stampa prima matrice \n";
	printArray(matrice1);
	cout <<endl;
	cout << "stampa seconda matrice \n";
	printArray(matrice2);
	
	//checks if the column of the first matrix is equal to the row of the second matrix
	if(matrice1[0].size() == matrice2.size()){
		cout << "\nStampa prodotto tra due matrici \n";
		product(matrice1, matrice2);	
	}	
	
}
/*#include<iostream>
#include<array>
using std::cout;
using std::cin;
using std::array;

const size_t m{2};
const size_t n{3};
const size_t k{4};

template<size_t rows, size_t col>
void printArray(const array<array<int, col>,rows>&);

template<typename T, size_t m, size_t n, size_t k>
void prod(array<array<int,n>,m>& M1, array<array<int,k>,n>&M2);

int main(){
    array<array<int,n>, m> mat1{1,2,3,4,5,6}; //matrice mxn
    array<array<int,k>, n> mat2{1,2,3,4,5,6,7,8,9,1,2,3}; //matrice nxk

    cout<<"La matrice 1 e':\n";
    printArray(mat1);
    cout<<"\nLa matrice 2 e':\n";
    printArray(mat2);

    if(mat1[0].size() == mat2.size()){
		cout << " stampa prodotto tra due matrici \n";
		prod(mat1, mat2);	
	}	




    return 0;
}

template<size_t rows, size_t col>
void printArray(const array<array<int, col>,rows>& a){
    for(auto const& rows : a){
        for(auto const& element: rows){
            cout<<element<< " ";
        }
        cout<<"\n";
    }
}

template<typename T, size_t m, size_t n, size_t k>
void prod(array<array<int,n>,m>& M1, array<array<int,k>,n>&M2){
    array<array<T,k>,m> product{0}; //matrice prodotto riga x colonna
    for(int i=0; i<M1.size(); i++){
        for(int j=0; j<B[i].size(); j++){
            for(int k=0;M1[j].size);k++{
                product[i][j]+=M1[i][k]*M2[k][j];
            }
        }
    }
    printArray(product);
}*/