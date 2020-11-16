#ifndef SOMMET_HPP
#define SOMMET_HPP
#include <cstddef>


class Sommet{
private:
    Sommet *left = nullptr;
    Sommet *right = nullptr;
    double frequence;
    char symbol;
    int depth = 0;
public:
    int valueSommet;


    //Constructor
    Sommet();
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

    void setDepth(int theDepth){
        depth = theDepth;
    }

    int &getDepth(){ return depth; };
    Sommet *getRight(){return right;}
    Sommet *getLeft(){return left;}

};


#endif