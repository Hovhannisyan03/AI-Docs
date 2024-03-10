#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <vector>

class DrawingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingWidget(QWidget *parent = nullptr);

    enum ShapeType { Line, Rectangle };

    void setShape(ShapeType shape);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    std::vector<QRect> rectangles;
    std::vector<QLine> lines;
    QPoint startPoint;
    QPoint endPoint;
    ShapeType currentShape;
};

#endif
