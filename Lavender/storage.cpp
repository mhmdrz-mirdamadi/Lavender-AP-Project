#include "storage.h"
#include "ui_storage.h"
#include "courtgame.h"
#include <QDebug>

Storage::Storage(QJsonObject _qjo, int _index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Storage),
    storage(_qjo),
    index(_index)
{
    ui->setupUi(this);

    if(storage.getDaysToFinishUpgrading() != 0)
    {
        ui->textEdit->setText("انبار در حال ارتقا است\n\n" + QString::number(storage.getDaysToFinishUpgrading()) + " روز باقی مانده است");
    }
    else
    {
        ui->man->setHidden(true);
        ui->coinReq->setHidden(true);
        ui->nailReq->setHidden(true);
        ui->shovelReq->setHidden(true);
        ui->textEdit->setHidden(true);
        ui->upPic1->setHidden(true);
        ui->upPic2->setHidden(true);
        ui->upPic3->setHidden(true);
    }
    ui->request->setHidden(true);

    ui->level->setText(QString::number(storage.getLevel()));
    ui->progressBar->setMaximum(storage.getMaxCapacity());
    ui->progressBar->setValue(storage.getUsedCapacity());
    ui->eggShow->setText(QString::number(storage.getEgg()));
    ui->milkShow->setText(QString::number(storage.getMilk().size()));
    ui->woolShow->setText(QString::number(storage.getWool()));
    ui->hayShow->setText(QString::number(storage.getHay()));
    ui->shovelShow->setText(QString::number(storage.getShovel()));
    ui->nailShow->setText(QString::number(storage.getNail()));
}

Storage::~Storage()
{
    delete ui;
}

void Storage::on_pushButton_clicked()
{
    ui->man->setHidden(false);
    if(storage.canUpgrade())
    {
        ui->coinReq->setText(QString::number(pow(storage.getLevel(), 3) * 10));
        ui->nailReq->setText(QString::number(storage.getLevel()));
        ui->shovelReq->setText(QString::number(storage.getLevel() - 1));

        ui->coinReq->setHidden(false);
        ui->nailReq->setHidden(false);
        ui->shovelReq->setHidden(false);
        ui->request->setHidden(false);
        ui->upPic1->setHidden(false);
        ui->upPic2->setHidden(false);
        ui->upPic3->setHidden(false);
    }
    else
    {
        ui->textEdit->setHidden(false);
    }
}

void Storage::on_request_accepted()
{
    storage.startUpgrading();

    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->request->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->upPic3->setHidden(true);
    ui->textEdit->setHidden(false);
    ui->textEdit->setText("انبار در حال ارتقا است\n\n" + QString::number(storage.getDaysToFinishUpgrading()) + " روز باقی مانده است");

    ui->shovelShow->setText(QString::number(storage.getShovel()));
    ui->nailShow->setText(QString::number(storage.getNail()));
    ui->progressBar->setValue(storage.getUsedCapacity());
}

void Storage::on_request_rejected()
{
    ui->man->setHidden(true);
    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->request->setHidden(true);
    ui->textEdit->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->upPic3->setHidden(true);
}


void Storage::on_continueKey_clicked()
{
    CourtGame* cgp = new CourtGame(storage.getQjo(), index);
    cgp->show();
    close();
}

