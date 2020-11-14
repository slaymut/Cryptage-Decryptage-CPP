#include "ArbreB.hpp"
#include <iostream>


int main(int argc, const char * argv[]) {
    
    auto * node1 = new c_Sommet{1};
    auto * root= new c_Sommet{2};
    auto *node2 = new c_Sommet{3};   
    auto *node3 = new c_Sommet{4}; 
    

    c_ArbreB tree{root};
    c_ArbreB Tree{node2};
    Tree.createNode(node3->valueSommet);
    Tree.createNode(node1->valueSommet);
    Tree.printTree();
    //tree.createNode(node1->valueSommet);
    tree.printTree();
    std::cout << '\n';
    std::cout << '\n';

    tree.fuse(Tree);

    tree.decompose(Tree);

    tree.printTree();
    std::cout << '\n';
    std::cout << '\n';
    Tree.printTree();
    
    return 0;
}