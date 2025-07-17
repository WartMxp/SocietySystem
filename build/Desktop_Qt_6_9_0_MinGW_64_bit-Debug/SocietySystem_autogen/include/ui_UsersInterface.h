/********************************************************************************
** Form generated from reading UI file 'UsersInterface.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSINTERFACE_H
#define UI_USERSINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsersInterface
{
public:

    void setupUi(QWidget *UsersInterface)
    {
        if (UsersInterface->objectName().isEmpty())
            UsersInterface->setObjectName("UsersInterface");
        UsersInterface->resize(400, 300);

        retranslateUi(UsersInterface);

        QMetaObject::connectSlotsByName(UsersInterface);
    } // setupUi

    void retranslateUi(QWidget *UsersInterface)
    {
        UsersInterface->setWindowTitle(QCoreApplication::translate("UsersInterface", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsersInterface: public Ui_UsersInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSINTERFACE_H
