#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>
#include "myscene.h"
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    MyScene *scene;
    QActionGroup *pActionGroup;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTypeItem(QTableWidgetItem* itemType, MyScene::ShapeType st);
    void setXYItem(QTableWidgetItem* itemXY, QRectF rect);
    void setStyleItem(QTableWidgetItem* itemStyle, Qt::PenStyle penStyle);
    void setWidthItem(QTableWidgetItem* itemWidth,int penWidth);
    void setColorItem(QTableWidgetItem* itemColor, QColor color);

public slots:
    void slotAddItem(MyScene::ShapeType shapeType, QRectF rect,
                     QColor color,uint penWidth,Qt::PenStyle penStyle);

    void slotRotateScene();
    void slotScaleScene();
    void slotShearScene();
    void slotResetScene();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
