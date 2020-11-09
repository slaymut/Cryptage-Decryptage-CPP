#include "ArbreB.hpp"
#include <iostream>

template<class Type>
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

//Fuse a source(root's node) and its binary tree to a target node (which contains main binary tree)
template<class Type>
c_Sommet<Type> *c_ArbreB<Type>::fuse(c_Sommet<Type> *source,c_Sommet<Type> *target){
    if (!source)
        return target;
    if (!target)
        return source;

    //Case where 
    if          (source->valueSommet > target->valueSommet) {
        c_Sommet<Type>*temp = target->right;
        target->right = nullptr;
        source->left = fuse(source,temp);
        return source;
    }
    //Case where
    else if     (source->valueSommet < target->valueSommet) {
        c_Sommet<Type>*temp = source->right;
        source->right = nullptr;
        target->left = fuse(target,temp);
        return target;
    }
    //Case where target is a leaf 
    else {
        c_Sommet<Type>*temp = source->left;
        source->left = target ;
        source->right = temp;
        return source;
    }
}

//Decompose a binary tree (target) or leaf from the main binary tree(source) and returns the target
template<class Type>
c_Sommet<Type> *c_ArbreB<Type>::decompose(c_Sommet<Type> *target){
    c_Sommet<Type>*temp = target;
    m_delete(target);
    return temp;
}

//Modifies value of a node(target)
template<class Type>
void c_ArbreB<Type>::modifyNode(c_Sommet<Type> *target,const Type value){
    //attributes a new value to the target node
    target->valueSommet = value;
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