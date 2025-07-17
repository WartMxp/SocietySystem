#include "Addsociety.h"
#include "ui_Addsociety.h"

AddSociety::AddSociety(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddSociety) {
    ui->setupUi(this);
}

AddSociety::~AddSociety() {
    delete ui;
}

void AddSociety::on_cancel_button_clicked() {
    this->hide();
}

void AddSociety::on_save_button_clicked() {
    socInfo info;
    info.name = ui->le_name->text();
    info.type = ui->le_type->text();
    info.description = ui->le_description->text();
    info.leader = ui->le_keader->text();
    auto ptr = SocietiesSql::get_instance();
    ptr->addSociety(info);
    QMessageBox::information(nullptr, "信息", "存储成功");

}

