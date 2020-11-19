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

    ArbreB bigcock{};
    Sommet *swag = new Sommet{15};
    Sommet *swag2 = new Sommet{5};
    Sommet *swag3 = new Sommet{16};
    bigcock.insert(swag);
    bigcock.insert(swag2);
    bigcock.insert(swag3);
    bigcock.printTree();
    
    return 0;
}