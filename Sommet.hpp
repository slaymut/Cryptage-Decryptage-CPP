#ifndef SOMMET_HPP
#define SOMMET_HPP

template<class Type>

class c_Sommet{
private:
    static int nbrNoeud;
    c_Sommet <Type> *left;
    c_Sommet <Type> *right;
    Type valueSommet;

public:
    c_Sommet(): valueSommet(nullptr) {}
    explicit c_Sommet(Type const &value) : valueSommet(value){}

    inline Type & getValue() const {return valueSommet;};

    ~c_Sommet(){
        delete left; delete right;
    }
};


#endif