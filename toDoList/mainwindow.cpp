#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) , ui(new Ui::MainWindow)
{
    QLineEdit *line = nullptr;
    QListWidget *list = nullptr;
    QPushButton *add = nullptr;
    QPushButton *remove = nullptr;
    info();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete line;
    delete list;
    delete add;
    delete remove;
}

void MainWindow::remove_line()
{
    int count = 0;
    QList<QListWidgetItem*> items = list->selectedItems();
    foreach(QListWidgetItem* item, items)
    {
        delete list->takeItem(list->row(item));
        ++count;
    }

    if(!count)
    {
        QMessageBox::critical(this, "Error", "Select item");
    }
}

void MainWindow::add_line()
{
    bool lock;
    QString input = line->text().trimmed();
    if(input.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Line is empty");
        line->clear();
    }
    else
    {
        list->addItem(input);
        line->clear();
    }
}

void MainWindow::info()
{
    QWidget *window = new QWidget(this);
    setCentralWidget(window);

    QVBoxLayout *layout = new QVBoxLayout(window);
    QFormLayout *formLayout = new QFormLayout;

    line = new QLineEdit;
    list = new QListWidget;
    add = new QPushButton("Add");
    add->setStyleSheet("background-color: green; color: white");
    remove = new QPushButton("Remove");
    remove->setStyleSheet("background-color: red; color: white");

    formLayout->addRow(line);

    layout->addLayout(formLayout);
    layout->addWidget(list);
    layout->addWidget(add);
    layout->addWidget(remove);

    connect(add,&QPushButton::clicked, this, &MainWindow::add_line);
    connect(remove,&QPushButton::clicked, this, &MainWindow::remove_line);
}
