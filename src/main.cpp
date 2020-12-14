#include <QApplication>
#include "../headers/occurrence.hpp"
#include "../headers/mainwindow.h"
#include "../headers/Context.hpp"
#include "../headers/input.hpp"

int main(int argc, char **argv)
{

    std::string letters_to_use{};
    std::cout << '\n';
    std::cout << "----------------------------------------------------------------------" << '\n';
    std::cout << "| Please, type something in ENGLISH. AT LEAST 2 different characters.|" << '\n';
    std::cout << "| ONLY ENGLISH IS SUPPORTED. SPECIAL CHARACTERS ARE NOT IN THE TREE. |" << '\n';
    std::cout << "----------------------------------------------------------------------" << '\n';
    std::cout << '\n';
    std::cout << "Go ahead: "; 
    std::getline(std::cin, letters_to_use);
    verifyInput(letters_to_use);

    Context &context = Context::getInstance();
    context.setString(letters_to_use);

    QApplication app(argc, argv);
    MainWindow *window = new MainWindow();
    
    window->show();
    
    return app.exec();
}
