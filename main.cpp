#include "mainwindow.h"
#include <cuaso.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    CuaSo cuaSo;
    cuaSo.show();

    return a.exec();
}
