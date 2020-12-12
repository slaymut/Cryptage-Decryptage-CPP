#include "../headers/mainmenu.h"

MainMenu::MainMenu()
{
    layout = new QHBoxLayout();
    setLayout(layout);
    setFixedSize(1100, 600);

    //Shapes of the menu
    setFrameShape(Box);
    setLineWidth(2);
    setFrameShadow(Sunken);
}

MainMenu::~MainMenu(){

}
