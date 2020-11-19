#ifndef SOMMET_HPP
#define SOMMET_HPP
#include <cstddef>


class Sommet{
private:
    Sommet *left = nullptr;
    Sommet *right = nullptr;
    double frequence;
    char symbol;
    int depth{};
    int valueSommet;
public:
    //Constructor
    Sommet() = delete;
    Sommet(int const &value) : valueSommet(value){}
    
    //Destructor
    ~Sommet(){
        delete this->left; delete this->right;
    }
    void setLeft(const Sommet& s) {
        if(&s == nullptr){
            left = nullptr;
        }
        else{
            delete left;
            auto* newS = new Sommet{s};
            left = newS;
        }
    }

    void setRight(const Sommet& s) {
        if(&s == nullptr){
            right = nullptr;
        }
        else{
            delete right;
            auto* newS = new Sommet{s};
            right = newS;
        }
    }

    void setDepth(const int &theDepth){
        depth = theDepth;
    }
    void setValue(const int &value){
        valueSommet = value;
    }

    int getValue() const{ return valueSommet; }
    int getDepth() const{ return depth; }


    Sommet *getRight(){return right;}
    Sommet *getLeft(){return left;}

};


#endif