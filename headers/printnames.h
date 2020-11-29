#ifndef PRINTNAMES_H
#define PRINTNAMES_H

#pragma once
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QApplication>


//  Fenetre pour afficher les noms

class PrintNames : public QFrame
{
private:
    QGridLayout *layout;
    QLabel *NameSurname;


public:
    PrintNames(){
        layout = new QGridLayout();
        setLayout(layout);

        std::string Name = "Salim SLIMANI - Mano RAKOTONIRINA";
        NameSurname = new QLabel(QString::fromStdString(Name));
        NameSurname->show();
        layout->addWidget(NameSurname, 0, 0, Qt::AlignCenter);

        setFrameShape(Box);
        setLineWidth(3);
        setFrameShadow(Sunken);
        //setStyleSheet("background-color: black");
    }

    ~PrintNames(){

    }

};

#endif // PRINTNAMES_H
