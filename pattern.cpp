#include "pattern.h"
#include <QPainter>

Pattern::Pattern(QWidget *parent) : QWidget(parent)
{


}

void Pattern::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(m_pen);
    painter.drawLine(rect().topLeft(), rect().bottomRight());
}
