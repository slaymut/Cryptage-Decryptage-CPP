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
    //Constructor
    Afficher_code();

    //Destructor
    ~Afficher_code();

public slots:
    //Sets a new string and sends it to the Context
    void setString();

    //Updates string to code and its binary code
    void stringChanged();
signals:

};

