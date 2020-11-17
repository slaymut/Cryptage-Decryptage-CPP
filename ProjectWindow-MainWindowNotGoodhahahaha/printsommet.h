#ifndef PRINTSOMMET_H
#define PRINTSOMMET_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>


class PrintSommet : public QWidget
{
private:
    QPoint P1, P2;
    int radius;
public:
    PrintSommet(QWidget *parent = nullptr) : QWidget(parent){}

    void setPrint(int P1x, int P1y, int P2x, int P2y, int radius);

    void paintEvent(QPaintEvent *event);
};

#endif // PRINTSOMMET_H
