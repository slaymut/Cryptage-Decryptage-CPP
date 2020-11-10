#include "ArbreB.hpp"
#include <iostream>


int main(int argc, const char * argv[]) {

    auto *node = new c_Sommet{5};
    auto *node1 = new c_Sommet{6};
    auto *node2 = new c_Sommet{1};
    auto *node3 = new c_Sommet{8};

    auto *root = new c_Sommet{1515};
    c_ArbreB tree{root};

    std::cout << "Before" << '\n';
    tree.createNode(node->valueSommet);
    tree.createNode(node1->valueSommet);
    tree.createNode(node2->valueSommet);
    tree.createNode(node3->valueSommet);
    tree.printTree();
    std::cout << '\n';

    c_Sommet *stuffy = tree.search(6);
    tree.createNode(stuffy->valueSommet);

    tree.modifyNode(stuffy, 18);
    std::cout << "After" << '\n';
    std::cout << '\n';

    tree.printTree();

    std::cout << "After" << '\n';
    std::cout << '\n';

    tree.m_delete(root->valueSommet);

    return 0;
}