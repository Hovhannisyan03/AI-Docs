#ifndef DRAWING_H
#define DRAWING_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>

class DrawingCanvas : public QWidget {
    Q_OBJECT
public:
    enum class Tool { Line, Rectangle };
    Tool currentTool;

public:
    DrawingCanvas(QWidget *parent);
private slots:
    //void paintEvent(QPaintEvent *event);
    void paintLine();
    void paintRectangle();
private:
    QPoint startPoint;
    QPoint endPoint;
    QVector<QRect> rectangles;
    QVector<QLine> lines;

    void mousePressEvent(QMouseEvent *event) override{
        startPoint = event->pos();
    }

    void mouseMoveEvent(QMouseEvent *event) override{
        endPoint = event->pos();
        update();
    }

    void mouseReleaseEvent(QMouseEvent *event) override{
        endPoint = event->pos();
        if (currentTool == Tool::Rectangle) {
            QRect rect(startPoint, endPoint);
            rectangles.append(rect.normalized());
        }
        else if (currentTool == Tool::Line) {
            QLine line(startPoint, endPoint);
            lines.append(line);
        }
        update();
    }
};

#endif // DRAWING_H
