#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(250,250,500,500);
    w.setWindowTitle("To Do List");
    w.show();
    return a.exec();
}
