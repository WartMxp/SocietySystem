#include "Regist.h"
#include "ui_Regist.h"

Regist::Regist(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Regist)
{
    ui->setupUi(this);
}

Regist::~Regist()
{
    delete ui;
}
