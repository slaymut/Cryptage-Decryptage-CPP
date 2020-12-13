#include <QApplication>
#include "../headers/occurrence.hpp"
#include "../headers/mainwindow.h"
#include "../headers/Context.hpp"

int main(int argc, char **argv)
{
    std::string letters_to_use{};
    std::cout << "Please, type something." << '\n';
    std::getline(std::cin, letters_to_use);

    Occurrence *Occu = new Occurrence(letters_to_use);

    Context &context = Context::getInstance();
    context.setArbre(Occu->getArbre());
    context.setString(letters_to_use);
    context.setCodageHuff(Occu->getBinaryCode());

    QApplication app(argc, argv);
    MainWindow *window = new MainWindow();
    
    window->show();
    
    return app.exec();
}
