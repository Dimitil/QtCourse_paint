#ifndef PATTERN_H
#define PATTERN_H

#include <QWidget>
#include <QPen>

class Pattern : public QWidget
{
    Q_OBJECT
    QPen m_pen;
public:
    explicit Pattern(QWidget *parent = nullptr);


public slots:
    void slotChangePen(QPen newPen) {
        m_pen = newPen;
        repaint();
    }

signals:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // PATTERN_H
