#include "mainwindow.h"
#include "texteditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *ptr = nullptr;
    textEditor obj(ptr);
    obj.setGeometry(250,250,500,500);
    obj.show();
    return a.exec();
}
