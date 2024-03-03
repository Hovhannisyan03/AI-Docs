#include "mainwindow.h"
// #include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    info();
}

MainWindow::~MainWindow()
{
    delete line1;
    delete line2;
    delete button;
}

void MainWindow::emptyCheck()
{

    QString input1 = line1->text();
    QString input2 = line2->text();

    if (input1.isEmpty() || input2.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Failed");
    }
    else
    {
        QMessageBox::information(this, "Success", "Successed");
    }
}

void MainWindow::info()
{
    QWidget *window = new QWidget(this);
    setCentralWidget(window);

    QVBoxLayout *layout = new QVBoxLayout(window);
    QFormLayout *formLayout = new QFormLayout;

    line1 = new QLineEdit;
    line2 = new QLineEdit;
    button = new QPushButton("Submit");

    formLayout->addRow("Line 1:", line1);
    formLayout->addRow("Line 2:", line2);

    layout->addLayout(formLayout);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &MainWindow::emptyCheck);
}

