#include "../headers/mainmenu.h"

MainMenu::MainMenu()
{
    layout = new QHBoxLayout();
    setLayout(layout);

    //Shapes of the menu
    setFrameShape(Box);
    setLineWidth(2);
    setFrameShadow(Sunken);
}

MainMenu::~MainMenu(){

}
