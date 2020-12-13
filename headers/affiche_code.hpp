#pragma once

#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QFont>
#include "Context.hpp"


//  Fenetre pour afficher les noms

class Afficher_code : public QFrame
{
private:
    QGridLayout *layout;
    QLabel *StringText;
    QLabel *StringBinaire;

public:
    Afficher_code(){
        layout = new QGridLayout();
        setLayout(layout);
        QFont f("Arial", 12);

        std::string input_text = "Texte entré: " + Context::getInstance().getString();
        StringText = new QLabel(QString::fromStdString(input_text));
        StringText->setFont(f);
        StringText->show();
        layout->addWidget(StringText, 0, 0, Qt::AlignLeft);

        std::string output_binaire = "Code binaire: " + Context::getInstance().getCodage();
        StringBinaire = new QLabel(QString::fromStdString(output_binaire));
        StringBinaire->setFont(f);
        StringBinaire->show();
        layout->addWidget(StringBinaire, 1, 0, Qt::AlignLeft);
        setFrameShape(Panel);
        setFrameShadow(Sunken);
        //setStyleSheet("background-color: black");
    }

    ~Afficher_code(){

    }

};

