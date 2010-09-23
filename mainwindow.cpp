#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //made the editor area central
    this->setCentralWidget(ui->textEdit);
    //initialize the highlighter
    this->highlighter = new Highlighter(ui->textEdit->document());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    //show about dialog
    QString aboutText = "<html><head></head><body>Alex has come.</body></html>";
    QMessageBox box;
    box.setWindowTitle("About");
    box.setIcon(QMessageBox::Question);
    box.setText(aboutText);
    box.setStandardButtons(QMessageBox::Yes);
    box.exec();

}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("open file"),"c:/",tr("所有文件(*.*)"));
    QMessageBox* mebox = new QMessageBox();
    mebox->setText(filename);
    mebox->show();
}
