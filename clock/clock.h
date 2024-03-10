#ifndef CLOCK_H
#define CLOCK_H
#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QVBoxLayout>

class clockDig : public QWidget
{
    Q_OBJECT
public:
    explicit clockDig(QWidget *parent);
    ~clockDig()
    {
        delete lcd;
    }
private slots:
    void currentTime();
private:
    QLCDNumber *lcd;
};

#endif
