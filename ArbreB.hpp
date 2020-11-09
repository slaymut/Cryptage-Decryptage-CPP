#ifndef ARBRE_B_HPP
#define ARBRE_B_HPP

#include "Sommet.hpp"

template <class Type>
class c_ArbreB{
private:
    c_Sommet<Type> * root;
    void insert(c_Sommet<Type> *node);
    void scanTree(c_Sommet<Type> *node) const;


public:
    //Constructors
    c_ArbreB(): root(nullptr) {}
    explicit c_ArbreB(Type const &value): root(value) {}

    void m_delete(c_Sommet<Type> *node);
    c_Sommet<Type>* getRoot(){return root;}
    c_Sommet<Type>* search(Type &val) const;
    void createNode(Type value);

    //Destructor
    ~c_ArbreB(){
        delete root;
    }
};


#endif