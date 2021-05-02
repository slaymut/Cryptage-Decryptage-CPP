#pragma once
#include <QObject>
#include <iostream>
#include "occurrence.hpp"

class Context : public QObject{

    Q_OBJECT

private:
    std::string string_to_code{};
    std::string string_to_decode{};
    Occurrence *Occu;

    //If binary code is invalid
    bool incorrect{false};
    Context(){}

public:
    //To get current instance
    static Context& getInstance()
    {
        static Context singleton;
        return singleton;
    }

    // Ensures that the class stays in one instance
    Context(Context const&) = delete;
    Context& operator=(Context const&) = delete;

    Occurrence* getInstanceOccu(){return Occu;}
    Occurrence* getInstanceOccu() const {return Occu;}
    void setOccurrence(std::string string){
        Occu = new Occurrence(string);
        emit arbreChanged();
    }

    //Get current Tree
    ArbreB getArbre() { return Occu->getArbre(); }
    ArbreB getArbre() const { return Occu->getArbre(); }

    //Get current Binary Code
    std::string getCodage() {return Occu->getBinaryCode();}
    std::string getCodage() const {return Occu->getBinaryCode();}

    //Get current string to code
    std::string getString() {return string_to_code;}
    std::string getString() const {return string_to_code;}
    void setString(std::string const& thisone){
        string_to_code = thisone;
        setOccurrence(string_to_code);
        emit stringChanged();
    }

    //Getter for the decoded string
    std::string getDecString() {return Occu->getDecodedText();}
    //To decode the binary code in input
    void setDecodingString(std::string input){
        string_to_decode = input;
        Occu->huffmanDecoding(input);

        //Always emits the signal. Incorrect stands for if the binary code is valid or not.
        if(!Occu->getIncorrect()){
            incorrect = false;
            emit codeChanged();
        }
        else{
            incorrect = true;
            emit codeChanged();
        }
        
    }

    //Get a vector of binary code representing each letter
    std::vector<std::pair<char, std::string>> getChar_Codes() {return Occu->getCode_Chars();}
    std::vector<std::pair<char, std::string>> getChar_Codes() const {return Occu->getCode_Chars();}

    bool getIncorrect(){return incorrect;}

    ~Context(){}
signals:
    //If the string is modified
    void stringChanged();

    //If the input code is modified
    void codeChanged();
    void wrongCode();

    //If the tree is modified
    void arbreChanged();
};