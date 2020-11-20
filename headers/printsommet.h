#ifndef PRINTSOMMET_H
#define PRINTSOMMET_H

#include <QWidget>
#include <QPainter>

//  Widget pour afficher les traits de l'arbre
class PrintLine : public QWidget
{
private:
    QPoint P1;
    QPoint P2;
public:
    PrintLine(QWidget *parent = nullptr) : QWidget(parent){
		}

    void setPrint(int P1x, int P1y, int P2x, int P2y);

    void paintEvent(QPaintEvent *event);

    ~PrintLine(){}
};

#endif // PRINTSOMMET_H
