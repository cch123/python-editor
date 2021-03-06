#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "highlighter.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Highlighter * highlighter;

    void enableSlotsManagement();
    void setCurrentFile(QString filename);
private slots:
    void on_actionOpen_triggered();
    void on_actionAbout_triggered();

};

#endif // MAINWINDOW_H
