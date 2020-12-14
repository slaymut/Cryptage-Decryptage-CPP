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
    Afficher_liste(){
        layout = new QGridLayout();
        setLayout(layout);
        
        QFont f("Monospace", 12);
        std::string input_text = "Liste des codes binaires";
        StringText = new QLabel(QString::fromStdString(input_text));
        StringText->setFont(f);
        StringText->setStyleSheet("color: white;");
        StringText->show();
        layout->addWidget(StringText, 0, 0, Qt::AlignTop);

        StringBinaire = new QLabel(QString::fromStdString(""));

        std::string output_binaire{};
        for(int i = 0; i < char_string.size(); i++){
            std::string separation{":  "};
            output_binaire += char_string[i].first + separation + char_string[i].second + '\n';
        }
        StringBinaire->setText(QString::fromStdString(output_binaire));
        QFont f2("Monospace", 12 - char_string.size()/10);
        StringBinaire->setFont(f2);
        StringBinaire->setStyleSheet("color: white;");
        StringBinaire->show();
        layout->addWidget(StringBinaire, 2, 0, Qt::AlignCenter);

        Quit = new QPushButton("Quitter", this);
        Quit->setStyleSheet("background:rgb(89, 91, 219);");
        Quit->show();
        layout->addWidget(Quit, 3, 0, Qt::AlignBottom);

        connect(Quit, SIGNAL(clicked()), qApp, SLOT(quit()));
        connect(&Context::getInstance(), SIGNAL(stringChanged()), this, SLOT(listChanged()));

        setFrameShape(Panel);
        setLineWidth(3);
        setFrameShadow(Sunken);
        setStyleSheet("background:rgb(45, 47, 124);");
    }

    ~Afficher_liste(){

    }

public slots:
    void listChanged(){
        char_string = Context::getInstance().getChar_Codes();
        std::string output_binaire{};
        for(int i = 0; i < char_string.size(); i++){
            std::string separation{":  "};
            output_binaire += char_string[i].first + separation + char_string[i].second + '\n';
        }
        StringBinaire->setText(QString::fromStdString(output_binaire));
        StringBinaire->setFont(QFont("Monospace", 12 - char_string.size()/10));
    }

signals:

};