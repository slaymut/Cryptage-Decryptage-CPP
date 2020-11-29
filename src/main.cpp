#include "../headers/mainwindow.h"
#include "../headers/arbreb.h"

#include <QApplication>
#include <QLabel>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    w->setFixedSize(1000,600);
    auto *root= new Sommet{2};
    auto *node1 = new Sommet{3};
    auto *node2 = new Sommet{15};
    auto *node3 = new Sommet{30};
    
    /* Function fuse() ( here it's a operator surcharge with operator +)
    *
    */
    ArbreB tree{root};
    ArbreB Tree{node1};
    ArbreB Tree2{node2};
    ArbreB Tree3{node3};

    tree += Tree;
    tree += Tree2;
    

    /* Function insert()
    *
    *
    ArbreB tree{root};
    tree.insert(node1);
    tree.insert(node2);
    tree.insert(node3);
    */

    /*
    auto * node1 = new Sommet{1};
    auto * root= new Sommet{2};
    auto *node2 = new Sommet{3};   
    auto *node3 = new Sommet{4}; 
    auto *node4 = new Sommet{5};
    */


    /* Function m_delete() 
    *
    *
    ArbreB tree{root};
    tree.insert(node1);
    tree.insert(node2);
    tree.insert(node3);
    tree.m_delete(root->getRight()->getRight());    
    */

    /* Function search() + modifyNode()
    *
    *
    ArbreB tree{root};
    tree.insert(node1);
    tree.insert(node2);
    tree.insert(node3);
    tree.modifyNode(root->getRight(),40);
    tree.search(40);
    */


    /*
    *
    * Fct Decompose
    *
    * 
    //We create two Trees for which we assigns their root values
    ArbreB Arbre1{root};
    ArbreB Arbre2{new Sommet{15}};

    //We create a third Tree for which we assign the value of merging both previous Trees
    ArbreB Arbre3{Arbre1 + Arbre2};

    //We merge the Tree 1 with Tree 3
    Arbre1 += Arbre3;

    //Set the depth of Tree1 if you want to print in
    Arbre1.updateMaxDepth();
    Arbre1.setNodesDepth(Arbre1.getRoot(), 0);

    //We create an empty Tree and decompose Tree 1
    ArbreB ArbreDecompose{};
    Arbre1.decompose(ArbreDecompose);
    
    //We set the depths of the Tree we want to print.
    ArbreDecompose.updateMaxDepth();
    ArbreDecompose.setNodesDepth(ArbreDecompose.getRoot(), 0);
    //We print the other tree
    ArbreDecompose.printTree(w, w->width()/2, 75);
    */

    
    tree.updateMaxDepth();
    tree.setNodesDepth(tree.getRoot(), 0);
    
    tree.printTree(w, w->width()/2, 75);
    w->show();
    return a.exec();
}
