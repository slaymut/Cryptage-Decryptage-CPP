#include "ArbreB.hpp"
#include <iostream>


void c_ArbreB::scanTree(c_Sommet *startNode) const{
    //Left first because of standart tree reading.
    if(startNode->left) {
        std::cout << "Going left." << '\n';
        scanTree(startNode->left);
    }

    //Show current node value
    if(startNode)
        std::cout << "Value of current node: " << startNode->valueSommet << '\n';

    //Right then
    if(startNode->right){
        std::cout << "Going right." << '\n';
        scanTree(startNode->right);
    }
}


c_Sommet *c_ArbreB::search(int &val) const {
    //Take root
    c_Sommet *current = root;

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

c_Sommet *c_ArbreB::fuse(c_Sommet *source, c_Sommet *target){
    if (!source)
        return target;
    if (!target)
        return source;

    //Case where 
    if          (source->valueSommet > target->valueSommet) {
        c_Sommet *temp = target->right;
        target->right = nullptr;
        source->left = fuse(source, temp);
        return source;
    }
    //Case where
    else if     (source->valueSommet < target->valueSommet) {
        c_Sommet *temp = source->right;
        source->right = nullptr;
        target->left = fuse(target,temp);
        return target;
    }
    //Case where target is a leaf 
    else {
        c_Sommet *temp = source->left;
        source->left = target ;
        source->right = temp;
        return source;
    }
}

//Decompose a binary tree (target) or leaf from the main binary tree(source) and returns the target

c_Sommet *c_ArbreB::decompose(c_Sommet *target){
    c_Sommet *temp = target;
    m_delete(target);
    return temp;
}

//Modifies value of a node(target)
void c_ArbreB::modifyNode(c_Sommet *target, const int value){
    //attributes a new value to the target node
    target->valueSommet = value;
}

void c_ArbreB::createNode(const int &value){
    //Allocate a new node
    c_Sommet * newNode = new c_Sommet;

    //Initialize left and right nodes
    newNode->right = nullptr;
    newNode->left = nullptr;

    //Insert value
    newNode->valueSommet = value;

    //Insert node in tree
    insert(newNode);
}

//Inserts a node in the tree.
void c_ArbreB::insert(c_Sommet *noodle){
    if(!noodle) return;

    if(root == nullptr){
        root = noodle;
        return;
    }

    c_Sommet *current = root;
    c_Sommet *previous = nullptr;

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

void c_ArbreB::printTree(){
    if(root != nullptr)
        scanTree(root);
    else
        std::cout << "There is no tree !" << '\n';
}

//Deletes a node in the tree.
void c_ArbreB::m_delete(c_Sommet *node){
    if (node==nullptr) return;

    m_delete(node->right);
    m_delete(node->left);

    delete node;
}