#include"gra.h"
#include <QApplication>

Gra *g;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    g = new Gra();
    g->showFullScreen();

    return a.exec();
}
