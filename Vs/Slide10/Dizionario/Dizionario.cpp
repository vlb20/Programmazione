#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<limits>
#include<iomanip>
#include "Dict.h"

using std::string;
using std::cout;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::cin;
using std::setw;
using std::fixed;
using std::vector;
using std::cerr;
using std::left;
using std::endl;

int binSearchWord(const string, const vector<Word>&);
void addWord(const string, const string, vector<Word>&);
void loadDictionary(const string, vector<Word>&);
void writeDictionary(const string, const vector<Word>&);

int main(){
    int choice{0};
    const string DICTIONARY{"eng_it.dict"};
    string word;
    vector<Word> words; //lista di parole

    loadDictionary(DICTIONARY, words);
    cout<<"Benvenuti nel dizionario INGLESE-ITALIANO:"<<endl;

    while (true){
        //display menu
        cout<<"\nCosa vuoi fare?:"<<endl;
        cout<<"[1] Ricerca"<<endl;
        cout<<"[2] Aggiungi una parola"<<endl;
        cout<<"[3] Vedi dizionario"<<endl;
        cout<<"[4] Esci"<<endl;
        cout<<endl;
        cout<<"Scegli: ";
        cin>>choice;

        switch(choice){
            case 1:{
                string word;
                cout<<"Inserisci una parola inglese da ricercare in minuscolo: ";
                cin>>word;
                int pos= binSearchWord(word, words);
                if(pos<0){
                    cout<<"---\n"<<endl;
                    cout<<"\n'"<<word<<"'"<<" not found.\n";
                    cout<<"---\n"<<endl;
                }else{
                    Word w{words[pos]};
                        cout<<"---"<<endl;
                        cout<<"\n'"<<word<<"' means '"<<w.getItWord()<<"'\n"<<endl;
                }
            }
            break;
            case 2:{
                string engWd, itWd;
                cout<<"Inserisci una parola inglese:";
                cin>>engWd;
                cout<<"\nInserisci la traduzione italiana di "<<engWd<<":";
                cin>>itWd;
                int pos=binSearchWord(engWd,words);
                if(pos<0){
                    addWord(engWd,itWd,words);
                    cout<<"'"<<engWd<<"' aggiunta al dizionario."<<endl;
                }else{
                    cout<<"\n'"<<engWd<<"' e' gia' all'interno del dizionario."<<endl;
                }
            }
            break;

            case 3:{
                cout<<endl;
                cout<<"Contenuti del dizionario:"<<endl;
                for(int i=0; i<words.size(); i++){
                    Word wd=words[i];
                        cout<<setw(12)<<left<<wd.getEngWord()
                            <<setw(12)<<wd.getItWord()<<endl;
                }
            }
            break;

            case 4:{
                writeDictionary(DICTIONARY, words);//per salvare il dizionario
                cout<<"Arrivederci!"<<endl;
                exit(EXIT_SUCCESS);
            }
            break;

            default:{
                cout<<"\nScelta errata. Deve essere un numero tra 1 e 4."<<endl;
                cin.clear();
            }
        }
    }
    return 0;
}

void loadDictionary(const string dictFile, vector<Word>& words){
    //carica le parole del dizionario dal file nel vettore
    string engWord, itWord;
    ifstream inFile{dictFile, ios::in};
    if(!inFile){
        cerr<<"Non si può aprire il dizionario. Uscita!"<<endl;
        exit(EXIT_FAILURE);
    }

    while(inFile>>engWord>>itWord){
        words.push_back(Word{engWord, itWord});
    }
    inFile.close();
}

int binSearchWord(const string searchWd, const vector<Word>& words){
    string itWord, engWord;
    int n=words.size();
    int left=0;
    int right=n-1;

    while(left<=right){
        int mid=(right+left)/2;
        Word w{words[mid]};
        if(w.getEngWord()==searchWd)
            return mid;
        if(w.getEngWord()<searchWd)
            left=mid+1;
        else right=mid-1;
    }
    return -1;

}

void addWord(const string engWord, const string itWord,
                vector<Word>& dict){
    //MOLTO INEFFICIENTE!!
    Word w{engWord, itWord};
    int i=0;
    while (i<dict.size()){
        Word c(dict[i]);
        if(c.getEngWord()<engWord)
            i++;
        else
            break;
    } 
    dict.insert(dict.begin()+i,w);
   
}

void writeDictionary(const string dictFile, const vector<Word>& words){
    string engWord, itWord;
    ofstream outFile{dictFile, ios::out};
    if(!outFile){
        cerr<<"Non si può aprire il dizionario. Uscita!"<<endl;
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<words.size(); i++){
        Word wd=words[i];
        engWord=wd.getEngWord();
        itWord=wd.getItWord();
        outFile<<engWord<<"\t"<<itWord<<endl;
    }
    outFile.close();
}