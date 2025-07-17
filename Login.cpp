#include "Login.h"
#include "ui_Login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login) {
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_button_clicked()
{
    //待修改
    emit login_success();
    // exit(0);
    this->hide();
}


void Login::on_logout_button_clicked()
{
    exit(0);
}


void Login::on_regist_button_clicked() {
    //不准备做
}

