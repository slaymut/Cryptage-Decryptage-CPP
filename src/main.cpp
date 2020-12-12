#include <QApplication>
#include "../headers/occurrence.hpp"
#include "../headers/mainwindow.h"

ArbreB ArbreB::ArbreGenerique{};

int main(int argc, char **argv)
{
    std::string letters_to_use{};
    std::cout << "Please, type something." << '\n';
    std::getline(std::cin, letters_to_use);

    //vecteur 1 char + occurrence 
    std::vector<std::pair<char, int>> vecteur = getOccurence(letters_to_use);
    //vecteur 2 arbre
    std::vector<ArbreB> vecteur2;
    int i = 0;
    for (auto v : vecteur ){
        std::string first{v.first};    
        ArbreB One{new Sommet(first, v.second)};
        vecteur2.insert(vecteur2.begin()+i, One);
    }
    ArbreB Tree;
    
    while(vecteur2.size() > 1){
        ArbreB maintTree{}, Tree2;
        maintTree = findMin(vecteur2);
        Tree2 = findMin(vecteur2);
        Tree = ArbreB{maintTree + Tree2};
        vecteur2.push_back(Tree);
        std::cout << "This Arbre: " << Tree.getRoot()->getLetters() << " " << Tree.getRoot()->getValue() << '\n'; 
    }
    ArbreB::ArbreGenerique = Tree;
    ArbreB::ArbreGenerique.setNodesDepth(ArbreB::ArbreGenerique.getRoot(), 0);
    ArbreB::ArbreGenerique.updateMaxDepth();
    
    QApplication app(argc, argv);
    MainWindow *window = new MainWindow();
    /*std::string a{};
    getCode(Tree.getRoot(), "a", a);
    std::cout << "Here's the code: " << a << '\n';
    */
    window->show();
    
    return app.exec();
}
