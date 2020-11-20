#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "mainmenu.h"
#include "printnames.h"
#include <QGridLayout>
#include <QScrollArea>
#include <QWidget>
#include <QPushButton>
#include <QApplication>


//  Fenetre principal de l'application

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGridLayout *layout;
    MainMenu* wMenu;
    PrintNames *pNames;

    /*
    QPushButton *Quitter;    
    QScrollArea* Zone_dessin;
    */
};
#endif // MAINWINDOW_H
