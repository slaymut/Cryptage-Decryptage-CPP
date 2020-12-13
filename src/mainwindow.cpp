#include "../headers/mainwindow.h"

MainWindow::MainWindow()
{
    layout = new QGridLayout();
    setLayout(layout);


    lines = new PrintLine();
    lines->show();
    
    Zone_dessin = new QScrollArea();
    Zone_dessin->setWidget(lines);
    Zone_dessin->show();
    Zone_dessin->setMinimumSize(500,500);
    layout->addWidget(Zone_dessin, 0, 0);

    display_code = new Afficher_code();
    display_code->show();
    layout->addWidget(display_code, 1, 0);

    //Widget pour afficher les noms du groupe
    pNames = new PrintNames();
    pNames->show();
    layout->addWidget(pNames, 2, 0, Qt::AlignBottom);
    
    /*wMenu = new MainMenu();
    wMenu->setStyleSheet("background:rgb(75,0,130)");
    wMenu->show();
    layout->addWidget(wMenu, 0, 0);*/
}

MainWindow::~MainWindow()
{
}
