#include "sommet.h"
#include "printsommet.h"

#include <QLabel>


void c_Sommet::print(MainWindow *wind, int x, int y){
    //Number of digits to set the radius
    int digits = 1;
    int tmp = valueSommet;
    while(valueSommet > 0){
        tmp /= 10;
        digits++;
    }

    if(this->left){
        PrintSommet *som = new PrintSommet(wind);
        som->setPrint(x, y, x - 50, y - 35, digits*10);
    }
    if(this->right){
        PrintSommet *som = new PrintSommet(wind);
        som->setPrint(x, y, x + 50, y - 35, digits*10);
    }

    QLabel *label = new QLabel(wind);
    label->setNum(valueSommet);
    label->setGeometry(x, y, 50, 50);
    label->raise();


}
