#ifndef VIWER_H
#define VIWER_H
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QAction>

class viewer : public QWidget
{
    Q_OBJECT
private slots:
    void open();
    void zoomIn();
    void zoomOut();
    void rotate();
public:
    explicit viewer(QWidget *parent);
    ~viewer()
    {
        delete label;
        delete _open;
        delete _zoomIn;
        delete _zoomOut;
        delete _rotate;

    }
private:
    QLabel *label;
    QPixmap pixmap;
    QAction *_open;
    QAction *_zoomIn;
    QAction *_zoomOut;
    QAction *_rotate;
    void connections();
    void createMenu();
};

#endif // VIWER_H
