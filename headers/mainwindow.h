#pragma once

#include "printnames.h"
#include "printsommet.h"
#include "affiche_code.hpp"
#include "list_displayer.hpp"
#include <QScrollArea>
#include <QWidget>
#include <QPushButton>
#include <QApplication>


// Main Window for our application

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    QGridLayout *layout;
    PrintNames *pNames;
    QScrollArea *Zone_dessin;
    TreePrinter *wPrinter;
    Afficher_code *display_code;
    Afficher_liste *list_display;

};
