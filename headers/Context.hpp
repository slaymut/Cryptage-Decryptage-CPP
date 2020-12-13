#pragma once
#include <QObject>
#include <iostream>
#include "arbreb.h"

class Context : public QObject{

    Q_OBJECT

private:
    ArbreB Tree{};
    std::string codageHuff{};
    std::string string_to_code{};

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

    ArbreB getArbre() { return Tree; }
    ArbreB getArbre() const { return Tree; }
    void setArbre(ArbreB otherTree){
        Tree = otherTree;
    }

    std::string getCodage() {return codageHuff;}
    std::string getCodage() const {return codageHuff;}
    void setCodageHuff(std::string code){
        codageHuff = code;
    }

    std::string getString() {return string_to_code;}
    std::string getString() const {return string_to_code;}
    void setString(std::string to_code){
        string_to_code = to_code;
    }

};