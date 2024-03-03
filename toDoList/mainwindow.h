#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QString>
#include <QMessageBox>

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
    void remove_line();
    void add_line();
private:
    Ui::MainWindow *ui;
    QLineEdit *line;
    QListWidget *list;
    QPushButton *add;
    QPushButton *remove;
    void info();
};
#endif // MAINWINDOW_H
