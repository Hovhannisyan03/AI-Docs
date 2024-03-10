#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), result(0.0)
{
    QWidget *window = new QWidget(this);
    setCentralWidget(window);
    QVBoxLayout *vLayout = new QVBoxLayout(window);
    display = new QLineEdit();
    display->setReadOnly(Qt::AlignRight);
    display->setMinimumHeight(50);
    vLayout->addWidget(display);

    QGridLayout *gridLayout = new QGridLayout();
    vLayout->addLayout(gridLayout);

    QStringList buttons
    {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "C", "0", "=", "+",
    };
    int position = 0;

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            QPushButton *button = new QPushButton(buttons[position]);
            gridLayout->addWidget(button, i, j);
            ++position;
            if(button->text() == "C")
            {
                button->setStyleSheet("background-color: red; color: white");
                connect(button, &QPushButton::clicked, this, &MainWindow::ClearLine);
            }
            else if(button->text() == "=")
            {
                button->setStyleSheet("background-color: green; color: white");
                connect(button, &QPushButton::clicked, this, &MainWindow::equalClicked);
            }
            else if(button->text() == "+" || button->text() == "-" || button->text() == "*" ||button->text() == "/")
            {
                button->setStyleSheet("background-color: orange; color: white");
                connect(button, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
            }
            else
            {
                button->setStyleSheet("background-color: black; color: white");
                connect(button, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
            }
        }
    }
    setFixedSize(300,400);
}

void MainWindow::onNumberClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    currentInput += button->text();
    display->setText(display->text() + button->text());
}

void MainWindow::onOperatorClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    currentOperator = button->text();
    result = currentInput.toDouble();
    currentInput.clear();
    display->setText(display->text() + button->text());
}
void MainWindow::equalClicked()
{
    double secondOperator = currentInput.toDouble();
    if(currentOperator == "+")
    {
        result += secondOperator;
    }
    else if(currentOperator == "-")
    {
        result -= secondOperator;
    }
    else if(currentOperator == "*")
    {
        result *= secondOperator;
    }
    else
    {
        result /= secondOperator;
    }

    display->setText(QString::number(result));
    currentInput = QString::number(result);
}
void MainWindow::ClearLine()
{
    currentInput.clear();
    currentOperator.clear();
    result = 0;
    display->clear();
}
MainWindow::~MainWindow()
{
    delete ui;
}
