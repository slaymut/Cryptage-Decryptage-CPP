#pragma once

#include "sommet.h"
#include <QLabel>


class ArbreB{
private:
    Sommet *root;
    //Scans the whole tree (and prints it)
    //void scanTree(Sommet *node, MainWindow *w, int x, int y) const;
    //Set depth of all nodes in the tree
    
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
    ArbreB(const ArbreB &arbre){
        if(arbre.root){
            root = new Sommet(*arbre.root);
        }
    }
    ArbreB(Sommet *someNode) : root(someNode), maximumLevel(maxLevel(someNode)){}

    static ArbreB ArbreGenerique;

    ArbreB& operator=(const ArbreB& Tree){
        if(root) delete root;
        root = new Sommet(*Tree.getRoot());
        maximumLevel = Tree.getTreeMaxLevel();

        return *this;
    }

    //Methods 
    //Inserts a node in the tree.
    void insert(Sommet *node); 
void setNodesDepth(Sommet *node, int level) const ;
    //Deletes a node in the tree 
     void m_delete(Sommet *target); 

    //Decompose a binary tree
    void decompose(ArbreB &Tree); 

    //Searches for a node in the tree
    Sommet* search(int val) const;

    //Prints the whole tree
    //void printTree(MainWindow *w, int x, int y) const;

    //Modifies value of a node(target)
    void modifyNode(Sommet *target, int value);

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
    int getTreeMaxLevel() const {return maximumLevel;}
    Sommet* getRoot(){return root;}
    Sommet* getRoot() const {return root;}

    void setRoot(Sommet *a_Node){
        if(root) delete root;
        root = new Sommet(*a_Node);
    }

    void updateMaxDepth(){maximumLevel = maxLevel(root);}

   

    //Destructor
    ~ArbreB(){
        if(root){
            delete root;
        }
    }
};
