#include "clock.h"

clockDig::clockDig(QWidget *parent) : QWidget(parent)
{
    resize(800, 600);
    QVBoxLayout *layout = new QVBoxLayout(this);

    lcd = new QLCDNumber(this);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->setDigitCount(8);
    layout->addWidget(lcd);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &clockDig::currentTime);
    timer->start(1000);
}

void clockDig::currentTime()
{
    QTime currentTime = QTime::currentTime();
    QString str = currentTime.toString("hh:mm:ss");
    lcd->display(str);
}
