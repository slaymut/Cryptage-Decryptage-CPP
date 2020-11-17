#ifndef SOMMET_HPP
#define SOMMET_HPP
#include <cstddef>
#include "mainwindow.h"


class c_Sommet{
private:
    double frequence;
    char symbol;
    int depth = 0;
public:
    int valueSommet;
    c_Sommet *left = nullptr;
    c_Sommet *right = nullptr;

    //Constructor
    c_Sommet() = delete;
    c_Sommet(int const &value) : valueSommet(value){}

    //Destructor
    ~c_Sommet(){
        delete left; delete right;
    }

    void setDepth(int theDepth){
        depth = theDepth;
    }

    int &getDepth(){ return depth; };

    void print(MainWindow *wind, int x, int y);


};


#endif
