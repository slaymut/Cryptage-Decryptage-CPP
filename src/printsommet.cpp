#include "../headers/printsommet.h"
#include <iostream>


void PrintLine::setPrint(int P1x, int P1y, int P2x, int P2y)
{
    //P1 et P2 prennent les valeurs prises en paramètre
    P1 += QPoint(P1x,P1y);
    P2 += QPoint(P2x,P2y);
}

void PrintLine::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    //on customise le pen&lignes et on trace les lignes
    QPainter paint(this);
    QPen pen(Qt::blue, 2, Qt::SolidLine);
    paint.setPen(pen);
    paint.setRenderHint(QPainter::Antialiasing, true);
    paint.drawLine(P1,P2);
}
