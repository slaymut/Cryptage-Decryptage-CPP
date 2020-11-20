#ifndef SOMMET_HPP
#define SOMMET_HPP
#include <cstddef>
#include "mainwindow.h"


class Sommet{
private:
    
    std::string letters; //Not used yet in this part
    int depth{};
    Sommet *left = nullptr;
    Sommet *right = nullptr;
    int valueSommet;

public:
    
    //Constructors
    Sommet() = delete;
    Sommet(const int value) : valueSommet(value){}
    Sommet(const Sommet& node){
        if (node.left != nullptr)
            left = new Sommet(*node.left);
        if (node.right != nullptr)
            right = new Sommet(*node.right);
        valueSommet = node.valueSommet;
    }

    //Destructor
    ~Sommet();

    void print(MainWindow *wind, int x, int y, int maxDepth);
    

    //Setters
    void setLeft(const Sommet& node);
    void setRight(const Sommet& node);
    void setDepth(int theDepth) {depth = theDepth;}
    void setValue(const int value) {valueSommet = value;}

    //Getters
    int getDepth() { return depth; };
    int getValue() { return valueSommet; }
    Sommet *getRight(){return right;}
    Sommet *getLeft(){return left;}
};


#endif
