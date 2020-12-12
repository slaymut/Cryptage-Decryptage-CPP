#pragma once

#include "arbreb.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>


//Return vector of Characters and Occurences (ORDERED)
/*std::vector<std::pair<char, int>> getOccurence(std::string input_string){
    std::map<char, int> characters;

    for(int i{0}; i < input_string.size(); i++){
        if(input_string.at(i) != ' '){
            char currentChar = input_string.at(i);
            char mapChar = characters.find(currentChar)->first;

            if(currentChar == mapChar)
                characters.find(currentChar)->second += 1;
            else
                characters.insert(std::pair<char, int>(currentChar, 1));
        }
    }
    std::vector<std::pair<char, int>> vec(characters.begin(), characters.end());

    return vec;
}*/

//Returns an UNORDERED vector of characters and their occurences
std::vector<std::pair<char, int>> getOccurence(std::string input_string){
    std::unordered_map<char, int> characters;

    for(int i{0}; i < input_string.size(); i++){
        if(input_string.at(i) != ' '){
            char currentChar = input_string.at(i);
            
            if(characters.find(currentChar) != characters.end())
                characters[currentChar] += 1;
            else
                characters[currentChar] = 1;
        }
    }
    std::vector<std::pair<char, int>> vec(characters.begin(), characters.end());

    return vec;
}

ArbreB findMin(std::vector<ArbreB> &vect){
    int tmp = 0, position;
    ArbreB min_Arbre{};

    for(int i = 0; i < vect.size(); i++){
        if(tmp == 0){
            tmp = vect[i].getRoot()->getValue();
            min_Arbre = vect[i];
            position = i;
        }
        if(tmp > vect[i].getRoot()->getValue()){
            tmp = vect[i].getRoot()->getValue();
            min_Arbre = vect[i];
            position = i;
        }
    }
    vect.erase(vect.begin() + position);

    return min_Arbre;
}

void getCode(Sommet *node, std::string c, std::string &code){

    if(node->getLeft()){
        if(node->getLeft()->getLetters().find(c) != std::string::npos){
            std::string binary{"0"};
            getCode(node->getLeft(), c, code += binary);
        }
    }

    if(node->getRight()){
        if(node->getRight()->getLetters().find(c) != std::string::npos){
            std::string binary{"1"};
            getCode(node->getRight(), c, code += binary);
        }
    }
}