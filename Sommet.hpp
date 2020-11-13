#ifndef SOMMET_HPP
#define SOMMET_HPP
#include <cstddef>


class c_Sommet{
private:
    double frequence;
    char symbol;
    int depth = 0;
    // Array of references to this node's children
    const c_Sommet* children[2];
public:
    int valueSommet;
    c_Sommet *left = nullptr;
    c_Sommet *right = nullptr;

    //Constructor
    c_Sommet() = delete;
    c_Sommet(int const &value) : valueSommet(value){}
    c_Sommet(c_Sommet *leftChild, c_Sommet *rightChild) {
        frequence = leftChild->frequence + rightChild->frequence;

        children[0] = leftChild;
        children[1] = rightChild;

        // internal nodes don't represent a single symbol ( noeud contient somme des fréquences (la fréquence de chaque fils(les 2 fils quoi)) go discord pour le schéma)
        symbol = 0;
    };
    c_Sommet(double freq, char sym) {
        frequence = freq ;
        // these children will ALWAYS be NULL since this is a leaf node(feuilles de l'arbre)
        children[0] = nullptr;
        children[1] = nullptr;
        symbol = sym;
    };
    
    //Destructor
    ~c_Sommet(){
        delete left; delete right;
    }

    void setDepth(int theDepth){
        depth = theDepth;
    }

    int &getDepth(){ return depth; };

    /*
     * Je pense que ces getters sont inutiles sachant que LEFT et RIGHT sont public ;)
     * Il faudrait les supprimer à mon avis.
     */

    //Getter
    /*virtual c_Sommet &get_left() const {return *left;};
    virtual c_Sommet &get_right() const {return *right;};*/


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