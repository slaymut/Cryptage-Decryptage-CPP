#include "../headers/occurrence.hpp"

void Occurrence::getOccurrence(std::string input_string){
    for(int i{0}; i < input_string.size(); i++){
        if(input_string.at(i) != ' '){
            char currentChar = input_string.at(i);
            char vecChar;
            for(int j{0}; j < all_chars.size(); j++){
                if(all_chars.at(j).first == currentChar){
                    vecChar = currentChar;
                    all_chars[j].second += 1;
                }
            }
            if(vecChar != currentChar){
                all_chars.push_back(std::make_pair(currentChar, 1));
            }
        }
    }
}

void Occurrence::makeTree(){
    std::vector<ArbreB> vecteur2;
    int i = 0;
    for (auto v : all_chars){
        std::string first{v.first};    
        ArbreB One{new Sommet(first, v.second)};
        vecteur2.push_back(One);
    }
    
    while(vecteur2.size() > 1){
        ArbreB maintTree{}, Tree2;
        maintTree = findMin(vecteur2);
        Tree2 = findMin(vecteur2);
        FullTree = ArbreB{maintTree + Tree2};
        vecteur2.push_back(FullTree);
        std::cout << "This Arbre: " << FullTree.getRoot()->getLetters() << " " << FullTree.getRoot()->getValue() << '\n'; 
    }
}

ArbreB Occurrence::findMin(std::vector<ArbreB> &vect){
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

std::pair<char, std::string> Occurrence::getCode(Sommet *node, std::string c, std::string &code){
    if(node->getLeft()){
        if(node->getLeft()->getLetters().find(c) != std::string::npos){
            getCode(node->getLeft(), c, code += "0");
        }
    }

    if(node->getRight()){
        if(node->getRight()->getLetters().find(c) != std::string::npos){
            getCode(node->getRight(), c, code += "1");
        }
    }

    return std::pair<char, std::string>(c.at(0), code);
}

void Occurrence::huffmanCoding(std::string string){
    for(auto v : all_chars){
        std::string char_to_code{v.first};
        std::string a_code;
        auto one = getCode(FullTree.getRoot(), char_to_code, a_code);
        char_codes.push_back(one);
    }

    for(int i{0}; i < string.size(); i++){
        char current = string.at(i);
        std::string thisone;
        for(int j{0}; j < char_codes.size(); j++){
            if(current == char_codes[j].first){
                thisone = char_codes[j].second;
            }
        }
        input_binary_code += thisone;
    }
}