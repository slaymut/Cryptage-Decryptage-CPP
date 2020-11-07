#include "ArbreB.hpp"

template<class Type>
c_Sommet<Type> *c_ArbreB<Type>::search() {
    //Will complete later.
}
//Creates a binary tree
template<class Type>
void c_ArbreB<Type>::create(Type value){
    //Will complete later.
}

//Inserts a node in the tree.
template<class Type>
void c_ArbreB<Type>::insert(c_Sommet<Type> *node){
    if(!node) return;

    if(root == nullptr){
        root = node;
        return;
    }

    c_Sommet<Type> *current = root;
    c_Sommet<Type> *previous = nullptr;

    while(current){
        previous = current;
        if(node->valueSommet < current->valueSommet)
            current = current->left;
        else
            current = current->right;
    }

    if(node->valeur < previous->valeur)
        previous->left = node;
    else
        previous->right = node;
}

//Deletes a node in the tree.
template<class Type>
void c_ArbreB<Type>::m_delete(c_Sommet<Type> *node){
    if (node==nullptr) return;

    m_delete(node->right);
    m_delete(node->left);
    
    delete node;
}

//UwU