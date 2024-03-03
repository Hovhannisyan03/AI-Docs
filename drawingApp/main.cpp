#include "mainwindow.h"
#include "drawing.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *ptr = nullptr;
    DrawingCanvas obj(ptr);
    obj.show();
    return app.exec();
}
