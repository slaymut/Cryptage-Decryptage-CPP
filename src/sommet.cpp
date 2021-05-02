#include "../headers/sommet.h"

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

Sommet::~Sommet(){
    if(right) delete right;
    if(left) delete left;
}

