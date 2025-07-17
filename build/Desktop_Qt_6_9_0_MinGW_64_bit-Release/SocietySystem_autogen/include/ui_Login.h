/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QGridLayout *gridLayout_2;
    QLabel *label2;
    QLineEdit *password_line;
    QLineEdit *username_line;
    QLabel *label1;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QPushButton *logout_button;
    QPushButton *regist_button;
    QPushButton *login_button;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(300, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8("pictures/logo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Login->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(Login);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label2 = new QLabel(Login);
        label2->setObjectName("label2");
        label2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label2, 1, 1, 1, 1);

        password_line = new QLineEdit(Login);
        password_line->setObjectName("password_line");
        password_line->setMaxLength(8);
        password_line->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_2->addWidget(password_line, 1, 2, 1, 1);

        username_line = new QLineEdit(Login);
        username_line->setObjectName("username_line");
        username_line->setMaxLength(8);

        gridLayout_2->addWidget(username_line, 0, 2, 1, 1);

        label1 = new QLabel(Login);
        label1->setObjectName("label1");

        gridLayout_2->addWidget(label1, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        logout_button = new QPushButton(Login);
        logout_button->setObjectName("logout_button");
        logout_button->setMinimumSize(QSize(0, 25));
        logout_button->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(logout_button, 2, 0, 1, 1);

        regist_button = new QPushButton(Login);
        regist_button->setObjectName("regist_button");
        regist_button->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(regist_button, 1, 0, 1, 1);

        login_button = new QPushButton(Login);
        login_button->setObjectName("login_button");
        login_button->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(login_button, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        Login->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("Login", "\351\253\230\346\240\241\347\244\276\345\233\242\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label2->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201", nullptr));
        password_line->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245", nullptr));
        username_line->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245", nullptr));
        label1->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", nullptr));
        logout_button->setText(QCoreApplication::translate("Login", "\351\200\200\345\207\272", nullptr));
        regist_button->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        login_button->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
