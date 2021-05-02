#include "../headers/mainwindow.h"

MainWindow::MainWindow()
{
    layout = new QGridLayout();
    setLayout(layout);
    ndWindow = new SecondWindow();
    
    wPrinter = new TreePrinter();
    wPrinter->show();
    
    Zone_dessin = new QScrollArea();
    Zone_dessin->setWidget(wPrinter);
    Zone_dessin->setStyleSheet("background-color: white;");
    Zone_dessin->show();
    Zone_dessin->setMinimumSize(650,500);
    layout->addWidget(Zone_dessin, 0, 0);

    list_display = new Afficher_liste();
    list_display->show();
    layout->addWidget(list_display, 0, 1, Qt::AlignRight);

    toggle_decryptage = new QPushButton("Fenetre : Decrypter", this);
    toggle_decryptage->setStyleSheet("background:rgb(89, 91, 219);");
    toggle_decryptage->show();
    layout->addWidget(toggle_decryptage, 1, 1);

    display_code = new Afficher_code();
    display_code->show();
    layout->addWidget(display_code, 2, 0);

    pNames = new PrintNames();
    pNames->show();
    layout->addWidget(pNames, 2, 1);

    connect(toggle_decryptage, SIGNAL(clicked()), this, SLOT(on_toggle_decrypt()));
    setStyleSheet("background:rgb(9, 10, 52);");
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_toggle_decrypt(){
    ndWindow->show();
}