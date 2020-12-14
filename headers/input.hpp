#include <iostream>

//Verifies if the first input is correct to avoid segfault
void verifyInput(std::string &string){
    bool one = false;
    for(int i=0; i < string.size(); i++){
        if(string.at(0) != string.at(i)){
            break;
        }
        if(i == string.size()-1){
            std::cout << "\nPlease, use at LEAST 2 different characters.\n" << '\n';
            std::cout << "Go ahead: "; 
            one = true;
            break;
        }
    }

    while(one == true){
        std::getline(std::cin, string);
        for(int i=0; i < string.size(); i++){
            if(string.at(0) != string.at(i)){
                one = false;
                break;
            }
            if(i == string.size()-1){
                std::cout << "\nPlease, use at LEAST 2 different characters.\n" << '\n';
                std::cout << "Go ahead: "; 
                one = true;
                break;
            }
        }
    }
}