#pragma once

#include <QFrame>
#include <QGridLayout>
#include <QLabel>


// Frame to display both names

class PrintNames : public QFrame
{
private:
    QGridLayout *layout;
    QLabel *Name1;
    QLabel *Name2;

public:
    PrintNames(){
        layout = new QGridLayout();
        setLayout(layout);

        std::string Name = "Salim SLIMANI";
        Name1 = new QLabel(QString::fromStdString(Name));
        Name1->setStyleSheet("color: white;");
        Name1->show();
        layout->addWidget(Name1, 0, 0, Qt::AlignCenter);

        std::string nd_Name = "Mano RAKOTONIRINA";
        Name2 = new QLabel(QString::fromStdString(nd_Name));
        Name2->setStyleSheet("color: white;");
        Name2->show();
        layout->addWidget(Name2, 1, 0, Qt::AlignCenter);

        setFrameShape(Panel);
        setLineWidth(3);
        setFrameShadow(Sunken);
        setStyleSheet("background:rgb(45, 47, 124);");
    }

    ~PrintNames(){

    }
};

