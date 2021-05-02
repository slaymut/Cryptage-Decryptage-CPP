#include "../headers/occurrence.hpp"

void Occurrence::getOccurrence(std::string input_string){
    int nbrLetters = 0;

    for(int i{0}; i < input_string.size(); i++){
        if((int)input_string.at(i) >= 65 && (int)input_string.at(i) <= 90 || 
            (int)input_string.at(i) >= 97 && (int)input_string.at(i) <= 122 || (int)input_string.at(i) == 32){
            char currentChar = input_string.at(i);
            char vecChar;
            for(int j{0}; j < all_chars.size(); j++){
                if(all_chars.at(j).first == currentChar){
                    vecChar = currentChar;
                    all_chars[j].second += 1.0;
                }
            }
            if(vecChar != currentChar){
                all_chars.push_back(std::make_pair(currentChar, 1.0));
            }
            nbrLetters++;
        }
    }

    //Pourcentage
    for(int i{0}; i < all_chars.size(); i++){
        all_chars[i].second = all_chars[i].second * 100.0 / nbrLetters;
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
        if(maxDigit < one.second.size()){
            maxDigit = one.second.size();
        }
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

void Occurrence::huffmanDecoding(std::string input){
    int i = 0;
    decoded_text = "";
    incorrect = false;
    
    while(i < input.size()){
        std::string chars{};
        if(input.at(i) != '0' && input.at(i) != '1'){
            decoded_text = "";
            incorrect = true;
            return;
        }

        for(int j = 0; j < maxDigit; j++){
            if(j+i < input.size())
                chars.push_back(input.at(j+i));
            
            for(auto pair : char_codes){
                if(chars == pair.second){
                    decoded_text.push_back(pair.first);
                    isFound = true;
                    break;
                }
            }
            if(isFound) break;
        }
        if(!isFound){
            decoded_text = "";
            incorrect = true;
            return;
        }

        i += chars.size();
        isFound = false;
    }

}