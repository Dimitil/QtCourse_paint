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

    pActionGroup = new QActionGroup(this);
    pActionGroup ->addAction(ui->actionRect);
    pActionGroup ->addAction(ui->actionElips);
    ui->actionRect->setChecked(true);

    connect(ui->actionColor, SIGNAL(triggered()),
            scene, SLOT(setColor()));
    connect(ui->actionOptions, SIGNAL(triggered()),
            scene, SLOT(slotCallDialog()));
    connect(ui->actionRect, SIGNAL(triggered()),
            scene, SLOT(slotSetRect()));
    connect(ui->actionElips, SIGNAL(triggered()),
            scene, SLOT(slotSetElips()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

