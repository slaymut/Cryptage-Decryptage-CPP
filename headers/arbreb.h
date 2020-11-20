#ifndef ARBRE_B_HPP
#define ARBRE_B_HPP

#include "sommet.h"
#include "mainwindow.h"
#include <QLabel>


class ArbreB{
private:
    Sommet *root;
    //Scans the whole tree (and prints it)
    void scanTree(Sommet *node, MainWindow *w, int x, int y) const;
    //Get Tree max Level
    int maxLevel(Sommet *node) const;
    //Merge the value of two nodes to create a new one, linked to both previous nodes.
    ArbreB merge(const ArbreB &tree);
    int maximumLevel = 0;
public:
    //Constructors
    ArbreB(): root(nullptr){}
    ArbreB(const int &value){
        root = nullptr;
        root->setValue(value);
    }
    ArbreB(Sommet *someNode) : root(someNode), maximumLevel(maxLevel(someNode)){}
    //Copy constructor
    ArbreB(const ArbreB &arbre){
        if(arbre.root)
            root = new Sommet(*arbre.root);
    }

    //Methods 

    //Inserts a node in the tree.
    void insert(Sommet *node); 

    //Deletes a node in the tree 
     void m_delete(Sommet *target); 

    //Decompose a binary tree
    void decompose(ArbreB &Tree); 

    //Searches for a node in the tree
    Sommet* search(int val) const;

    //Prints the whole tree
    void printTree(MainWindow *w, int x, int y) const;

    //Modifies value of a node(target)
    void modifyNode(Sommet *target, int value);

    //Function to find minimum in a tree. 
    Sommet* FindMin(Sommet *node);

    //Operator + to return the result of two merged trees
    ArbreB operator+(const ArbreB &Tree){
        ArbreB newArbre{merge(Tree)};
        return newArbre;
    }

    //Operator += to merge two trees
    ArbreB operator+=(const ArbreB &Tree){
        ArbreB newArbre{merge(Tree)};
        return newArbre;
    }


    //Getters
    int getTreeMaxLevel(){return maximumLevel;}
    Sommet* getRoot(){return root;}

    void updateMaxDepth(){maximumLevel = maxLevel(root);}

    //Set depth of all nodes in the tree
    void setNodesDepth(Sommet *node, int level=0);

    //Destructor
    ~ArbreB(){
        if(root){
            delete root;
        }
    }
};


#endif
