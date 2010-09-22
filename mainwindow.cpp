#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    //显示关于对话框
    QString aboutText = "<html><head></head><body>Alex has come.</body></html>";
    QMessageBox box;
    box.setWindowTitle("About");
    box.setIcon(QMessageBox::Question);
    box.setText(aboutText);
    box.setStandardButtons(QMessageBox::Yes);
    box.exec();

}
