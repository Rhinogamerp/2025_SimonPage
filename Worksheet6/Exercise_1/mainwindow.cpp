#include "mainwindow.h"
#include <QMessageBox>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::handleButton1()
{
    QMessageBox msgBox;
    msgBox.setText("Button 1 clicked");
    msgBox.exec();
}

void MainWindow::handleButton2()
{
    QMessageBox msgBox;
    msgBox.setText("Button 2 clicked");
    msgBox.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
