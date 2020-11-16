#include "ArbreB.hpp"
#include <iostream>


int main(int argc, const char * argv[]) {

    ArbreB tree{15};
    ArbreB Tree{5};
    ArbreB Tree2{6};

    tree.fuse(Tree);
    tree.printTree();
    std::cout << "2nd fuse" << '\n';
    tree.fuse(Tree2);
    tree.printTree();
    std::cout << '\n';
    std::cout << '\n';
    std::cout << '\n';

    Sommet *node = new Sommet{13};
    Sommet *node2 = new Sommet{2};
    Sommet *node3 = new Sommet{18};
    Tree2.insert(node);
    Tree2.insert(node2);
    Tree2.insert(node3);

    Tree2.printTree();
    
    return 0;
}