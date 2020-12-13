#pragma once

#include "mainmenu.h"
#include "printnames.h"
#include "printsommet.h"
#include "affiche_code.hpp"
#include <QScrollArea>
#include <QWidget>
#include <QPushButton>
#include <QApplication>


//  Fenetre principal de l'application

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    QGridLayout *layout;
    MainMenu* wMenu;
    PrintNames *pNames;
    QScrollArea *Zone_dessin;
    PrintLine *lines;
    Afficher_code *display_code;
};
