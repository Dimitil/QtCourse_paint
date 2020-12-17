#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPen>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

    Ui::Dialog *ui;


public:
    explicit Dialog(QColor clr, int w, Qt::PenStyle ps, QWidget *parent = nullptr);
    ~Dialog();

    QColor getColor() const;

    int getWidth() const;

    Qt::PenStyle getStyle() const;

signals:
    void signalChangePattern(QPen);

public slots:

    void slotSomeBodyChanged(){
       QColor clr = getColor();
       int width = getWidth();
       Qt::PenStyle ps = getStyle();

       QPen p;
       p.setColor(clr);
       p.setWidth(width);
       p.setStyle(ps);

       signalChangePattern(p);
    }

};

#endif // DIALOG_H
