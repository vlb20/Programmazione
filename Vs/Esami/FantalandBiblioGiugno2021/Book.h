#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<vector>
#include<string>

class Book{
    public:
        Book(int=0,const std::vector<std::string>& ={""},const std::string& =" ",int =0,const std::string& =" ",double=0.0);
        
        void setId(int);
        int getId() const;
        void setAuthors(const std::vector<std::string>&);
        std::string getAuthors() const;
        void setTitle(const std::string&);
        std::string getTitle() const;
        void setYear(int);
        int getYear() const;
        void setPosition(const std::string&);
        std::string getPosition() const;
        void setValue(double);
        double getValue() const;

        bool operator<(const Book&) const;
        virtual void print() const;

    private:
        int book_id;
        std::string title;
        std::vector<std::string> authors;
        int year;
        std::string position;
        double value;


};

#endif