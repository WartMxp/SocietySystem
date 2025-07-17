/********************************************************************************
** Form generated from reading UI file 'Addstudent.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENT_H
#define UI_ADDSTUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddStudent
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *save_button;
    QPushButton *cancel_button;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QTextEdit *textEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label;

    void setupUi(QWidget *AddStudent)
    {
        if (AddStudent->objectName().isEmpty())
            AddStudent->setObjectName("AddStudent");
        AddStudent->resize(400, 300);
        gridLayoutWidget = new QWidget(AddStudent);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(50, 200, 281, 51));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        save_button = new QPushButton(gridLayoutWidget);
        save_button->setObjectName("save_button");

        gridLayout->addWidget(save_button, 0, 0, 1, 1);

        cancel_button = new QPushButton(gridLayoutWidget);
        cancel_button->setObjectName("cancel_button");

        gridLayout->addWidget(cancel_button, 0, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(AddStudent);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(50, 40, 281, 161));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(gridLayoutWidget_2);
        lineEdit->setObjectName("lineEdit");

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout_2->addWidget(lineEdit_3, 3, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        textEdit = new QTextEdit(gridLayoutWidget_2);
        textEdit->setObjectName("textEdit");

        gridLayout_2->addWidget(textEdit, 2, 1, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout_2->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        retranslateUi(AddStudent);

        QMetaObject::connectSlotsByName(AddStudent);
    } // setupUi

    void retranslateUi(QWidget *AddStudent)
    {
        AddStudent->setWindowTitle(QCoreApplication::translate("AddStudent", "Form", nullptr));
        save_button->setText(QCoreApplication::translate("AddStudent", "\344\277\235\345\255\230", nullptr));
        cancel_button->setText(QCoreApplication::translate("AddStudent", "\345\217\226\346\266\210", nullptr));
        label_4->setText(QCoreApplication::translate("AddStudent", "\345\257\206\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("AddStudent", "\351\202\256\347\256\261", nullptr));
        label_3->setText(QCoreApplication::translate("AddStudent", "\344\270\252\344\272\272\347\256\200\344\273\213", nullptr));
        label->setText(QCoreApplication::translate("AddStudent", "\347\224\250\346\210\267\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStudent: public Ui_AddStudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENT_H
