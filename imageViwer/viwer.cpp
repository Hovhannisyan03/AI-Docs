#include "viwer.h"
#include <QTransform>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMenu>
#include <QMainWindow>

viewer::viewer(QWidget *parent) : QWidget(parent)
{
    label = new QLabel(this);
    label->setScaledContents(true);

    connections();
    createMenu();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);
}

void viewer::open()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!imagePath.isEmpty())
    {
        QPixmap p(imagePath);
        pixmap = p;
        label->setPixmap(p);
    }
}

void viewer::zoomIn()
{
    if (!label->pixmap())
    {
        return;
    }
    QPixmap p = pixmap.scaled(label->pixmap().size() * 1.2, Qt::KeepAspectRatio);
    label->setPixmap(p);
}

void viewer::zoomOut()
{
    if (!label->pixmap())
    {
        return;
    }
    QPixmap p = pixmap.scaled(label->pixmap().size() * 0.8, Qt::KeepAspectRatio);
    label->setPixmap(p);
}

void viewer::rotate()
{
    if (!label->pixmap())
    {
        return;
    }

    QPixmap p = pixmap.transformed(QTransform().rotate(90));
    label->setPixmap(p);
    pixmap = p;
}

void viewer::createMenu()
{
    QMenuBar *menuBar;
    _open = new QAction("&Open", this);
    _zoomIn = new QAction("Zoom &In", this);
    _zoomOut = new QAction("Zoom &Out", this);
    _rotate = new QAction("&Rotate", this);

    QMenu *fmenu = new QMenu("&File", this);
    fmenu->addAction(_open);

    QMenu *viewMenu = new QMenu("&View", this);
    viewMenu->addAction(_zoomIn);
    viewMenu->addAction(_zoomOut);
    viewMenu->addAction(_rotate);

    menuBar->addMenu(fmenu);
    menuBar->addMenu(viewMenu);
}
void viewer::connections()
{
    connect(_open, &QAction::triggered, this, &viewer::open);

    connect(_zoomIn, &QAction::triggered, this, &viewer::zoomIn);

    connect(_zoomOut, &QAction::triggered, this, &viewer::zoomOut);

    connect(_rotate, &QAction::triggered, this, &viewer::rotate);
}
