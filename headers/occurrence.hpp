#pragma once

#include "arbreb.h"
#include <iostream>
#include <vector>

class Occurrence{
private:
    std::vector<std::pair<char, int>> all_chars{};
    std::vector<std::pair<char, std::string>> char_codes{};
    ArbreB FullTree;
    std::string input_binary_code{};

    //Private methods
    void getOccurrence(std::string input_string);
    void makeTree();
    ArbreB findMin(std::vector<ArbreB> &vect);
    std::pair<char, std::string> getCode(Sommet *node, std::string c, std::string &code);
    void huffmanCoding(std::string string);

public:
    Occurrence(std::string string){
        getOccurrence(string);
        makeTree();
        huffmanCoding(string);
    }

    ArbreB getArbre() {return FullTree;}
    std::vector<std::pair<char, int>> getAll_Chars() {return all_chars;}
    std::vector<std::pair<char, std::string>> getCode_Chars(){ return char_codes;}
    std::string getBinaryCode(){return input_binary_code;}

    ~Occurrence();
};