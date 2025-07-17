/********************************************************************************
** Form generated from reading UI file 'Addactivity.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDACTIVITY_H
#define UI_ADDACTIVITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddActivity
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QLineEdit *le_name_2;
    QLabel *label_5;
    QLineEdit *le_keader_2;
    QLabel *label_6;
    QLineEdit *le_type_2;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *le_description_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_4;
    QPushButton *save_button_2;
    QPushButton *cancel_button_2;

    void setupUi(QWidget *AddActivity)
    {
        if (AddActivity->objectName().isEmpty())
            AddActivity->setObjectName("AddActivity");
        AddActivity->resize(400, 300);
        gridLayoutWidget_2 = new QWidget(AddActivity);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(60, 40, 281, 161));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        le_name_2 = new QLineEdit(gridLayoutWidget_2);
        le_name_2->setObjectName("le_name_2");

        gridLayout_3->addWidget(le_name_2, 0, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName("label_5");

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        le_keader_2 = new QLineEdit(gridLayoutWidget_2);
        le_keader_2->setObjectName("le_keader_2");

        gridLayout_3->addWidget(le_keader_2, 3, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName("label_6");

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        le_type_2 = new QLineEdit(gridLayoutWidget_2);
        le_type_2->setObjectName("le_type_2");

        gridLayout_3->addWidget(le_type_2, 1, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName("label_7");

        gridLayout_3->addWidget(label_7, 2, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName("label_8");

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        le_description_2 = new QLineEdit(gridLayoutWidget_2);
        le_description_2->setObjectName("le_description_2");

        gridLayout_3->addWidget(le_description_2, 2, 1, 1, 1);

        gridLayoutWidget = new QWidget(AddActivity);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(60, 200, 281, 51));
        gridLayout_4 = new QGridLayout(gridLayoutWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        save_button_2 = new QPushButton(gridLayoutWidget);
        save_button_2->setObjectName("save_button_2");

        gridLayout_4->addWidget(save_button_2, 0, 0, 1, 1);

        cancel_button_2 = new QPushButton(gridLayoutWidget);
        cancel_button_2->setObjectName("cancel_button_2");

        gridLayout_4->addWidget(cancel_button_2, 0, 1, 1, 1);


        retranslateUi(AddActivity);

        QMetaObject::connectSlotsByName(AddActivity);
    } // setupUi

    void retranslateUi(QWidget *AddActivity)
    {
        AddActivity->setWindowTitle(QCoreApplication::translate("AddActivity", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("AddActivity", "\347\244\276\351\225\277", nullptr));
        label_6->setText(QCoreApplication::translate("AddActivity", "\347\261\273\345\210\253", nullptr));
        label_7->setText(QCoreApplication::translate("AddActivity", "\346\217\217\350\277\260", nullptr));
        label_8->setText(QCoreApplication::translate("AddActivity", "\345\220\215\347\247\260", nullptr));
        save_button_2->setText(QCoreApplication::translate("AddActivity", "\344\277\235\345\255\230", nullptr));
        cancel_button_2->setText(QCoreApplication::translate("AddActivity", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddActivity: public Ui_AddActivity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDACTIVITY_H
