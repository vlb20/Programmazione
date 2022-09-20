/*Write an application that prints the following egg-timer shape. You may use output statements
that print a single asterisk (*), a single hash (#) a single space or a single newline character. 
Maximize your use of iteration (with nested for statements), and minimize the number of output statement.*/
#include<iostream>

using std::cin;
using std::cout;

int main(){
    for(int i=0;i<9;i++){
        switch (i)
        {
            case 1:
                for (int k = 0; k < 9; k++)
                {
                    cout<<"#";
                }
                break;
                
            case 2:
                for(int k=0;k<9;k++){
                    if(k==0||k==8){
                    cout<<"#";
                    }else{
                        cout<<"*";
                    }
                }
                break;
            case 3:
                for(int k=0;k<9;k++){
                    if(k==0||k==8){
                    cout<<"#";
                    }else if(k==1||k==7){
                        cout<<" ";
                    }else{
                        cout<<"*";
                    }
                }
                break;
            case 4:
                for(int k=0;k<9;k++){
                    if(k==0||k==8){
                    cout<<"#";
                    }else if(k==1||k==7||k==2||k==6){
                        cout<<" ";
                    }else{
                        cout<<"*";
                    }
                }
                break;
            case 5:
                for(int k=0;k<9;k++){
                    if(k==0||k==8){
                    cout<<"#";
                    }else if(k==4){
                        cout<<"*";
                    }else{
                        cout<<" ";
                    }
                }
                break;
            case 6:
                for(int k=0;k<9;k++){
                    if(k==0||k==8){
                    cout<<"#";
                    }else if(k==1||k==7||k==2||k==6){
                        cout<<" ";
                    }else{
                        cout<<"*";
                    }
                }
                break;
            case 7:
                for(int k=0;k<9;k++){
                    if(k==0||k==8){
                    cout<<"#";
                    }else if(k==1||k==7){
                        cout<<" ";
                    }else{
                        cout<<"*";
                    }
                }
                break;
            case 8:
                for(int k=0;k<9;k++){
                    if(k==0||k==8){
                    cout<<"#";
                    }else{
                        cout<<"*";
                    }
                }
                break;
            
            default:
                break;
            }
        cout<<std::endl;  
        }
        
	for(int i=0;i<1;i++){
		for(int k=0;k<9;k++){
			cout<<"#";
		}	
	}
	
              return 0;
    }

