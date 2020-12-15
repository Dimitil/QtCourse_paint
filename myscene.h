#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QAbstractGraphicsShapeItem>
#include <QColorDialog>

class MyScene : public QGraphicsScene
{
    enum class ShapeType{
        RECT,
        ELIPS
    };

    Q_OBJECT
    QAbstractGraphicsShapeItem *m_current;
    bool   m_drawingInProcess;
    ShapeType type;
    QPointF m_startPoint;
    QColor ramColor;
    QColor ramBrushColor;
    uint ramWidth;
    Qt::PenStyle ramStyle;


public:
    explicit MyScene(QObject *parent = nullptr);

public slots:
    void setColor() {
        QColor newColor = QColorDialog::getColor();
        if (newColor.isValid()) {
            ramBrushColor = newColor;
        }
    }

signals:


    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYSCENE_H
