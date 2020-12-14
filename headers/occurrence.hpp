#pragma once

#include "arbreb.h"
#include <iostream>
#include <vector>

class Occurrence{
private:
    //Vector of char and their according percentages
    std::vector<std::pair<char, double>> all_chars{};

    //Vector of char and their according binary code
    std::vector<std::pair<char, std::string>> char_codes{};
    ArbreB FullTree;
    
    std::string input_binary_code{};

    //Private methods

    //Get percentage of occurrences for each letter
    void getOccurrence(std::string input_string);
    
    //Build tree
    void makeTree();

    //Find Tree with smallest value
    ArbreB findMin(std::vector<ArbreB> &vect);
    
    //Get binary code of the letter
    std::pair<char, std::string> getCode(Sommet *node, std::string letter, std::string &code);
    
    //Applies huffman Coding algorithm to find the binary codes of each letter
    void huffmanCoding(std::string string);

public:
    //Constructors
    Occurrence() = delete;
    Occurrence(std::string string){
        getOccurrence(string);
        makeTree();
        huffmanCoding(string);
    }

    //Getters
    ArbreB getArbre() {return FullTree;}
    std::vector<std::pair<char, double>> getAll_Chars() {return all_chars;}
    std::vector<std::pair<char, std::string>> getCode_Chars(){ return char_codes;}
    std::string getBinaryCode(){return input_binary_code;}

    //Destructor
    ~Occurrence();
};