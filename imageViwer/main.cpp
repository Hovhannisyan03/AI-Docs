//#include "mainwindow.h"
#include <QApplication>
#include "viwer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *ptr = nullptr;
    viewer obj(ptr);
    obj.show();
    return a.exec();
}

