#ifndef SOMMET_HPP
#define SOMMET_HPP
#include <cstddef>
template<class Type>

class c_Sommet{
private:
    static int nbrNoeud;
    double frequence ;
    char symbol ;
    // Array of references to this node's children
    const c_Sommet* children[2];
public:
    const c_Sommet* node;
    Type valueSommet;
    //Constructor
    c_Sommet(): valueSommet(nullptr) {};
    c_Sommet(c_Sommet leftChild,c_Sommet rightChild) {
        frequence = leftChild->frequence + rightChild->frequence;
    
        children[0] = leftChild;
        children[1] = rightChild;
    
        // internal nodes don't represent a single symbol ( noeud contient somme des fréquences (la fréquence de chaque fils(les 2 fils quoi)) go discord pour le schéma)
        symbol = 0;
    };
    c_Sommet(double freq, char sym) {
        frequence = freq ;
         // these children will ALWAYS be NULL since this is a leaf node(feuilles de l'arbre)
        children[0] = NULL;
        children[1] = NULL;
        symbol = sym;
    };
    explicit c_Sommet(Type const &value) : valueSommet(value){};

    //Getters
    inline Type & getValue() const {return valueSommet;};
    c_Sommet <Type> *left;
    c_Sommet <Type> *right;
    virtual c_Sommet <Type> &get_left() const {return *left;};
    virtual c_Sommet <Type> &get_right() const {return *right;};
    //Destructor
    ~c_Sommet(){
        delete left; delete right;
    }
    //J'aurais pensé à ce destructor du coup
    /*
    ~c_Sommet(){
         if(children[0])
        {
            delete children[0];
        }

        if(children[1])
        {
            delete children[1];
        }
    }
    */
};


#endif