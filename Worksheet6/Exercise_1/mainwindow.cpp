#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "optiondialog.h"
#include <QFileDialog>
#include <QPushButton>
#include <QStatusBar>
#include <QTreeView>
#include <QModelIndex>
#include <QIcon>
#include <QSize>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , partList(nullptr)
{
    ui->setupUi(this);

    ui->actionOpen_File->setIcon(QIcon(":/Icons/fileopen.png"));
    ui->toolBar->clear();
    ui->toolBar->setIconSize(QSize(24, 24));
    ui->toolBar->addAction(ui->actionOpen_File);
    ui->toolBar->show();

    connect(ui->pushButton, &QPushButton::released,
            this, &MainWindow::handleButton);

    connect(ui->pushButton_2, &QPushButton::released,
            this, &MainWindow::handleButton2);

    connect(this, &MainWindow::statusUpdateMessage,
            ui->statusbar, &QStatusBar::showMessage);

    connect(ui->treeView, &QTreeView::clicked,
            this, &MainWindow::handleTreeClicked);

    partList = new ModelPartList("Parts List");
    ui->treeView->setModel(partList);

    ModelPart *rootItem = partList->getRootItem();

    for (int i = 0; i < 3; i++) {
        QString name = QString("TopLevel %1").arg(i);
        QString visible = "true";

        ModelPart *childItem = new ModelPart({name, visible});
        rootItem->appendChild(childItem);

        for (int j = 0; j < 5; j++) {
            QString childName = QString("Item %1,%2").arg(i).arg(j);
            QString childVisible = "true";

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
    OptionDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        emit statusUpdateMessage("Dialog accepted", 0);
    } else {
        emit statusUpdateMessage("Dialog rejected", 0);
    }
}

void MainWindow::on_actionOpen_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "C:\\",
        tr("STL Files (*.stl);;Text Files (*.txt)")
        );

    if (!fileName.isEmpty()) {
        emit statusUpdateMessage(QString("Selected file: ") + fileName, 0);
    }
}

void MainWindow::handleTreeClicked()
{
    QModelIndex index = ui->treeView->currentIndex();

    if (!index.isValid()) {
        return;
    }

    ModelPart *selectedPart = static_cast<ModelPart*>(index.internalPointer());

    if (!selectedPart) {
        return;
    }

    QString text = selectedPart->data(0).toString();
    emit statusUpdateMessage(QString("The selected item is: ") + text, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
