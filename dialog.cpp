#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QColor clr, int w, Qt::PenStyle ps, QWidget *parent) :
    QDialog(parent), ui(new Ui::Dialog)
{

    ui->setupUi(this);

    ui->comboBox->addItem("Solid", static_cast<int>(Qt::SolidLine));
    ui->comboBox->addItem("Dash", static_cast<int>(Qt::DashLine));
    ui->comboBox->addItem("Dot", static_cast<int>(Qt::DotLine));

    ui->spinBox->setValue(w);

    int r,g,b;
    clr.getRgb(&r, &g, &b);

    ui->redSlider->setValue(r);
    ui->greenSlider->setValue(g);
    ui->blueSlider->setValue(b);

    int curItem = ui->comboBox->findData(static_cast<int>(ps));
    ui->comboBox->setCurrentIndex(curItem);

    QPen p;
    p.setColor(clr);
    p.setStyle(ps);
    p.setWidth(w);
    ui->pattern->slotChangePen(p);


    connect(ui->spinBox, SIGNAL(valueChanged(int)),
            this, SLOT(slotSomeBodyChanged()));

    connect(ui->redSlider, SIGNAL(valueChanged(int)),
            this, SLOT(slotSomeBodyChanged()));
    connect(ui->greenSlider, SIGNAL(valueChanged(int)),
            this, SLOT(slotSomeBodyChanged()));
    connect(ui->blueSlider, SIGNAL(valueChanged(int)),
            this, SLOT(slotSomeBodyChanged()));

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(slotSomeBodyChanged()));
    connect(this, SIGNAL(signalChangePattern(QPen)),
            ui->pattern, SLOT(slotChangePen(QPen)));

    setModal(true);


    show();

}

Dialog::~Dialog()
{
    delete ui;
}

QColor Dialog::getColor() const
{
    int r = ui->redSlider->value();
    int g = ui->greenSlider->value();
    int b = ui->blueSlider->value();
    return QColor(r, g, b);
}

int Dialog::getWidth() const
{
    return ui->spinBox->value();
}

Qt::PenStyle Dialog::getStyle() const
{
    Qt::PenStyle ps = static_cast<Qt::PenStyle>(ui->comboBox->currentData().toInt());
    return ps;
}
