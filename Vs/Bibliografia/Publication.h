/*Scrivere un programma c++ che permetta di gestire la
bibliografia di un articolo scientifico.
• Il programma deve gestire un elenco di pubblicazioni,
• Tutte le pubblicazioni possono hanno un titolo, uno o piu’ autori, ed un
anno di pubblicazione
• E possono essere dei
• Libri, vanno memorizzati le informazioni sulla casa editrice e l’ISBN
• Articoli su riviste, vanno memorizzati il titolo della Rivista (es IEEE
Transaction of Computers), il numero della rivista, e le pagine (inizio e fine)
• Articoli su atti di convegni, vanno memorizzati il titolo del convegno (es IEEE
Conference on Machine Learning), la sede del convegno, e il numero di pagina
• Il programma deve permettere di memorizzare una lista di pubblicazioni
in un vettore, stampare la lista, ed calcolare il numero di
pubblicazioni di ciascun tipo a partire dai dati memorizzati nel
vettore.
• La stampa deve essere fatta in ordine alfabetico di cognome (overload
dell’operatore <)
• Implementare l’ordinamento di un vettore di pubblicazioni*/

#ifndef PUBLICATION_H
#define PUBLICATION_H
#include<string>
#include<vector>

class Publication{
public:
    Publication(std::vector<std::string>, std::string, int); //costruttore
    //get and set
    const std::vector<std::string>& getAuthors();
    Publication& setAuthors(const std::vector<std::string>&); //restituisce un puntator a this, abilità la cascata
    const std::string& getTitle();
    Publication& setTitle(const std::string&);
    const int getYear();
    void setYear(const int);

    //comparison
    bool operator<(const Publication&);

    //virtual print
    virtual std::string toString();

private:
    std::string title;
    std::vector<std::string> authors;
    int year{1800};
};

#endif
