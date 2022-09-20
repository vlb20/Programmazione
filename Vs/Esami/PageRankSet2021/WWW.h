#ifndef WWW_H
#define WWW_H
#include<vector>
#include<list>
class WWW{
    public:
        class Page{
            public:
                Page(int id, int nl, double p):
                    pageID{id}, nLink{nl}, P{p} {}
                friend class WWW;
            private:
                int pageID;
                int nLink;
                double P; //peso
        };
        WWW(int); //numero di pag in ingresso
        void pageRank();
        void addLink(int, int); //per linkare le varie pagine
        void printRanks();
        void iteratePageRank();

    private:
        int nPages;
        std::vector<Page> pages; 
        std::list<int> *web;
        double delta{0.001};

};



#endif