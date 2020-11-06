#include "ArbreB.hpp"

template<class Type>
c_Sommet<Type> *c_ArbreB<Type>::search() {
    //Will complete later.
}

template<class Type>
void c_ArbreB<Type>::create(Type value){
    //Will complete later.
}

//Inserts a node in the tree.
template<class Type>
void c_ArbreB<Type>::insert(c_Sommet<Type> *noodle){
    if(!noodle) return;

    if(root == nullptr){
        root = noodle;
        return;
    }

    c_Sommet<Type> *current = root;
    c_Sommet<Type> *previous = nullptr;

    while(current){
        previous = current;
        if(noodle->valueSommet < current->valueSommet)
            current = current->left;
        else
            current = current->right;
    }

    if(noodle->valeur < previous->valeur)
        previous->gauche = noodle;
    else
        previous->droite = noodle;
}

//UwU