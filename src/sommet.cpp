#include "../headers/sommet.h"

#include <QLabel>

void Sommet::setLeft(const Sommet &node){
    if(left)
        delete left;
    left = new Sommet{node};
}

void Sommet::setRight(const Sommet &node){
    if(right)
        delete right;
    right = new Sommet{node};
}

//Prints the tree nodes on the window
/*void Sommet::print(MainWindow *wind, int x, int y, int max){
    //Number of digits of valueSommet
    int digits = 1;
    int tmp = valueSommet;
    while(tmp > 0){
        tmp /= 10;
        digits++;
    }

    //Print left node if it exists
    if(this->left){
        PrintLine *som = new PrintLine(wind);
        som->resize(1100, 600);
        som->setPrint(x - 30*(ArbreB::ArbreGenerique.getTreeMaxLevel() - this->getDepth())+(3+digits), y + 40 * (getDepth()+1), x + digits*3, y+17);
    }

    //Print left node if it exists
    if(this->right){
        PrintLine *som = new PrintLine(wind);
        som->resize(1100, 600);
        som->setPrint(x + 30*(ArbreB::ArbreGenerique.getTreeMaxLevel() - this->getDepth())+(3+digits), y + 40 * (getDepth()+1), x + digits*3, y+17);
    }

    //Print each node's value
    QLabel *label = new QLabel(wind);
    label->setStyleSheet("QLabel { color : white; }");
    label->setNum(valueSommet);
    label->setGeometry(x, y, 7*digits, 15);
}*/

Sommet::~Sommet(){
    if(right) delete right;
    if(left) delete left;
}

