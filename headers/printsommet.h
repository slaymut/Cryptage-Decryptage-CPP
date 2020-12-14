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
    void PrintLines_Rect(Sommet* node, int P1x, int P1y, int Separation1);
    ArbreB arbre = Context::getInstance().getArbre();
public:
    TreePrinter();

    void paintEvent(QPaintEvent *event);

    ~TreePrinter(){}

public slots:
    void arbreChanged();

signals:
};