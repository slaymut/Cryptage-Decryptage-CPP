#pragma once

#include <QFrame>
#include <QPainter>
#include <QFont>
#include "Context.hpp"

//  Widget pour afficher les traits de l'arbre
class PrintLine : public QFrame
{
private:
    void PrintSommets(Sommet* node, int currentX, int currentY, int Separation1);
    void PrintLines_Rect(Sommet* node, int P1x, int P1y, int Separation1);
    ArbreB arbre = Context::getInstance().getArbre();
public:
    PrintLine();

    void paintEvent(QPaintEvent *event);

    ~PrintLine(){}
};