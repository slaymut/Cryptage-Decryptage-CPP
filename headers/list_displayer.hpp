#pragma once

#include <QFrame>
#include <QGridLayout>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include "Context.hpp"


//  Fenetre pour afficher les noms

class Afficher_liste : public QFrame
{
    Q_OBJECT
private:
    QGridLayout *layout;
    QLabel *StringText;
    QLabel *StringBinaire;
    QPushButton *Quit;
    std::vector<std::pair<char, std::string>> char_string = Context::getInstance().getChar_Codes();

public:
    //Constructor
    Afficher_liste();

    //Destructor
    ~Afficher_liste();

public slots:
    //Change display of the list
    void listChanged();

signals:

};