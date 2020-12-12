#pragma once
#include <QObject>
#include <iostream>
#include "arbreb.h"

class Context : public QObject{

    Q_OBJECT

private:
    ArbreB Tree;

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
    void setArbre(ArbreB otherTree){
        Tree = otherTree;
    }

};