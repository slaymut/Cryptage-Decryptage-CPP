#pragma once

#include <QFrame>
#include <QPainter>
#include <QFont>
#include "Context.hpp"

//  Widget pour afficher les traits de l'arbre
class TreePrinter : public QFrame
{
    Q_OBJECT
private:
    //Recursive method to draw to full Tree
    void PrintArbre(Sommet* node, int P1x, int P1y, int Separation1);

    //Current Tree
    ArbreB arbre = Context::getInstance().getArbre();
public:
    TreePrinter();

    //Method to paint
    void paintEvent(QPaintEvent *event);

    ~TreePrinter(){}

public slots:
    //Paints the new current Tree
    void arbreChanged();

signals:
};