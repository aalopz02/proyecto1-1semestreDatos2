#include <QApplication>
#include "Window.h"

/**
 * @brief Main : Funcion main que llama a la ventana principal para iniciar la aplicación
 */
int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    QWidget *window = new Window;
    window->show();
    return app.exec();
}
