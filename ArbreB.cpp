#include "ArbreB.hpp"
#include <iostream>

template<class Type>
<<<<<<< HEAD
c_Sommet<Type> *c_ArbreB<Type>::search(Type valueSommet) {
    c_Sommet<Type> *current = root;
    while(current){
        if(valueSommet== current->valueSommet)
         return current;
        else if(valueSommet < current->valueSommet)
         current = current->left;
        else
         current = current->right;
    }
=======
void c_ArbreB<Type>::scanTree(c_Sommet<Type> *startNode) const{
    //Left first because of standart tree reading.
    if(startNode->left)
        scanTree(startNode->left);

    //Show current node value
    if(startNode)
        std::cout << "Value of current node: " << startNode->valueSommet << '\n';

    //Right then
    if(startNode->right)
        scanTree(startNode->right);
>>>>>>> f5a4baeee684fca5cf239aae2cf34bb97437b865
}

template<class Type>
c_Sommet<Type> *c_ArbreB<Type>::search(Type &val) const {
    //Take root
    c_Sommet<Type> *current = root;

    //While root not nullptr
    while(current){
        //If node is found, return it
        if(current->valueSommet == val)
            return current;

        //Go left if value is
        if(current->valueSommet > val)
            current = current->right;
        else
            current = current->left;
    }

    return nullptr;
}

template<class Type>
void c_ArbreB<Type>::createNode(const Type value){
    //Allocate a new node
    auto * newNode = new c_Sommet<Type>;

    //Initialize left and right nodes
    newNode->right = nullptr;
    newNode->left = nullptr;

    //Insert value
    newNode->valueSommet = value;

    //Insert node in tree
    insert(newNode);
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

    if(noodle->valueSommet < previous->valueSommet)
        previous->left = noodle;
    else
        previous->right = noodle;
}

//Deletes a node in the tree.
template<class Type>
void c_ArbreB<Type>::m_delete(c_Sommet<Type> *node){
    if (node==nullptr) return;

    m_delete(node->right);
    m_delete(node->left);

    delete node;
}