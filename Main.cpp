#include "ArbreB.hpp"
#include <iostream>


int main(int argc, const char * argv[]) {

    auto *node = new c_Sommet{5};
    auto *node1 = new c_Sommet{6};
    auto *node2 = new c_Sommet{1};
    auto *node3 = new c_Sommet{8};

    c_ArbreB tree{15};

    tree.createNode(node->valueSommet);
    tree.createNode(node1->valueSommet);
    tree.createNode(node2->valueSommet);
    tree.createNode(node3->valueSommet);

    tree.printTree();



    return 0;
}
