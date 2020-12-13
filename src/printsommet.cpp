#include "../headers/printsommet.h"
#include <iostream>

PrintLine::PrintLine(){
    setFixedSize(1500, 600);
    arbre.setNodesDepth(arbre.getRoot(), 0);
    arbre.updateMaxDepth();
    int distance = 30*(arbre.getTreeMaxLevel()*2);
    PrintSommets(arbre.getRoot(), 750, 20, distance);
}

void PrintLine::PrintSommets(Sommet* node, int currentX, int currentY, int Separation1){
    
    if(node){
        QLabel *label = new QLabel(this);
        QFont f("Arial", 12, QFont::Bold);
        label->setFont(f);
        label->setNum(node->getValue());
        label->setGeometry(currentX-5, currentY, 3*node->getValue() + 10, 15);

        if (node->getLetters().length() > 1 ) node->setLetters("");
        QLabel *L_Text = new QLabel(QString::fromStdString(node->getLetters()), this);
        L_Text->setFont(f);
        L_Text->setStyleSheet("QLabel { color : black; }");
        L_Text->setGeometry(currentX+5, currentY, 10*node->getLetters().size(), 15);
    }

    int left_next_X = currentX - Separation1;
    int right_next_X = currentX + Separation1;
    int next_Y = currentY + 35 * (node->getDepth()+1);

    if(node->getLeft()){
        PrintSommets(node->getLeft(), left_next_X, next_Y, Separation1/2);
    }

    if(node->getRight()){
        PrintSommets(node->getRight(), right_next_X, next_Y, Separation1/2);
    }
}

void PrintLine::PrintLines_Rect(Sommet* node, int P1x, int P1y, int Separation1){

    QPainter paint(this);
    QPen pen(Qt::red, 2, Qt::SolidLine);
    paint.setPen(pen);
    paint.setRenderHint(QPainter::Antialiasing, true);
    int left_next_X = P1x - Separation1;
    int right_next_X = P1x + Separation1;
    int next_Y = P1y + 35 * (node->getDepth()+1);

    if(node){
        paint.drawRect(P1x-10, P1y-2, 30, 20);
    }
    if(node->getLeft() || node->getRight()){
        pen.setStyle(Qt::DotLine);
        paint.setPen(pen);
        paint.drawLine(P1x+5, P1y+18, P1x+5, P1y + 30);
        pen.setStyle(Qt::SolidLine);
        paint.setPen(pen);

        if(node->getLeft()){
            paint.drawLine(P1x+5, P1y+30, left_next_X + 5, P1y +30);
            paint.drawLine(left_next_X + 5, P1y + 30, left_next_X + 5, next_Y - 4);
        }
        if(node->getRight()){
            paint.drawLine(P1x+5, P1y+30, right_next_X + 5, P1y +30);
            paint.drawLine(right_next_X + 5, P1y + 30, right_next_X + 5, next_Y - 4);
        }
    }

    if(node->getLeft()){
        PrintLines_Rect(node->getLeft(), left_next_X, next_Y, Separation1/2);
    }

    if(node->getRight()){
        PrintLines_Rect(node->getRight(), right_next_X, next_Y, Separation1/2);
    }
}

void PrintLine::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    //on customise le pen&lignes et on trace les lignes
    int distance = 30*(arbre.getTreeMaxLevel()*2);
    PrintLines_Rect(arbre.getRoot(), 750, 20, distance);
}