#include "../headers/printsommet.h"
#include <iostream>

TreePrinter::TreePrinter(){
    setFixedSize(2000, 1500);
    arbre.setNodesDepth(arbre.getRoot(), 0);
    arbre.updateMaxDepth();
    setStyleSheet("background:rgb(45, 47, 124);");
}

void TreePrinter::PrintArbre(Sommet* node, int P1x, int P1y, int Separation1){
    
    QPainter paint(this);
    QPen pen(Qt::white, 2, Qt::SolidLine);
    paint.setPen(pen);
    paint.setRenderHint(QPainter::Antialiasing, true);
    int left_next_X = P1x - Separation1;
    int right_next_X = P1x + Separation1;
    int next_Y = P1y + 35 * ((node->getDepth()+2)/2 + 1);
    int theY = (next_Y - P1y)/2;

    if(node){
        std::string number{std::to_string(node->getValue())};
        number.erase(number.begin()+number.size()-5, number.end());
        
        paint.drawRect(P1x-10 - number.size(), P1y-2, 30 + number.size()*2, 20);
        paint.setPen(QPen(Qt::white, 2, Qt::SolidLine));
        if (node->getLeft() || node->getRight()){
            node->setLetters("");
            paint.drawText(P1x-number.size()*2 - 2, P1y+12, QString::fromStdString(number));
        }
        else{
            paint.drawRect(P1x-10 - number.size(), P1y+18, 30 + number.size()*2 , 20);
            paint.drawText(P1x, P1y+12, QString::fromStdString(node->getLetters()));
            paint.drawText(P1x-number.size()*2 - 2, P1y+32, QString::fromStdString(number));
        }
        paint.setPen(QPen(Qt::white, 2, Qt::SolidLine));
    }
    if(node->getLeft() || node->getRight()){
        pen.setStyle(Qt::DotLine);
        paint.setPen(pen);
        paint.drawLine(P1x+5, P1y+18, P1x+5, P1y + theY);
        pen.setStyle(Qt::SolidLine);
        paint.setPen(pen);

        if(node->getLeft()){
            paint.drawLine(P1x+5, P1y+ theY, left_next_X + 5, P1y + theY);
            paint.drawLine(left_next_X + 5, P1y + theY, left_next_X + 5, next_Y - 4);
        }
        if(node->getRight()){
            paint.drawLine(P1x+5, P1y+theY, right_next_X + 5, P1y +theY);
            paint.drawLine(right_next_X + 5, P1y + theY, right_next_X + 5, next_Y - 4);
        }
    }

    if(node->getLeft()){
        PrintArbre(node->getLeft(), left_next_X, next_Y, Separation1/2);
    }

    if(node->getRight()){
        PrintArbre(node->getRight(), right_next_X, next_Y, Separation1/2);
    }
}

void TreePrinter::paintEvent(QPaintEvent *event){
    int distance = 30*(arbre.getTreeMaxLevel()*2) + arbre.getTreeMaxLevel()*10;
    PrintArbre(arbre.getRoot(), 1000, 20, distance);

    connect(&Context::getInstance(), SIGNAL(arbreChanged()), this, SLOT(arbreChanged()));
}

void TreePrinter::arbreChanged(){
    arbre = Context::getInstance().getArbre();
    arbre.setNodesDepth(arbre.getRoot(), 0);
    arbre.updateMaxDepth();
    repaint();
}