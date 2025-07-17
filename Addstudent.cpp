#include "Addstudent.h"
#include "ui_Addstudent.h"
#include "SocietiesSql.h"
#include "Struct.h"

AddStudent::AddStudent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddStudent) {
    ui->setupUi(this);
}

AddStudent::~AddStudent() {
    delete ui;
}

void AddStudent::on_cancel_button_clicked() {
    this->hide();
}


void AddStudent::on_save_button_clicked() {

    stuInfo info;
    info.name = ui->le_username->text();
    info.email = ui->le_email->text();
    info.description = ui->le_description->text();
    info.password = ui->le_password->text();
    auto ptr = SocietiesSql::get_instance();
    ptr->addStudent(info);
    QMessageBox::information(nullptr, "信息", "存储成功");
}

