#ifndef ADDSOCIETY_H
#define ADDSOCIETY_H

#include <QWidget>
#include "Struct.h"
#include "SocietiesSql.h"
namespace Ui {
class AddSociety;
}

class AddSociety : public QWidget
{
    Q_OBJECT

public:
    explicit AddSociety(QWidget *parent = nullptr);
    ~AddSociety();

private slots:
    void on_cancel_button_clicked();

    void on_save_button_clicked();

private:
    Ui::AddSociety *ui;
};

#endif // ADDSOCIETY_H
