#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QAbstractGraphicsShapeItem>
#include <QColorDialog>

#include "dialog.h"

class MyScene : public QGraphicsScene
{
public:
    enum class ShapeType{
        RECT,
        ELIPS
    };

private:

    Q_OBJECT
    QAbstractGraphicsShapeItem *m_current;
    bool   m_drawingInProcess;
    ShapeType type;
    QPointF m_startPoint;
    QColor ramColor;
    QColor ramBrushColor;
    int ramWidth;
    Qt::PenStyle ramStyle;

public:


    explicit MyScene(QObject *parent = nullptr);

public slots:

    void slotSetRect() {
        type = ShapeType::RECT;
    }

    void slotSetElips() {
        type = ShapeType::ELIPS;
    }

    void slotCallDialog() {
        Dialog dlg(ramBrushColor, ramWidth, ramStyle);
        if (dlg.exec() == QDialog::Accepted) {
            setColor(dlg.getColor());
            setRamWidth(dlg.getWidth());
            setRamStyle(dlg.getStyle());
        }
    }

    void setRamWidth(uint w) {
        ramWidth = w;
    }

    void setColor(QColor clr) {
        ramBrushColor = clr;
    }

    void setColor() {
        QColor newColor = QColorDialog::getColor();
        if (newColor.isValid()) {
            ramBrushColor = newColor;
        }
    }

    void setRamStyle(Qt::PenStyle ps) {
        ramStyle = ps;
    }

signals:
    void signalNewShape(MyScene::ShapeType, QRectF, QColor, uint, Qt::PenStyle);
    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


};

#endif // MYSCENE_H
