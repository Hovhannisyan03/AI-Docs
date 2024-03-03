#include "drawing.h"


DrawingCanvas::DrawingCanvas(QWidget *parent) : QWidget(parent), currentTool(Tool::Line)
{
    resize(800, 600);

    QPushButton *lineButton = new QPushButton("Line", this);
    lineButton->setGeometry(10, 10, 80, 30);

    QPushButton *rectButton = new QPushButton("Rectangle", this);
    rectButton->setGeometry(100, 10, 80, 30);

    connect(lineButton, &QPushButton::clicked, this, DrawingCanvas::paintLine);
    connect(rectButton, &QPushButton::clicked, this, DrawingCanvas::paintRectangle);
}

void DrawingCanvas::paintLine()
{
    currentTool = Tool::Line;

    QPainter *painter = new QPainter(this);
    painter->setPen(Qt::black);

    for (const auto &line : lines)
    {
        painter->drawLine(line);
    }

    painter->drawLine(startPoint, endPoint);

}

void DrawingCanvas::paintRectangle()
{
    currentTool = Tool::Rectangle;

    QPainter *painter = new QPainter(this);
    painter->setPen(Qt::black);

    for (const auto &rect : rectangles)
    {
        painter->drawRect(rect);
    }

    QRect currentRect(startPoint, endPoint);
    painter->drawRect(currentRect.normalized());
}



