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
    //tree.printTree();

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
    std::cout << "After DECOMPOSE FOR tree " << '\n';
    std::cout << '\n';

    auto *Node1 = new c_Sommet{69};
    auto *Node2 = new c_Sommet{420};

    c_ArbreB Tree{};
    tree.decompose(node2, Tree);

    tree.printTree();

    std::cout << "After DECOMPOSE FOR TREE " << '\n';
    std::cout << '\n';

    Tree.printTree();
    
    return 0;
}