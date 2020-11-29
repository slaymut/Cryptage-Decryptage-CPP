#include "../headers/arbreb.h"
#include <iostream>

void ArbreB::scanTree(Sommet *startNode, MainWindow* w, int x, int y) const{
    //Show current node value
    if(startNode){
        std::cout << "Value of current node: " << startNode->getValue() << " with depth: " << startNode->getDepth() << '\n';
        startNode->print(w, x, y, maximumLevel);
    }

    //Left first because of standart tree reading.
    if(startNode->getLeft()) {
        std::cout << "Going left." << '\n';
        scanTree(startNode->getLeft(), w, x - 30*(maximumLevel - startNode->getDepth()) , y + 40 * (startNode->getDepth()+1));
    }

    //Right then
    if(startNode->getRight()){
        std::cout << "Going right." << '\n';
        scanTree(startNode->getRight(), w, x + 30*(maximumLevel - startNode->getDepth()), y+ 40 * (startNode->getDepth()+1));
    }
}

int ArbreB::maxLevel(Sommet *node) const{
    if (!node)
        return 0;
    else
    {
        //Find depth of each subtree
        int lDepth = maxLevel(node->getLeft());
        int rDepth = maxLevel(node->getRight());

        //Return the larger one
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

void ArbreB::setNodesDepth(Sommet *node, int level){
    // Base Case
    if (node == nullptr)
        return;

    // Set its depth
    node->setDepth(level);

    setNodesDepth(node->getLeft(), level+1);
    setNodesDepth(node->getRight(), level+1);
}


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

ArbreB ArbreB::merge(const ArbreB &Tree){
    //If first node is nullptr
    if (!root) {
        insert(Tree.root);
        return 0;
    }
    //If second node is nullptr
    if (!Tree.root) {
        return 0;
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

    return *this;
}

void ArbreB::decompose(ArbreB &Tree){
    if(!root) {
        std::cout << "Can't decompose current tree. ERROR: Non-existant." << std::endl;
        return;
    }
    if(Tree.getRoot()){
        std::cout << "Can't decompose current tree. ERROR: The other tree is an existant tree." << std::endl;
        return;
    }

    Tree.root = root->getLeft();

    //Override root value
    root = root->getRight();

}

void ArbreB::modifyNode(Sommet *target, const int value){
    //attributes a new value to the target node
    std::cout << "Modify value of actuel node from : " << target->getValue() << " to " << value <<std::endl; 
    target->setValue(value);
}

void ArbreB::insert(Sommet *node){
    if(!node) return;

    if(root == nullptr){
        root = node;
        return;
    }

    Sommet *current = root;
    Sommet *previous = nullptr;

    while(current){
        previous = current;
        if(node->getValue() < current->getValue()){
            current = current->getLeft();
        }
        else{
            current = current->getRight();
        }
    }

    if(node->getValue() < previous->getValue())
        previous->setLeft(*node);
    else
        previous->setRight(*node);

}

void ArbreB::printTree(MainWindow *w, int x, int y) const{
    if(root != nullptr) {
        std::cout << "\n" ;
        std::cout << "SCANNING THE TREE ..." << std::endl;
        scanTree(root, w, x, y);
    }
    else
        std::cout << "There is no tree !" << '\n';
}

Sommet* ArbreB::FindMin(Sommet* root)
{
	while(root->getLeft() != NULL) root = root->getLeft();
	return root;
}
void ArbreB::m_delete(Sommet *target){
    Sommet *node = target;
    if (!node){
        std::cout << "There is no node to delete !" << '\n';
        return;
    }

    Sommet *right = node->getRight();
    Sommet *left = node->getLeft();
    Sommet *current = root;
    Sommet *c_right = current->getRight();
    Sommet *c_left = current->getLeft();

    //Case where value to delete is in root Node
    if(node == root){
        root = right;
        if(left) insert(left);
        
        node = nullptr;
        delete node;
        std::cout << "Sommet has been deleted (value to delete is in root node)!" << '\n';
        return;
    }

    //Other cases
    while(current){
        //If we find node
        if(current->getRight() == node ||current->getLeft() == node)
            break;

        //Else
        if(node->getValue() >= current->getValue())
            current = current->getRight();
        else
            current = current->getLeft();
    }

    if(current->getRight() == node){
        current->setRight(*right);
    }
    else{
        current->setLeft(*right);
    }
    if(left) insert(left);
    node = nullptr;
    delete node;
    std::cout << "Sommet has been deleted (normal algorithm)!" << '\n';
}

/*
*
*   NOT ENCAPSULATED BUT WORKS FINE
* 
void m_delete(Sommet *target){
    Sommet *node = target;

    if (!node){
        std::cout << "There is no node to delete !" << '\n';
        return;
    }

    Sommet *right = node->right;
    Sommet *left = node->left;
    Sommet *current = root;

    //Case where value to delete is in root Node
    if(node == root){
        root = right;
        if(left) insert(left);

        delete node;
        std::cout << "Sommet has been deleted !" << '\n';
        return;
    }


    //Other cases
    while(current){
        //If we find node
        if(current->right == node ||current->left == node)
            break;

        //Else
        if(node->valueSommet >= current->valueSommet)
            current = current->right;
        else
            current = current->left;
    }

    if(current->right == node)
        current->right = right;
    else
        current->left = right;

    if(left) insert(left);
    node = nullptr;
    delete node;
    std::cout << "Sommet has been deleted !" << '\n';
    
}
*/
