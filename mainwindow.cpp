#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new MyScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView_2->setScene(scene);
    connect(ui->actionColor, SIGNAL(triggered()),
            scene, SLOT(setColor()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

