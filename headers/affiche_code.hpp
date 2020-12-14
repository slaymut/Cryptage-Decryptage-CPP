#pragma once

#include <QFrame>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QFont>
#include "Context.hpp"


//  Display text to code and the binary code

class Afficher_code : public QFrame
{
    Q_OBJECT
    
private:
    QGridLayout *layout;
    QLineEdit *Input_String;
    QPushButton *valider_string;
    QLabel *StringText;
    QLabel *StringBinaire;

public:
    Afficher_code(){
        layout = new QGridLayout();
        setLayout(layout);
        QFont f("Monospace", 10);

        std::string input_text{};
        if(Context::getInstance().getCodage().size() > 60){
            std::string changedText = Context::getInstance().getString();
            for(int i = 0; i < Context::getInstance().getString().size()/60; i++){
                changedText.insert((i+1)*60, "\n");
            }
            input_text = "Texte entré:\n" + changedText;
        }
        else{
            input_text = "Texte entré: " + Context::getInstance().getString();
        }

        StringText = new QLabel(QString::fromStdString(input_text));
        StringText->setFont(f);
        StringText->setStyleSheet("color: white;");
        StringText->show();
        layout->addWidget(StringText, 0, 0, Qt::AlignLeft);

        std::string output_binaire{};
        if(Context::getInstance().getCodage().size() > 70){
            std::string changedBinaire = Context::getInstance().getCodage();
            for(int i = 0; i < Context::getInstance().getCodage().size()/70; i++){
                changedBinaire.insert((i+1)*70, "\n");
            }
            output_binaire = "Code binaire:\n" + changedBinaire;
        }
        else{
            output_binaire = "Code binaire: " + Context::getInstance().getCodage();
        }

        StringBinaire = new QLabel(QString::fromStdString(output_binaire));
        StringBinaire->setFont(f);
        StringBinaire->setStyleSheet("color: white;");
        StringBinaire->show();
        layout->addWidget(StringBinaire, 1, 0, Qt::AlignLeft);
        
        setStyleSheet("background:rgb(45, 47, 124);");

        Input_String = new QLineEdit();
        Input_String->setStyleSheet("background:rgb(109, 110, 189);");
        Input_String->show();
        layout->addWidget(Input_String, 2, 0);

        valider_string = new QPushButton("Valider", this);
        valider_string->setStyleSheet("background:rgb(89, 91, 219);");
        valider_string->show();
        layout->addWidget(valider_string, 2, 1);

        setFrameShape(Box);
        setLineWidth(2);
        setFrameShadow(Raised);

        connect(valider_string, SIGNAL(clicked()), this, SLOT(setString()));
        connect(Input_String, SIGNAL(returnPressed()), this, SLOT(setString()));

        connect(&Context::getInstance(), SIGNAL(stringChanged()), this, SLOT(stringChanged()));
    }

    ~Afficher_code(){}

public slots:
    void setString(){
        Context::getInstance().setString(Input_String->text().toStdString());
    }

    void stringChanged(){
        std::string input_text{};
        if(Context::getInstance().getCodage().size() > 60){
            std::string changedText = Context::getInstance().getString();
            for(int i = 0; i < Context::getInstance().getString().size()/60; i++){
                changedText.insert((i+1)*60, "\n");
            }
            input_text = "Texte entré:\n" + changedText;
        }
        else{
            input_text = "Texte entré: " + Context::getInstance().getString();
        }
        
        std::string output_binaire{};
        if(Context::getInstance().getCodage().size() > 70){
            std::string changedBinaire = Context::getInstance().getCodage();
            for(int i = 0; i < Context::getInstance().getCodage().size()/70; i++){
                changedBinaire.insert((i+1)*70, "\n");
            }
            output_binaire = "Code binaire:\n" + changedBinaire;
        }
        else{
            output_binaire = "Code binaire: " + Context::getInstance().getCodage();
        }
        StringText->setText(QString::fromStdString(input_text));
        StringBinaire->setText(QString::fromStdString(output_binaire));

        Input_String->setText("");
    }

signals:

};

