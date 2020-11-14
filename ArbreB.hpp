#ifndef ARBRE_B_HPP
#define ARBRE_B_HPP

#include "Sommet.hpp"


class c_ArbreB{
private:
    c_Sommet * root;
    void insert(c_Sommet *node);
    void scanTree(c_Sommet *node) const;

public:
    //Constructors
    c_ArbreB(): root(nullptr) {}
    c_ArbreB(const int &value){
        root->valueSommet = value;
    }
    c_ArbreB(c_Sommet *someNode) : root(someNode){}

    //Methods
    void m_delete(c_Sommet *node);
    c_Sommet* getRoot(){return root;}
    void fuse(c_ArbreB &tree);
    void decompose(c_ArbreB &Tree);
    c_Sommet* search(int val) const;
    void printTree() const;
    void createNode(const int &value);
    void modifyNode(c_Sommet *target, int value);

    //Destructor
    ~c_ArbreB(){
        delete root;
    }
};


#endif