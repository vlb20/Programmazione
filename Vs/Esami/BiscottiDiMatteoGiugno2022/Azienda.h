#ifndef AZ_H
#define AZ_H
#include "Biscotto.h"
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
using std::ios;
#include<math.h>
#include <list>
using std::list;
#include <iostream>

class Azienda
{
    public:
        Azienda()
        {
            ifstream inFile( "biscotti.txt", ios::in);
            if (!inFile) exit(EXIT_FAILURE);
            inFile>>nBiscotti;
            
            for ( int i=0; i<nBiscotti; i++)
            {
                int ide;
                string n;
                string p;
                inFile>>ide>>n>>p;

                array<float,10> temp;
                for (int j=0; j<10; j++){inFile>>temp[j];}
                biscotti.push_back(Biscotto(i,n,p,temp));
            }
        }

        int getN() const {return nBiscotti;}

        string toString()
        {
            ostringstream out;
            out<<"ELENCO BISCOTTI DISPONIBILI: \n";
            for (int i=0; i<nBiscotti; i++) out<<biscotti[i].toString()<<"\n";
            return out.str();
        }

        bool simili( Biscotto& b1, Biscotto& b2)
        {
            float sum=0;
            for (int i=0; i<10; i++)
            {
                float diff{ b1.getValori()[i] - b2.getValori()[i]};
                sum+= diff*diff;
            }
            return sqrt(sum)< epsilon;;
        }

        void setEpsilon( float e)
        {
            epsilon=e;
        }

        void buildGrafo()
        {
            grafo= new list<int> [nBiscotti];
            for( int i=0; i<nBiscotti-1; i++)
            {
                for( int j=i+1; j<nBiscotti; j++)
                {
                    Biscotto b1= biscotti[i];
                    Biscotto b2= biscotti[j];

                    if( simili(b1,b2))
                    {
                        
                        grafo[i].push_back(b2.getId());
                        grafo[j].push_back(b1.getId());
                    }
                }
            }
        }

        string displayGrafo()
        {
            ostringstream out;
            for (int i=0; i<nBiscotti; i++)
            {
                out<<"BISCOTTI SIMILI AL N."<< i<<" :\t";
                for (auto cur=grafo[i].begin(); cur!=grafo[i].end(); cur++)
                {
                    int n= *cur;
                    out<<"["<<n<<"] ";
                }
                out<<"\n";
            }
            return out.str();
        }

        string cluster(int ide)
        {
            ostringstream out;
            bool* flags= new  bool [nBiscotti] ;
            for (int i=0; i<nBiscotti; i++) flags[i]=false;
            for( auto cur=grafo[ide].begin(); cur!=grafo[ide].end(); cur++)
            {
                int n=*cur;
                flaggaSimili(flags,n);
            }
            out<< "BISCOTTI RAGGIUNTI DAL BISCOTTO N."<< ide<< " :";
            for (int i=0; i<nBiscotti; i++)
            {
                if (flags[i]==true && i!=ide) out<<"["<< i<<"] ";
            }
            return out.str();
        }

        void flaggaSimili(bool* flag  ,int ide)
        {
            for( auto cur=grafo[ide].begin(); cur!=grafo[ide].end(); cur++)
            {
                int n=*cur;
                if (flag[n]!=true)
                {
                    flag[n]=true;
                    flaggaSimili( flag, n);
                } 
                
            }
        }


    private:
        vector<Biscotto> biscotti;
        int nBiscotti;
        float epsilon=12.0;
        list<int>* grafo;

};
#endif