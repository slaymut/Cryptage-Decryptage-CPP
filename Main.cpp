#include "ArbreB.hpp"
#include <iostream>


int main(int argc, const char * argv[]) {
    
    auto * node1 = new c_Sommet{1};
    auto * root= new c_Sommet{2};
    auto *node2 = new c_Sommet{3};   
    auto *node3 = new c_Sommet{4}; 
    
    //either c_ArbreB tree{} but decomment tree.createNode(root->valueSommet); (l.26)
    c_ArbreB tree{root};
    std::cout << "Before" << '\n';
    //can't create node made of root's node and binary tree
    //tree.createNode(root->valueSommet);
    tree.createNode(node1->valueSommet);
    tree.createNode(node2->valueSommet);
    tree.createNode(node3->valueSommet);
    tree.printTree();

    std::cout << '\n';
    /*
    c_Sommet *stuffy = tree.search(4);
    tree.createNode(stuffy->valueSommet);

    tree.modifyNode(root, 18);
    std::cout << "After modify" << '\n';
    std::cout << '\n';
    
    tree.printTree();
    */
    /*
    std::cout << "After delete root named node (not actual root) " << '\n';
    std::cout << '\n';

    tree.m_delete(root,root->valueSommet);
    tree.printTree(); 
    */
    std::cout << "After decompose " << '\n';
    std::cout << '\n';
    //TEST POUR ACCEDER AU CHILD (RIGHT OR LEFT) DE ROOT (à supprimer)
    /*
    //TRYING ROOT CHILD
    if ( root->right) {
        c_Sommet *root_right = root->right ;
        std::cout << "root has a right child : " << root_right->valueSommet << std::endl;
        //TRYING ROOT_RIGHT CHILD
        if(root_right->right) {
            c_Sommet *root_right_right = root_right->right;
            std::cout << "root_right has a right child : " << root_right_right->valueSommet << std::endl;
        }
        //TRYING ROOT_LEFT CHILD
        if(root_right->left) {
            c_Sommet *root_right_left = root_right->left;
            std::cout << "root_right has a left child : " << root_right_left->valueSommet << std::endl;
        }
    }
    if ( root->left) {
        c_Sommet *root_left = root->left ;
        std::cout << "root has a left child : " << root_left->valueSommet << std::endl;
    }
    */
    //TEST QUI NE MARCHE PAS (à supprimer)
    /*
    //TRYING NODE 1
    if ( node1->right) {
        c_Sommet *node1_right = node1->right ;
        std::cout << "node1 has a right child : " << node1_right->valueSommet << std::endl;
    }
    if ( node1->left) {
        c_Sommet *node1_left = node1->left ;
        std::cout << "node1 has a left child : " << node1_left->valueSommet << std::endl;
    }
    //TRYING NODE 3
    if ( node3->right) {
        c_Sommet *node3_right = node3->right ;
        std::cout << "node3 has a right child : " << node3_right->valueSommet << std::endl;
    }
    if ( node3->left) {
        c_Sommet *node3_left = node3->left ;
        std::cout << "node3 has a left child : " << node3_left->valueSommet << std::endl;
    }
    //TRYING NODE 2
    if ( node2->right) {
        c_Sommet *node2_right = node2->right ;
        std::cout << "node2 has a right child : " << node2_right->valueSommet << std::endl;
    }
    if ( node2->left) {
        c_Sommet *node2_left = node2->left ;
        std::cout << "node2 has a left child : " << node2_left->valueSommet << std::endl;
    }
    */
    c_Sommet * root_right = tree.search(1);
    tree.decompose(root_right);
    tree.printTree();
    
    return 0;
}