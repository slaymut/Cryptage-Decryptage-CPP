#pragma once

#include <cstddef>
#include <iostream>


class Sommet{
private:
    std::string letters;
    int depth{};
    Sommet *left = nullptr;
    Sommet *right = nullptr;
    double valueSommet;
    int binaire;

public:
    
    //Constructors
    Sommet() = delete;
    Sommet(const double value) : valueSommet(value){}
    Sommet(std::string const &lettres, double const &value) : letters(lettres), valueSommet(value){}

    Sommet(const Sommet& node){
        if (node.left != nullptr)
            left = new Sommet(*node.left);
        if (node.right != nullptr)
            right = new Sommet(*node.right);
        valueSommet = node.valueSommet;
        depth = node.depth;
        letters = node.letters;
    }

    //Destructor
    ~Sommet();

    //Setters
    void setLeft(const Sommet& node);
    void setRight(const Sommet& node);
    void setDepth(int theDepth) {depth = theDepth;}
    void setValue(double value) {valueSommet = value;}
    void setBinaire(int value) {binaire = value;}
    void setLetters(std::string input) {letters = input;}

    //Getters
    int getBinaire(){ return binaire; }
    int getBinaire()const{ return binaire; }

    std::string getLetters(){ return letters; }
    std::string getLetters()const { return letters; }
    int getDepth() { return depth; };
    
    double getValue() { return valueSommet; }
    double getValue() const { return valueSommet; }

    Sommet *getRight(){return right;}
    Sommet *getLeft(){return left;}
};
