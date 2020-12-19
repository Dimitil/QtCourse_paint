#include "myscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QPen>

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent),
    m_drawingInProcess(false), type(MyScene::ShapeType::RECT),
    m_startPoint(0,0), ramColor(Qt::blue), ramBrushColor(Qt::red),
    ramWidth(3), ramStyle(Qt::SolidLine)
{
    setSceneRect(0, 0, 500, 500);
}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::MouseButton::RightButton) {
        m_startPoint = event->scenePos();
        if (type == ShapeType::RECT) {
            m_current = new QGraphicsRectItem(m_startPoint.x(),
                                              m_startPoint.y(), 0, 0);
        }
        else if (type == ShapeType::ELIPS) {
            m_current = new QGraphicsEllipseItem(m_startPoint.x(),
                                                 m_startPoint.y(), 0, 0);
        }
        QPen pen;
        pen.setColor(ramColor);
        pen.setStyle(ramStyle);
        pen.setWidth(ramWidth);
        pen.setBrush(ramBrushColor);
        m_current->setPen(pen);

        m_current->setFlags(QGraphicsItem::ItemIsMovable |
                            QGraphicsItem::ItemIsSelectable);
        addItem(m_current);
        m_drawingInProcess = true;
    }
    QGraphicsScene::mousePressEvent(event);
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_drawingInProcess) {
        QPointF curPos = event->scenePos();
        QRectF rect(m_startPoint, curPos);
        if(type == ShapeType::RECT) {
            QGraphicsRectItem* tmp = qgraphicsitem_cast<QGraphicsRectItem*>(m_current);
            tmp -> setRect(rect.normalized());
        }
        else if(type == ShapeType::ELIPS) {
            QGraphicsEllipseItem ellips(QRectF(m_startPoint, curPos));
            QGraphicsEllipseItem* tmp = qgraphicsitem_cast<QGraphicsEllipseItem*>(m_current);
            tmp -> setRect(rect.normalized());
        }
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::MouseButton::RightButton)
    {
        m_drawingInProcess = false;
        m_current = nullptr;
    }
    QGraphicsScene::mouseReleaseEvent(event);
}
