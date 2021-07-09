#include "daynight.h"
#include "ui_daynight.h"
#include <QMovie>

DayNight::DayNight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DayNight)
{
    ui->setupUi(this);
    QMovie *m = new QMovie(":/nextDay/otherPic/dayNight.gif");
    ui->label->setMovie(m);
    m->start();
}

DayNight::~DayNight()
{
    delete ui;
}
