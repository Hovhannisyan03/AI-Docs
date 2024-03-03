#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include <QMenuBar>
class textEditor : public QMainWindow
{
    Q_OBJECT
public:
    textEditor(QWidget *parent);
    ~textEditor();
private slots:
    void openFile();
    void saveFile();
    void exitFile();
private:
    QTextEdit *textEdit;
    QMenu *menu;
    QAction *open;
    QAction *save;
    QAction *exit;
};

#endif // TEXTEDITOR_H
