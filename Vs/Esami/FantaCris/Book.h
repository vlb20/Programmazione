#ifndef BOOK_H
#define BOOK_H

#include<vector>
#include<string>

class Book{
    public:
        Book(int = 0 ,std::string = "",std::vector<std::string> = {},int = 2000 , std::string="0000",double=0.0);
        Book& operator=(const Book&);
        bool operator<(const Book&) const;
        void setId(int id);
        void setAuthors(std::vector<std::string>& aut);
        void setYear(int y);
        void setValue(double v);
        void setPosition(std::string pos);
         void setTitle(std::string tit);
        int getId() const;
        std::vector<std::string> getAuthors() const;
        int getYear() const;
        std::string getTitle() const;
        std::string getPosition() const;
        double getValue() const;
        //virtual di print
        virtual void print() const;


    private:
        int book_id;
        std::vector<std::string> authors;
        std::string title;
        int year;
        std::string position;
        double value;

};
#endif