#ifndef ARBRE_B_HPP
#define ARBRE_B_HPP

#include "Sommet.hpp"

template <class Type>
class c_ArbreB{
private:
    c_Sommet<Type> * root;

public:
    //Constructors
    c_ArbreB(): root(nullptr) {}
    explicit c_ArbreB(Type const &value): root(value) {}

    c_Sommet<Type>* getRoot(){return root;}
    c_Sommet<Type>* search();
    void insert(Type value);//not sure how we'll use this one yet

    //Destructor
    ~c_ArbreB(){
        delete root;
    }
};


#endif