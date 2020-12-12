#pragma once

#include <QFrame>
#include <QPainter>
#include <QFont>
#include "arbreb.h"

//  Widget pour afficher les traits de l'arbre
class PrintLine : public QFrame
{
private:
    void PrintSommets(Sommet* node, int currentX, int currentY);
    void PrintLines_Rect(Sommet* node, int P1x, int P1y);
public:
    PrintLine();
    void paintEvent(QPaintEvent *event);

    ~PrintLine(){}
};
