#pragma once

#include <cstddef>
#include <iostream>


class Sommet{
private:
    
    std::string letters;
    int depth{};
    Sommet *left = nullptr;
    Sommet *right = nullptr;
    int valueSommet;
    int binaire;

public:
    
    //Constructors
    Sommet() = delete;
    Sommet(const int value) : valueSommet(value){}
    Sommet(std::string const &lettres, int const &value) : letters(lettres), valueSommet(value){}

    Sommet(const Sommet& node){
        if (node.left != nullptr)
            left = new Sommet(*node.left);
        if (node.right != nullptr)
            right = new Sommet(*node.right);
        valueSommet = node.valueSommet;
        depth = node.depth;
        letters = node.letters;
    }

    //Destructorstd::string getLetters(){ return letters; }
    ~Sommet();

    //void print(MainWindow *wind, int x, int y, int maxDepth);
    

    //Setters
    void setLeft(const Sommet& node);
    void setRight(const Sommet& node);
    void setDepth(int theDepth) {depth = theDepth;}
    void setValue(const int value) {valueSommet = value;}
    void setBinaire(const int value) {binaire = value;}
    void setLetters(std::string l) {letters = l;}

    //Getters
    int getBinaire(){ return binaire; }
    int getBinaire()const{ return binaire; }

    std::string getLetters(){ return letters; }
    std::string getLetters()const { return letters; }
    int getDepth() { return depth; };
    
    int getValue() { return valueSommet; }
    int getValue() const { return valueSommet; }

    Sommet *getRight(){return right;}
    Sommet *getLeft(){return left;}
};
