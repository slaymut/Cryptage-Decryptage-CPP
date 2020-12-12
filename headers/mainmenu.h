#pragma once

#include <QBoxLayout>
#include <QFrame>

//  Menu principal de l'application

class MainMenu : public QFrame
{
    
private:
    QHBoxLayout *layout;    
    
public:
    MainMenu();
    ~MainMenu();
};

