/*Write a program that takes a binary sequence in input and
outputs its’ decimal equivalent*/
#include<iostream>
#include<cmath>


using std::cout;
using std::cin;

int main(){
	int dec=0;
	int bin;
	int i=0;

	cout<<"Inserisci il numero da convertire da binario a decimale:";
	cin>>bin;

	while(bin>0){
		if(bin%10!=0){ //siamo in presenza di un 1
			dec=dec+pow(2,i);
		}

		bin=bin/10;
		i++;
	}
	cout<<"\n\n\nConvertendo...";
	cout<<"\nLa sequenza in decimale e':"<<dec;

}
/*
int main () {
	int d=0,b,n;
	
	cout<< "Inserisci il numero di bit da convertire: ";
	cin>>n;	
	
	while (n!=0) {

		do{
			cout<< "Inserisci il  bit solo 0 o 1: ";
			cin>>b;
		} while(b==0 && b==1);

		d=d*2+b; //aggiorniamo ogni volta d
		n--;		
	}

	cout<<"Valore decimale: "<<d<<std::endl;
	
}*/
