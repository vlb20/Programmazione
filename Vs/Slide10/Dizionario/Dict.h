#ifndef DICT_H
#define DICT_H
#include<string>

class Word{
    public:
        Word(std::string, std::string);
        std::string getEngWord();
        std::string getItWord();
        void setEngWord(std::string);
        void setItWord(std::string);

    private:
        std::string engWord;
        std::string itWord;
};

#endif