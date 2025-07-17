#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class AddStudent;
}

class AddStudent : public QWidget {
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = nullptr);
    ~AddStudent();

private slots:
    void on_cancel_button_clicked();

    void on_save_button_clicked();

private:
    Ui::AddStudent *ui;
};

#endif // ADDSTUDENT_H
