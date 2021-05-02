#pragma once

#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include "Context.hpp"

//Frame to input the binary code

class Write_Code : public QFrame{
    Q_OBJECT

private:
    QGridLayout *layout;
    QLabel *Title;
    QLabel *filler;
    QLineEdit *Input_String;

public:
    Write_Code(){
        layout = new QGridLayout();

        setLayout(layout);

        QFont f("Monospace", 12);

        Title = new QLabel(QString::fromStdString("Entrez un texte en binaire:"));
        Title->setFont(f);
        Title->setStyleSheet("color: white;");
        Title->show();
        layout->addWidget(Title, 0, 0, Qt::AlignTop);

        Input_String = new QLineEdit();
        Input_String->setStyleSheet("background:rgb(109, 110, 189);");
        Input_String->show();
        layout->addWidget(Input_String,1,0);
        
        filler = new QLabel();
        filler->show();
        layout->addWidget(filler,2,0, Qt::AlignBottom);
        

        setFrameShape(Panel);
        setLineWidth(3);
        setFrameShadow(Sunken);
        setStyleSheet("background:rgb(45, 47, 124);");

        connect(Input_String, SIGNAL(returnPressed()), this, SLOT(setCode()));
    }

    ~Write_Code(){

    }

public slots:
    void setCode(){
        Context::getInstance().setDecodingString(Input_String->text().toStdString());
        if(Context::getInstance().getIncorrect()){
            QMessageBox::information(this, tr("ERREUR"), tr("Le code binaire n'est pas valable."));
        }
        Input_String->setText("");
    }

};

//Frame to display the binary code


class Display_Text : public QFrame{
    Q_OBJECT

private:
    QGridLayout *layout;
    QLabel *Title;
    QLabel *TextDecoded;
    QLabel *filler;

public:
    Display_Text(){
        layout = new QGridLayout();
        setLayout(layout);
        QFont f("Monospace", 12);
        Title = new QLabel(QString::fromStdString("Résultat du code binaire crypté"));
        Title->setFont(f);
        Title->setStyleSheet("color: white;");
        Title->show();
        layout->addWidget(Title, 0, 0, Qt::AlignTop);
        
        TextDecoded = new QLabel();
        TextDecoded->setStyleSheet("color: white;");
        TextDecoded->setFont(QFont("Monospace", 12));
        TextDecoded->show();
        layout->addWidget(TextDecoded, 1, 0, Qt::AlignCenter);
        
        filler = new QLabel();
        filler->show();
        layout->addWidget(filler,2,0, Qt::AlignBottom);

        connect(&Context::getInstance(), SIGNAL(codeChanged()), this, SLOT(codeChanged()));
        setFrameShape(Panel);
        setLineWidth(3);
        setFrameShadow(Sunken);
        setStyleSheet("background:rgb(45, 47, 124);");
    }
    
    ~Display_Text(){

    }

public slots:
    void codeChanged(){
        std::string code = Context::getInstance().getDecString();
        if(code.size() > 30){
            std::string changedBinaire = Context::getInstance().getDecString();
            for(int i = 0; i < Context::getInstance().getDecString().size()/30; i++){
                changedBinaire.insert((i+1)*30, "\n");
            }
            code = changedBinaire;
        }
        TextDecoded->setText(QString::fromStdString(code));
    }

};