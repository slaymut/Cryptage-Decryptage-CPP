#ifndef ARBRE_B_HPP
#define ARBRE_B_HPP

#include "Sommet.hpp"

template <class Type>
class c_ArbreB{
private:
    c_Sommet<Type> * root;
    void insert(c_Sommet<Type> *node);
<<<<<<< HEAD
    void m_delete(c_Sommet<Type> *node);
=======
    void scanTree(c_Sommet<Type> *node) const;

>>>>>>> f5a4baeee684fca5cf239aae2cf34bb97437b865

public:
    //Constructors
    c_ArbreB(): root(nullptr) {}
    explicit c_ArbreB(Type const &value): root(value) {}

    void m_delete(c_Sommet<Type> *node);
    c_Sommet<Type>* getRoot(){return root;}
<<<<<<< HEAD
    c_Sommet<Type>* search(Type valueSommet);
    void create(Type value);
    
=======
    c_Sommet<Type>* search(Type &val) const;
    void createNode(Type value);
>>>>>>> f5a4baeee684fca5cf239aae2cf34bb97437b865

    //Destructor
    ~c_ArbreB(){
        delete root;
    }
};


#endif