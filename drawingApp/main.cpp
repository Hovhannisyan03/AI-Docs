#include "mainwindow.h"
#include "drawing.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *ptr = nullptr;
    DrawingWidget obj(ptr);
    obj.show();
    return app.exec();
}
