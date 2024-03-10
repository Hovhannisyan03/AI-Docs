#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNumberClicked();
    void ClearLine();
    void equalClicked();
    void onOperatorClicked();
private:
    Ui::MainWindow *ui;
    QLineEdit *display;
    QString currentInput;
    QString currentOperator;
    QString buffer;
    double result;
};
#endif
