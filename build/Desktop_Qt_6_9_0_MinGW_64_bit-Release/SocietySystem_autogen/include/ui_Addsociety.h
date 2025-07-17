/********************************************************************************
** Form generated from reading UI file 'Addsociety.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSOCIETY_H
#define UI_ADDSOCIETY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddSociety
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *le_name;
    QLabel *label_4;
    QLineEdit *le_keader;
    QLabel *label_2;
    QLineEdit *le_type;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *le_description;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *save_button;
    QPushButton *cancel_button;

    void setupUi(QWidget *AddSociety)
    {
        if (AddSociety->objectName().isEmpty())
            AddSociety->setObjectName("AddSociety");
        AddSociety->resize(400, 300);
        gridLayoutWidget_2 = new QWidget(AddSociety);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(60, 40, 281, 161));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        le_name = new QLineEdit(gridLayoutWidget_2);
        le_name->setObjectName("le_name");

        gridLayout_2->addWidget(le_name, 0, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        le_keader = new QLineEdit(gridLayoutWidget_2);
        le_keader->setObjectName("le_keader");

        gridLayout_2->addWidget(le_keader, 3, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        le_type = new QLineEdit(gridLayoutWidget_2);
        le_type->setObjectName("le_type");

        gridLayout_2->addWidget(le_type, 1, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        le_description = new QLineEdit(gridLayoutWidget_2);
        le_description->setObjectName("le_description");

        gridLayout_2->addWidget(le_description, 2, 1, 1, 1);

        gridLayoutWidget = new QWidget(AddSociety);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(60, 200, 281, 51));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        save_button = new QPushButton(gridLayoutWidget);
        save_button->setObjectName("save_button");

        gridLayout->addWidget(save_button, 0, 0, 1, 1);

        cancel_button = new QPushButton(gridLayoutWidget);
        cancel_button->setObjectName("cancel_button");

        gridLayout->addWidget(cancel_button, 0, 1, 1, 1);


        retranslateUi(AddSociety);

        QMetaObject::connectSlotsByName(AddSociety);
    } // setupUi

    void retranslateUi(QWidget *AddSociety)
    {
        AddSociety->setWindowTitle(QCoreApplication::translate("AddSociety", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("AddSociety", "\347\244\276\351\225\277", nullptr));
        label_2->setText(QCoreApplication::translate("AddSociety", "\347\261\273\345\210\253", nullptr));
        label_3->setText(QCoreApplication::translate("AddSociety", "\346\217\217\350\277\260", nullptr));
        label->setText(QCoreApplication::translate("AddSociety", "\345\220\215\347\247\260", nullptr));
        save_button->setText(QCoreApplication::translate("AddSociety", "\344\277\235\345\255\230", nullptr));
        cancel_button->setText(QCoreApplication::translate("AddSociety", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSociety: public Ui_AddSociety {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSOCIETY_H
