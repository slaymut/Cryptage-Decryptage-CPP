#ifndef ARBRE_B_HPP
#define ARBRE_B_HPP

#include "Sommet.hpp"


class ArbreB{
private:
    Sommet * root;
    void scanTree(Sommet *node) const;

public:
    //Constructors
    ArbreB(): root(nullptr) {}
    ArbreB(const int &value){
        root = new Sommet{value};
    }
    ArbreB(ArbreB &Tree){
        this->root = Tree.getRoot();
    }
    ArbreB(Sommet *someNode) : root(someNode){}

    //Methods
    void insert(Sommet *node);
    void m_delete(Sommet *node);
    Sommet* getRoot(){return root;}
    void fuse(ArbreB &tree);
    void decompose(ArbreB &Tree);
    Sommet* search(int val) const;
    void printTree() const;
    void modifyNode(Sommet *target, int value);

    //Destructor
    ~ArbreB(){
        delete root;
    }
};


#endif