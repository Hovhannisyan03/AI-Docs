#include <QApplication>
#include "clock.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    clockDig obj(nullptr);
    obj.show();
    return a.exec();
}
