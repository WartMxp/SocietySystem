/********************************************************************************
** Form generated from reading UI file 'Regist.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIST_H
#define UI_REGIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Regist
{
public:

    void setupUi(QWidget *Regist)
    {
        if (Regist->objectName().isEmpty())
            Regist->setObjectName("Regist");
        Regist->resize(400, 300);

        retranslateUi(Regist);

        QMetaObject::connectSlotsByName(Regist);
    } // setupUi

    void retranslateUi(QWidget *Regist)
    {
        Regist->setWindowTitle(QCoreApplication::translate("Regist", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Regist: public Ui_Regist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIST_H
