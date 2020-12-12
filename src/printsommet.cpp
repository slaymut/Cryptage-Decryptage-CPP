#include "../headers/printsommet.h"
#include <iostream>

PrintLine::PrintLine(){
    setFixedSize(1500, 600);
    PrintSommets(ArbreB::ArbreGenerique.getRoot(), 400, 75);
}

void PrintLine::PrintSommets(Sommet* node, int currentX, int currentY){
    if(node){
        QLabel *label = new QLabel(this);
        QFont f("Arial", 12, QFont::Bold);
        label->setFont(f);
        label->setStyleSheet("QLabel { color : black; }");
        label->setNum(node->getValue());
        //on a fait (currentX) + différence entre 400(taille min) et taille P1x dans paintEvent() ici 700 donc on fait currentX+300
        label->setGeometry(currentX+300, currentY, 3*node->getValue() + 10, 15);
        std::string rien = "";
        if (node->getLetters().length() > 1 ) node->setLetters(rien);
        QLabel *L_Text = new QLabel(QString::fromStdString(node->getLetters()), this);
        L_Text->setStyleSheet("QLabel { color : black; }");
        //on a fait (currentX+13) + différence entre 400(taille min) et taille P1x dans paintEvent() ici 700 donc on fait currentX+313
        L_Text->setGeometry(currentX+313, currentY, 7*node->getLetters().size(), 15);
    }

    if(node->getLeft()){
        PrintSommets(node->getLeft(), currentX - 30*(ArbreB::ArbreGenerique.getTreeMaxLevel()-node->getDepth() +1), currentY + 40 * (node->getDepth()+1));
    }

    if(node->getRight()){
        PrintSommets(node->getRight(), currentX + 30*(ArbreB::ArbreGenerique.getTreeMaxLevel()-node->getDepth() +1), currentY + 40 * (node->getDepth()+1));
    }
}

void PrintLine::PrintLines_Rect(Sommet* node, int P1x, int P1y){
    QPainter paint(this);
    QPen pen(Qt::red, 2, Qt::SolidLine);
    paint.setPen(pen);
    paint.setRenderHint(QPainter::Antialiasing, true);
    int left_next_X = P1x - 30*(ArbreB::ArbreGenerique.getTreeMaxLevel()-node->getDepth() +1);
    int right_next_X = P1x + 30*(ArbreB::ArbreGenerique.getTreeMaxLevel()-node->getDepth() +1);
    int next_Y = P1y + 40 * (node->getDepth()+1);
    if(node){
        paint.drawRect(P1x-10, P1y-2, 33, 20);
    }
    if(node->getLeft() || node->getRight()){
        paint.drawLine(P1x+5, P1y+18, P1x+5, P1y + 30);
        if(node->getLeft()){
            paint.drawText(( P1x + left_next_X  )/2,P1y+30,"1");
            paint.drawLine(P1x+5, P1y+30, left_next_X + 5, P1y +30);
            paint.drawLine(left_next_X + 5, P1y + 30, left_next_X + 5, next_Y - 4);
        }
        if(node->getRight()){
            paint.drawText(( ( P1x + right_next_X  )/2),P1y+30 ,"0");
            paint.drawLine(P1x+5, P1y+30, right_next_X + 5, P1y +30);
            paint.drawLine(right_next_X + 5, P1y + 30, right_next_X + 5, next_Y - 4);
        }
    }
    
    if(node->getLeft()){
        PrintLines_Rect(node->getLeft(), left_next_X, next_Y);
    }

    if(node->getRight()){
        PrintLines_Rect(node->getRight(), right_next_X, next_Y);
    }
    
}

void PrintLine::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    //on customise le pen&lignes et on trace les lignes
    
    PrintLines_Rect(ArbreB::ArbreGenerique.getRoot(), 700, 75);
}
