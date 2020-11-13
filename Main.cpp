#include "ArbreB.hpp"
#include <iostream>


int main(int argc, const char * argv[]) {
    
    auto * node1 = new c_Sommet{1};
    auto * root= new c_Sommet{2};
    auto *node2 = new c_Sommet{3};   
    auto *node3 = new c_Sommet{4}; 
    

    c_ArbreB tree{root};
    tree.createNode(node1->valueSommet);
    tree.createNode(node2->valueSommet);
    tree.createNode(node3->valueSommet);
    tree.printTree();
    std::cout << '\n';
    std::cout << '\n';

    tree.m_delete(node2);
    tree.printTree();
    
    return 0;
}