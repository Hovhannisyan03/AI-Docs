#include "texteditor.h"

textEditor::textEditor(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Text Editor");

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
    menu = menuBar()->addMenu("&File");

    open = new QAction("Open", this);
    connect(open, &QAction::triggered, this, &textEditor::openFile);

    save = new QAction("Save", this);
    connect(save, &QAction::triggered, this, &textEditor::saveFile);

    exit = new QAction("Exit", this);
    connect(exit, &QAction::triggered, this, &textEditor::exitFile);

    menu->addAction(open);
    menu->addAction(save);
    menu->addSeparator();
    menu->addAction(exit);
}

textEditor::~textEditor()
{
    delete textEdit;
    delete menu;
    delete open;
    delete save;
    delete exit;
}
void textEditor::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "C:\\");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            textEdit->setPlainText(in.readAll());
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not open file.");
        }
    }
}

void textEditor::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "C:\\");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not save file.");
        }
    }
}

void textEditor::exitFile()
{
    qApp->quit();
}
