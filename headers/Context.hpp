#pragma once
#include <QObject>
#include <iostream>
#include "occurrence.hpp"

class Context : public QObject{

    Q_OBJECT

private:
    std::string string_to_code{};
    Occurrence *Occu;
    Context(){}

public:
    static Context& getInstance()
    {
        static Context singleton;
        return singleton;
    }

    // Pour s'assurer que la classe reste en Singleton
    Context(Context const&) = delete;
    Context& operator=(Context const&) = delete;

    Occurrence* getInstanceOccu(){return Occu;}
    Occurrence* getInstanceOccu() const {return Occu;}
    void setOccurrence(std::string string){
        Occu = new Occurrence(string);
        emit arbreChanged();
    }

    ArbreB getArbre() { return Occu->getArbre(); }
    ArbreB getArbre() const { return Occu->getArbre(); }

    std::string getCodage() {return Occu->getBinaryCode();}
    std::string getCodage() const {return Occu->getBinaryCode();}

    std::string getString() {return string_to_code;}
    std::string getString() const {return string_to_code;}
    void setString(std::string const& thisone){
        string_to_code = thisone;
        setOccurrence(string_to_code);
        emit stringChanged();
    }

    std::vector<std::pair<char, std::string>> getChar_Codes() {return Occu->getCode_Chars();}
    std::vector<std::pair<char, std::string>> getChar_Codes() const {return Occu->getCode_Chars();}

    ~Context(){}
signals:
    void stringChanged();
    void arbreChanged();
};