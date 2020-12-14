#include <iostream>

//Verifies if the first input is correct to avoid segfault and is an alphabetic letter of english
void verifyInput(std::string &string){

    std::cout << '\n';
    std::cout << "----------------------------------------------------------------------" << '\n';
    std::cout << "| Please, type something in ENGLISH. AT LEAST 2 different characters.|" << '\n';
    std::cout << "| ONLY ENGLISH IS SUPPORTED. SPECIAL CHARACTERS ARE NOT IN THE TREE. |" << '\n';
    std::cout << "----------------------------------------------------------------------" << '\n';
    std::cout << '\n';
    std::cout << "Go ahead: "; 

    bool correct = false;

    while(correct == false){
        std::getline(std::cin, string);
        bool firstChar, iChar;
        //If firstChar is correct
        if((int)string.at(0) >= 65 && (int)string.at(0) <= 90 || 
            (int)string.at(0) >= 97 && (int)string.at(0) <= 122){
            firstChar = true;
        }
        else firstChar = false;

        for(int i=0; i < string.size(); i++){
            //If other char is correct
            if((int)string.at(i) >= 65 && (int)string.at(i) <= 90 || 
            (int)string.at(i) >= 97 && (int)string.at(i) <= 122){
                iChar = true;
            }
            else iChar = false;

            //If different and correct
            if(string.at(0) != string.at(i) && firstChar && iChar){
                correct = true;
                break;
            }
            //Else we ask to input again
            if(i == string.size()-1){
                std::cout << "\nPlease, use at LEAST 2 different characters.\n" << '\n';
                std::cout << "Go ahead: "; 
                correct = false;
                break;
            }
        }
    }
}