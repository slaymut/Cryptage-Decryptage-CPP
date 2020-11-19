#include "ArbreB.hpp"
#include <iostream>

//Scans the whole tree
void ArbreB::scanTree(Sommet *startNode) const{
    //Show current node value
    if(startNode)
        std::cout << "Value of current node: " << startNode->getValue() << " of depth: " << startNode->getDepth() <<'\n';

    //Left first because of standart tree reading.
    if(startNode->getLeft()) {
        std::cout << "Going left." << '\n';
        scanTree(startNode->getLeft());
    }

    //Right then
    if(startNode->getRight()){
        std::cout << "Going right." << '\n';
        scanTree(startNode->getRight());
    }
}

//Searches for a node in the tree
Sommet *ArbreB::search(int val) const {
    //Take root
    Sommet *current = root;
    std::cout << "Searching node of value : " << val << '\n';

    //While current not nullptr
    while(current){
        //If node is found, return it
        if(val == current->getValue()) {
            std::cout << "Found node of value : " << val << '\n';
            return current;
        }

        //Go Right if value is larger
        if(val > current->getValue())
            current = current->getRight();
        //Else go left
        else
            current = current->getLeft();
    }
    std::cout << "Didn't found node !" << '\n';
    return nullptr;
}

//Fuse the value of two nodes to create a new one, linked to both previous nodes.
void ArbreB::fuse(ArbreB &Tree){
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
    auto *sumNode = new Sommet{root->getValue() + Tree.root->getValue()};

    //To select which one to put on right and left
    if(root->getValue() >= Tree.root->getValue()) {
        sumNode->setRight(*root);
        sumNode->setLeft(*Tree.root);
    }
    else{
        sumNode->setRight(*Tree.root);
        sumNode->setLeft(*root);
    }

    std::cout << "Node created !" << '\n';
    root = sumNode;

    //We delete used Tree.
    delete Tree.root;
    Tree.root = nullptr;
}

//Decompose a binary tree (target) or leaf from the main binary tree(source) and returns the target

void ArbreB::decompose(ArbreB &Tree){
    if(!root) {
        std::cout << "Can't decompose tree. ERROR: Non-existant." << std::endl;
        return;
    }
    if(Tree.getRoot()){
        std::cout << "Can't decompose tree. ERROR: Tree in parameters is an existant tree." << std::endl;
        return;
    }

    Tree.root = root->getLeft();

    //Override root value
    root = root->getRight();

}

//Modifies value of a node(target)
void ArbreB::modifyNode(Sommet *target, const int value){
    //attributes a new value to the target node
    target->setValue(value);
}

//Inserts a node in the tree.
void ArbreB::insert(Sommet *node){
    if(!node) return;

    if(root == nullptr){
        root = node;
        return;
    }

    int cpt{0};
    Sommet *current = root;
    Sommet *previous = nullptr;

    while(current){
        previous = current;
        if(node->getValue() < current->getValue()) {
            current = current->getLeft();
            cpt++;
        }
        else {
            current = current->getRight();
            cpt++;
        }
    }

    if(node->getValue() < previous->getValue())
        previous->setLeft(*node);
    else
        previous->setRight(*node);

    node->setDepth(cpt);
}

void ArbreB::printTree() const{
    if(root != nullptr) {
        std::cout << "\n" ;
        std::cout << "SCANNING OF THE TREE ..." << std::endl;
        scanTree(root);
    }
    else
        std::cout << "There is no tree !" << '\n';
}

//Deletes a node in the tree.
void ArbreB::m_delete(Sommet *node){
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