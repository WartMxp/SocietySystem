#ifndef ADDACTIVITY_H
#define ADDACTIVITY_H

#include <QWidget>

namespace Ui {
class AddActivity;
}

class AddActivity : public QWidget
{
    Q_OBJECT

public:
    explicit AddActivity(QWidget *parent = nullptr);
    ~AddActivity();

private:
    Ui::AddActivity *ui;
};

#endif // ADDACTIVITY_H
