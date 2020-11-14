#include "ArbreB.hpp"
#include <iostream>

//Scans the whole tree
void c_ArbreB::scanTree(c_Sommet *startNode) const{
    //Show current node value
    if(startNode)
        std::cout << "Value of current node: " << startNode->valueSommet << " of depth: " << startNode->getDepth() <<'\n';

    //Left first because of standart tree reading.
    if(startNode->left) {
        std::cout << "Going left." << '\n';
        scanTree(startNode->left);
    }

    //Right then
    if(startNode->right){
        std::cout << "Going right." << '\n';
        scanTree(startNode->right);
    }
}

//Searches for a node in the tree
c_Sommet *c_ArbreB::search(int val) const {
    //Take root
    c_Sommet *current = root;
    std::cout << "Searching node of value : " << val << '\n';

    //While current not nullptr
    while(current){
        //If node is found, return it
        if(val == current->valueSommet) {
            std::cout << "Found node of value : " << val << '\n';
            return current;
        }

        //Go Right if value is larger
        if(val > current->valueSommet)
            current = current->right;
        //Else go left
        else
            current = current->left;
    }
    std::cout << "Didn't found node !" << '\n';
    return nullptr;
}

//Fuse the value of two nodes to create a new one, linked to both previous nodes.
void c_ArbreB::fuse(c_ArbreB &Tree){
    //If first node is nullptr
    if (!root) {
        insert(Tree.root);
        return;
    }
    //If second node is nullptr
    if (!Tree.root) {
        return;
    }

    //We allocate a new node and sum their values
    auto *sumNode = new c_Sommet{root->valueSommet + Tree.root->valueSommet};

    //To select which one to put on right and left
    if(root->valueSommet >= Tree.root->valueSommet) {
        sumNode->right = root;
        sumNode->left = Tree.root;
    }
    else{
        sumNode->right = Tree.root;
        sumNode->left = root;
    }

    std::cout << "Node created !" << '\n';
    root = sumNode;

    //We delete used Tree.
    delete Tree.root;
    Tree.root = nullptr;
}

//Decompose a binary tree (target) or leaf from the main binary tree(source) and returns the target

void c_ArbreB::decompose(c_ArbreB &Tree){
    if(!root) {
        std::cout << "Can't decompose tree. ERROR: Non-existant." << std::endl;
        return;
    }

    Tree.root = root->left;
    root->left = nullptr;
    delete root->left;

    root = root->right;

}

//Modifies value of a node(target)
void c_ArbreB::modifyNode(c_Sommet *target, const int value){
    //attributes a new value to the target node
    target->valueSommet = value ;
}

void c_ArbreB::createNode(const int &value){
    //Allocate a new node
    auto * newNode = new c_Sommet{value};

    //Insert node in tree
    insert(newNode);
}

//Inserts a node in the tree.
void c_ArbreB::insert(c_Sommet *node){
    if(!node) return;

    if(root == nullptr){
        root = node;
        return;
    }

    int cpt{0};
    c_Sommet *current = root;
    c_Sommet *previous = nullptr;

    while(current){
        previous = current;
        if(node->valueSommet < current->valueSommet) {
            current = current->left;
            cpt++;
        }
        else {
            current = current->right;
            cpt++;
        }
    }

    if(node->valueSommet < previous->valueSommet)
        previous->left = node;
    else
        previous->right = node;

    node->setDepth(cpt);
}

void c_ArbreB::printTree() const{
    if(root != nullptr) {
        std::cout << "\n" ;
        std::cout << "SCANNING OF THE TREE ..." << std::endl;
        scanTree(root);
    }
    else
        std::cout << "There is no tree !" << '\n';
}

//Deletes a node in the tree.
void c_ArbreB::m_delete(c_Sommet *node){
    if(!node){
        return;
    }
    if(node == root) {
        root = nullptr;
        delete root;
        return;
    }
    node = nullptr;
    delete node;

    std::cout << "Sommet has been deleted !" << '\n';
}