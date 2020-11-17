#include "printsommet.h"

void PrintSommet::setPrint(int P1x, int P1y, int P2x, int P2y, int value)
{
    this->P1 = QPoint(P1x, P1y);
    this->P2 = QPoint(P2x, P2y);
    this->radius = value;
}

void PrintSommet::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter paint(this);
    QPen pen(Qt::blue);

    paint.setPen(pen);
    paint.drawLine(P1, P2);
    paint.drawEllipse(P1, radius, radius);
}
