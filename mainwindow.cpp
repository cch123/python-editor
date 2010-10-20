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
    this->enableSlotsManagement();
    //initialize the highlighter
    this->highlighter = new Highlighter(ui->textEdit->document());
    this->setWindowModified(false);
    this->setCurrentFile("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableSlotsManagement(){
    connect(ui->textEdit->document(),SIGNAL(modificationChanged(bool)),this,SLOT(setWindowModified(bool)));
}

void MainWindow::setCurrentFile(QString filename){
    QString resultName = "Untitled Document";
    if(!filename.isEmpty()){
        resultName = filename;
    }
    this->setWindowTitle(tr("%1[*] - Current File").arg(resultName));
    this->setWindowModified(false);
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
    QString filename = QFileDialog::getOpenFileName(this,tr("open file"),"c:/",tr("All Files(*.*)"));
//    QMessageBox* mebox = new QMessageBox();
//    mebox->setText(filename);
//    mebox->show();
    if(!filename.isEmpty()){
        QFile file(filename);
        if(file.open(QFile::ReadOnly|QFile::Text)){
            ui->textEdit->setPlainText(file.readAll());
        }
    }
}
