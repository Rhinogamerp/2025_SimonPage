#include "mainwindow.h"
#include <QMessageBox>
#include <QStatusBar>
#include <QPushButton>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::released,
            this, &MainWindow::handleButton);

    connect(ui->pushButton_2, &QPushButton::released,
            this, &MainWindow::handleButton2);

    connect(this, &MainWindow::statusUpdateMessage,
            ui->statusbar, &QStatusBar::showMessage);
}

void MainWindow::handleButton()
{
    emit statusUpdateMessage("Button 1 clicked", 0);
}

void MainWindow::handleButton2()
{
    emit statusUpdateMessage("Button 2 clicked", 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
