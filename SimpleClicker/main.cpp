#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QObject>

class SimpleClicker : public QObject
{
public:
    SimpleClicker() : clickerWindow{nullptr}, layout{nullptr}, button{nullptr}, label{nullptr}, count{0}{ }
    void showClicker();
    void addCount();
private:
    QWidget *clickerWindow;
    QVBoxLayout *layout;
    QPushButton *button;
    QLabel *label;
    int count;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleClicker obj;
    obj.showClicker();
    return a.exec();
}

void SimpleClicker::showClicker()
{
    clickerWindow = new QWidget();
    clickerWindow->setGeometry(200,200,400,400);
    clickerWindow->setWindowTitle("Simple Click Counter");

    layout = new QVBoxLayout(clickerWindow);
    button = new QPushButton("Click");

    label = new QLabel();
    label->setNum(0);
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(button);
    layout->addWidget(label);

    QObject::connect(button,&QPushButton::clicked, this, &SimpleClicker::addCount);
    clickerWindow->show();

}

void SimpleClicker::addCount()
{
    ++count;
    label->setNum(count);
}
