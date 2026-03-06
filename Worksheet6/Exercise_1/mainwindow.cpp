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

    // Create / allocate the model list
    this->partList = new ModelPartList("Parts List");

    // Link it to the tree view in the GUI
    ui->treeView->setModel(this->partList);

    // Get root item
    ModelPart *rootItem = this->partList->getRootItem();

    // Add 3 top level items
    for (int i = 0; i < 3; i++) {
        QString name = QString("TopLevel %1").arg(i);
        QString visible("true");

        ModelPart *childItem = new ModelPart({name, visible});
        rootItem->appendChild(childItem);

        // Add 5 sub-items
        for (int j = 0; j < 5; j++) {
            QString childName = QString("Item %1,%2").arg(i).arg(j);
            QString childVisible("true");

            ModelPart *childChildItem = new ModelPart({childName, childVisible});
            childItem->appendChild(childChildItem);
        }
    }
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
