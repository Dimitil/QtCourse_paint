#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QDebug>


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

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList titles;
    titles << "Figure Type" << "Geometry" << "PenStyle" << "PenWidth" << "Color";
    ui->tableWidget->setHorizontalHeaderLabels(titles);

    connect(scene, SIGNAL(signalNewShape(MyScene::ShapeType, QRectF,
                                         QColor, uint, Qt::PenStyle)),
            this, SLOT(slotAddItem(MyScene::ShapeType, QRectF,
                                        QColor, uint, Qt::PenStyle)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotAddItem(MyScene::ShapeType shapeType,
                             QRectF rect, QColor color, uint penWidth,
                             Qt::PenStyle penStyle)
{
    int curRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(curRow);

    QTableWidgetItem* itemType = new QTableWidgetItem;
    setTypeItem(itemType, shapeType);
    ui->tableWidget->setItem(curRow, 0, itemType);

    QTableWidgetItem* itemXY = new QTableWidgetItem;
    setXYItem(itemXY, rect);
    ui->tableWidget->setItem(curRow, 1, itemXY);

    QTableWidgetItem* itemStyle = new QTableWidgetItem;
    setStyleItem(itemStyle, penStyle);
    ui->tableWidget->setItem(curRow, 2, itemStyle);

    QTableWidgetItem* itemWidth = new QTableWidgetItem;
    setWidthItem(itemWidth, penWidth);
    ui->tableWidget->setItem(curRow, 3, itemWidth);

    QTableWidgetItem* itemColor = new QTableWidgetItem;
    setColorItem(itemColor, color);
    ui->tableWidget->setItem(curRow, 4, itemColor);

}

void MainWindow::setTypeItem(QTableWidgetItem* itemType, MyScene::ShapeType st) {
    if(st == MyScene::ShapeType::RECT) {
        itemType->setText("Rect");
    }
    else if(st == MyScene::ShapeType::ELIPS) {
        itemType->setText("Ellips");
    }
    else {
            itemType->setText("not definitely");
         }
}

void MainWindow::setXYItem(QTableWidgetItem* itemXY, QRectF rect) {
    QString Geometry = "(" + QString::number(rect.topLeft().x()) + ", " +
                             QString::number(rect.topLeft().y()) + ", " +
                             QString::number(rect.width()) + ", " +
                             QString::number(rect.height()) + ")";
    itemXY->setData(Qt::DisplayRole, Geometry);
}

void MainWindow::setStyleItem(QTableWidgetItem* itemStyle, Qt::PenStyle penStyle)
{

    QString style;
    switch (penStyle) {
    case Qt::PenStyle::SolidLine:
        style= "Solid";
        break;
    case Qt::PenStyle::DashLine:
        style= "DashLine";
        break;
    case Qt::PenStyle::DotLine:
        style= "DotLine";
        break;
    default:
        style = "not definitely";
    }
    itemStyle->setText(style);
}

void MainWindow::setWidthItem(QTableWidgetItem* itemWidth,int penWidth) {
    itemWidth->setData(Qt::DisplayRole, penWidth);
}

void MainWindow::setColorItem(QTableWidgetItem* itemColor, QColor color) {
    itemColor->setData(Qt::DisplayRole, color);
    itemColor->setData(Qt::DecorationRole, color);
}
