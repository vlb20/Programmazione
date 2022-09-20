/*(Triangle-Printing Program) Write an application that displays
the following patterns sep-arately, one below the other. Use for
loops to generate the patterns. All asterisks (*) should be
print-ed by a single statement of the form cout << '*'; which
causes the asterisks to print side by side. A statement of the
form cout << '\n'; can be used to move to the next line. A
statement of the form cout << ' '; can be used to display a
space for the last two patterns. There should be no other output
statements in the program. [Hint: The last two patterns require
that each line begin with an appro-priate number of blank
spaces.]*/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int dim{10};
    
    cout<<"\n\nTriangolo A:\n";
    for(int i=0;i<dim;i++){
        for(int j=dim-i-1;j<dim;j++){
            cout<<"*";
        }
        for(int k=dim-1-i;k>0;k--){
            cout<<" ";
        }
        cout<<endl;
    }
    
    cout<<"\n\nTriangolo B:\n";
    for(int i=0;i<dim;i++){
        for(int j=dim-i-1;j>0;j--){
            cout<<"*";
        }
        for(int j=dim-i-1;j<dim;j++){
            cout<<" ";
        }
        cout<<endl;
    }

    cout<<"\n\nTriangolo C:\n";
    for(int i=0;i<dim;i++){
        for(int j=dim-1-i;j<dim;j++){
            cout<<" ";
        }
        for(int k=dim-i-1;k>0;k--){
            cout<<"*";
        }
        cout<<endl;
    }

    cout<<"\n\nTriangolo D:\n";
    for(int i=0;i<dim;i++){
        for(int j=dim-1-i;j>0;j--){
            cout<<" ";
        }
        for(int k=dim-i-1;k<dim;k++){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}