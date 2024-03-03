#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow obj;
    obj.setGeometry(250,250,500,500);
    obj.setWindowTitle("Simple Form with Validation");
    obj.show();

    return a.exec();
}
