// drawingwidget.cpp
#include "drawing.h"
#include <QPushButton>
DrawingWidget::DrawingWidget(QWidget *parent) : QWidget(parent)
{
    resize(800, 600);

    currentShape = Line;
    QPushButton *lineButton = new QPushButton("Line", this);
    lineButton->setGeometry(10, 10, 80, 30);

    QPushButton *rectButton = new QPushButton("Rectangle", this);
    rectButton->setGeometry(100, 10, 80, 30);

    connect(lineButton, &QPushButton::clicked, this, [=]() {setShape(Line);});
    connect(rectButton, &QPushButton::clicked, this, [=]() {setShape(Rectangle);});
    setMouseTracking(true);
}

void DrawingWidget::setShape(ShapeType shape)
{
    currentShape = shape;
}

void DrawingWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    for (const auto &rect : rectangles)
        painter.drawRect(rect);

    for (const auto &line : lines)
        painter.drawLine(line);
}

void DrawingWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        startPoint = event->pos();
    }
}

void DrawingWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        endPoint = event->pos();
        update();
    }
}

void DrawingWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        endPoint = event->pos();

        if (currentShape == Rectangle)
        {
            QRect rect(startPoint, endPoint);
            rectangles.push_back(rect);
        }
        else if (currentShape == Line)
        {
            QLine line(startPoint, endPoint);
            lines.push_back(line);
        }

        update();
    }
}
