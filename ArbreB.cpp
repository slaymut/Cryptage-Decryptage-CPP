#include "ArbreB.hpp"
#include <iostream>

//Scans the whole tree
void c_ArbreB::scanTree(c_Sommet *startNode) const{
    //Show current node value
    if(startNode)
        std::cout << "Value of current node: " << startNode->valueSommet << '\n';

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

//Fuse a source(root's node) and its binary tree to a target node (which contains main binary tree) *NEEDS TO BE FIXED*
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
    if(!target) {
        std::cout << "can't decompose sub binary tree if there is not a valid node in argument" << std::endl;
        return nullptr;
    }

    std::cout << "Search of decompose method" << std::endl;
    target = search(target->valueSommet);
    /*
    if (target->right) { 
        c_Sommet *target_right = target->right;
        std::cout << "value of target right child : " << target_right->valueSommet << std::endl;
    }
    if (target->left) {
        c_Sommet *target_left = target->left;
        std::cout << "value of target left child : " << target_left->valueSommet << std::endl;
    }
    */
    
    while(target){
        if(target->left) {
            std::cout << "going into left sub tree in order to decompose" << std::endl;
            m_delete(target->left,(target->left)->valueSommet );
            decompose(target->left);
        }
        if(target->right) {
            std::cout << "going into right sub tree in order to decompose" << std::endl;
            m_delete(target->right,(target->right)->valueSommet );
            decompose(target->right);
        }
        else {
            break;
        }  
    }
    m_delete(target,target->valueSommet);  

}

//Modifies value of a node(target)
void c_ArbreB::modifyNode(c_Sommet *target, const int value){
    //attributes a new value to the target node
    target->valueSommet = value ;
}

void c_ArbreB::createNode(const int &value){
    //Allocate a new node
    auto * newNode = new c_Sommet;

    //Initialize left and right nodes
    newNode->right = nullptr;
    newNode->left = nullptr;

    //Insert value
    newNode->valueSommet = value;

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
    
    c_Sommet *current = root;
    c_Sommet *previous = nullptr;

    while(current){
        previous = current;
        if(node->valueSommet < current->valueSommet)
            current = current->left;
        else
            current = current->right;
    }

    if(node->valueSommet < previous->valueSommet)
        previous->left = node;
    else
        previous->right = node;

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
void c_ArbreB::m_delete(c_Sommet *node,int &val){
    std::cout << "Search of m_delete method" << std::endl;
    node = search(val);

    if (!node){
        std::cout << "There is no node to delete !" << '\n';
        return;
    }

    c_Sommet *right = node->right;
    c_Sommet *left = node->left;
    c_Sommet *current = root;

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