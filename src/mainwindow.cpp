#include "../headers/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    
    layout = new QGridLayout();
    setLayout(layout);

    //Widget pour afficher les noms du groupe
    pNames = new PrintNames();
    pNames->show();
    layout->addWidget(pNames, 1, 0, Qt::AlignBottom);
    

    //Widget qui contient le menu principal de l'application
    wMenu = new MainMenu();
    wMenu->setStyleSheet("background:rgb(75,0,130)");
    wMenu->show();
    wMenu->setFixedSize(950,500);
    layout->addWidget(wMenu, 0, 0);

    

    /* Not implemented yet ScrollArea   
    *
    *
    Zone_dessin = new QScrollArea();
    Zone_dessin->show();
    //Zone_dessin->setWidgetResizable(true);
    //Zone_dessin->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //Zone_dessin->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //Zone_dessin->setFixedSize(1000,400);
    layout->addWidget(Zone_dessin);
    
    
    /*Not implemented yet Button "QUITTER"
    *
    *
    Quitter = new QPushButton("Quitter", this);
	Quitter->show();
	layout->addWidget(Quitter,2,0);

	connect(Quitter, SIGNAL(clicked()), qApp, SLOT(quit()));    
    */
}

MainWindow::~MainWindow()
{
}
