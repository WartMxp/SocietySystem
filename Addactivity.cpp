#include "Addactivity.h"
#include "ui_Addactivity.h"

AddActivity::AddActivity(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddActivity)
{
    ui->setupUi(this);
}

AddActivity::~AddActivity()
{
    delete ui;
}
