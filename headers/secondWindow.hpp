#pragma once

#include "Window2Widgets.hpp"
#include <QWidget>
#include <QPushButton>
#include <iostream>
#include <QApplication>

//Second window to display the decoding frames.

class SecondWindow : public QWidget {
    Q_OBJECT
    
private:
    QGridLayout *layout;
    QPushButton *Quit;
    QPushButton *Crypt;
    Display_Text *Decoded_Text;
    Write_Code *Text;

public:
    SecondWindow(QWidget *parent = nullptr) : QWidget(parent){
        layout = new QGridLayout();
        setLayout(layout);

        setFixedSize(700, 500);

        Quit = new QPushButton("Quitter", this);
        Quit->setStyleSheet("background:rgb(89, 91, 219);");
        Quit->show();
        layout->addWidget(Quit, 1, 0);

        Crypt = new QPushButton("Fenetre : Crypter", this);
        Crypt->setStyleSheet("background:rgb(89, 91, 219);");
        Crypt->show();
        layout->addWidget(Crypt, 1, 1);

        Text = new Write_Code();
        Text->show();
        layout->addWidget(Text, 0, 0);

        Decoded_Text = new Display_Text();
        Decoded_Text->show();
        layout->addWidget(Decoded_Text, 0, 1);

        connect(Crypt, SIGNAL(clicked()), this, SLOT(show_other_window()));
        connect(Quit, SIGNAL(clicked()), qApp, SLOT(quit()));
        
        setStyleSheet("background:rgb(9, 10, 52);");
    }

    ~SecondWindow(){}

private slots:
    void show_other_window(){
        hide();
    }
};