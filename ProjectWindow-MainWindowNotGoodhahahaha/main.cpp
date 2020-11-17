#include "mainwindow.h"
#include "arbreb.h"

#include <QApplication>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    auto *node1 = new c_Sommet{1};
    auto *root= new c_Sommet{2};
    auto *node2 = new c_Sommet{3};
    auto *node3 = new c_Sommet{4};


    c_ArbreB tree{root};
    c_ArbreB Tree{node2};
    Tree.createNode(node3->valueSommet);
    Tree.createNode(node1->valueSommet);

    //tree.createNode(node1->valueSommet);


    tree.fuse(Tree);



    tree.printTree(&w, 250, 250);
    w.show();
    return a.exec();
}
