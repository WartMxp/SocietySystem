/********************************************************************************
** Form generated from reading UI file 'Interface.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *usersname;
    QPushButton *exitButton;
    QPushButton *testButtom;
    QTreeWidget *treeWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_manage3;
    QGridLayout *gridLayout_7;
    QTableWidget *manage3_table;
    QWidget *page_manage1;
    QGridLayout *gridLayout_4;
    QTableWidget *manage1_table;
    QWidget *page_manage2;
    QTableWidget *manage2_table;
    QWidget *page_home3;
    QGridLayout *gridLayout_6;
    QTableWidget *home3_table;
    QWidget *page_home1;
    QWidget *page_recent_act;
    QGridLayout *gridLayout_5;
    QTableWidget *recent_act_table;
    QWidget *page_home2;
    QTableWidget *home2_table;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 480);
        Widget->setMinimumSize(QSize(800, 480));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        Widget->setWindowIcon(icon);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(161, 196, 232);"));
        gridLayout_3 = new QGridLayout(Widget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        label = new QLabel(widget_2);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        usersname = new QLabel(widget);
        usersname->setObjectName("usersname");

        gridLayout_2->addWidget(usersname, 1, 1, 1, 1);

        exitButton = new QPushButton(widget);
        exitButton->setObjectName("exitButton");
        exitButton->setMinimumSize(QSize(60, 0));
        exitButton->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(exitButton, 1, 2, 1, 1);

        testButtom = new QPushButton(widget);
        testButtom->setObjectName("testButtom");
        testButtom->setMinimumSize(QSize(60, 0));
        testButtom->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(testButtom, 1, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 2, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);

        gridLayout_3->addWidget(widget_2, 0, 0, 1, 3);

        treeWidget = new QTreeWidget(Widget);
        treeWidget->headerItem()->setText(0, QString());
        treeWidget->setObjectName("treeWidget");
        treeWidget->setMaximumSize(QSize(180, 16777215));
        treeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 143, 176);"));
        treeWidget->header()->setVisible(false);

        gridLayout_3->addWidget(treeWidget, 3, 0, 1, 1);

        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 163, 199);"));
        page_manage3 = new QWidget();
        page_manage3->setObjectName("page_manage3");
        gridLayout_7 = new QGridLayout(page_manage3);
        gridLayout_7->setObjectName("gridLayout_7");
        manage3_table = new QTableWidget(page_manage3);
        if (manage3_table->columnCount() < 5)
            manage3_table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        manage3_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        manage3_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        manage3_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        manage3_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        manage3_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        manage3_table->setObjectName("manage3_table");
        manage3_table->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(57, 57, 57);"));

        gridLayout_7->addWidget(manage3_table, 0, 0, 1, 1);

        stackedWidget->addWidget(page_manage3);
        page_manage1 = new QWidget();
        page_manage1->setObjectName("page_manage1");
        gridLayout_4 = new QGridLayout(page_manage1);
        gridLayout_4->setObjectName("gridLayout_4");
        manage1_table = new QTableWidget(page_manage1);
        if (manage1_table->columnCount() < 4)
            manage1_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        manage1_table->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        manage1_table->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        manage1_table->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        manage1_table->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        manage1_table->setObjectName("manage1_table");
        manage1_table->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        manage1_table->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(57, 57, 57);"));
        manage1_table->horizontalHeader()->setCascadingSectionResizes(false);
        manage1_table->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        manage1_table->horizontalHeader()->setStretchLastSection(false);
        manage1_table->verticalHeader()->setCascadingSectionResizes(false);
        manage1_table->verticalHeader()->setMinimumSectionSize(40);
        manage1_table->verticalHeader()->setHighlightSections(false);
        manage1_table->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        manage1_table->verticalHeader()->setStretchLastSection(false);

        gridLayout_4->addWidget(manage1_table, 0, 0, 1, 1);

        stackedWidget->addWidget(page_manage1);
        page_manage2 = new QWidget();
        page_manage2->setObjectName("page_manage2");
        manage2_table = new QTableWidget(page_manage2);
        if (manage2_table->columnCount() < 5)
            manage2_table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        manage2_table->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        manage2_table->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        manage2_table->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        manage2_table->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        manage2_table->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        manage2_table->setObjectName("manage2_table");
        manage2_table->setGeometry(QRect(0, 30, 588, 388));
        manage2_table->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(57, 57, 57);"));
        stackedWidget->addWidget(page_manage2);
        page_home3 = new QWidget();
        page_home3->setObjectName("page_home3");
        gridLayout_6 = new QGridLayout(page_home3);
        gridLayout_6->setObjectName("gridLayout_6");
        home3_table = new QTableWidget(page_home3);
        if (home3_table->columnCount() < 5)
            home3_table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        home3_table->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        home3_table->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        home3_table->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        home3_table->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        home3_table->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        home3_table->setObjectName("home3_table");
        home3_table->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(57, 57, 57);"));

        gridLayout_6->addWidget(home3_table, 0, 0, 1, 1);

        stackedWidget->addWidget(page_home3);
        page_home1 = new QWidget();
        page_home1->setObjectName("page_home1");
        stackedWidget->addWidget(page_home1);
        page_recent_act = new QWidget();
        page_recent_act->setObjectName("page_recent_act");
        gridLayout_5 = new QGridLayout(page_recent_act);
        gridLayout_5->setObjectName("gridLayout_5");
        recent_act_table = new QTableWidget(page_recent_act);
        if (recent_act_table->columnCount() < 5)
            recent_act_table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        recent_act_table->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        recent_act_table->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        recent_act_table->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        recent_act_table->setHorizontalHeaderItem(3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        recent_act_table->setHorizontalHeaderItem(4, __qtablewidgetitem23);
        recent_act_table->setObjectName("recent_act_table");
        recent_act_table->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(57, 57, 57);"));

        gridLayout_5->addWidget(recent_act_table, 0, 0, 1, 1);

        stackedWidget->addWidget(page_recent_act);
        page_home2 = new QWidget();
        page_home2->setObjectName("page_home2");
        home2_table = new QTableWidget(page_home2);
        if (home2_table->columnCount() < 5)
            home2_table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        home2_table->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        home2_table->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        home2_table->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        home2_table->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        home2_table->setHorizontalHeaderItem(4, __qtablewidgetitem28);
        home2_table->setObjectName("home2_table");
        home2_table->setGeometry(QRect(0, 10, 611, 421));
        home2_table->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(57, 57, 57);"));
        stackedWidget->addWidget(page_home2);

        gridLayout_3->addWidget(stackedWidget, 3, 1, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\351\253\230\346\240\241\347\244\276\345\233\242\350\256\277\351\227\256\347\263\273\347\273\237", nullptr));
#if QT_CONFIG(tooltip)
        Widget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("Widget", "\346\254\242\350\277\216\350\256\277\351\227\256\351\253\230\346\240\241\347\244\276\345\233\242\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        usersname->setText(QCoreApplication::translate("Widget", "usersname", nullptr));
        exitButton->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        testButtom->setText(QCoreApplication::translate("Widget", "\346\265\213\350\257\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem = manage3_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "\347\244\276\345\233\242ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = manage3_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "\346\264\273\345\212\250\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = manage3_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = manage3_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Widget", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = manage3_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Widget", "\347\256\200\344\273\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = manage1_table->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Widget", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = manage1_table->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Widget", "\351\202\256\347\256\261", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = manage1_table->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Widget", "\344\270\252\344\272\272\347\256\200\344\273\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = manage1_table->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = manage2_table->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Widget", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = manage2_table->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Widget", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = manage2_table->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Widget", "\347\256\200\344\273\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = manage2_table->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Widget", "\345\210\233\347\253\213\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = manage2_table->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Widget", "\350\264\237\350\264\243\344\272\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = home3_table->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Widget", "\347\244\276\345\233\242ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = home3_table->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Widget", "\346\264\273\345\212\250\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = home3_table->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = home3_table->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Widget", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = home3_table->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Widget", "\347\256\200\344\273\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = recent_act_table->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Widget", "\347\244\276\345\233\242ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = recent_act_table->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("Widget", "\346\264\273\345\212\250\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = recent_act_table->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = recent_act_table->horizontalHeaderItem(3);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("Widget", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = recent_act_table->horizontalHeaderItem(4);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("Widget", "\347\256\200\344\273\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = home2_table->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("Widget", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = home2_table->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("Widget", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = home2_table->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("Widget", "\347\256\200\344\273\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = home2_table->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("Widget", "\345\210\233\347\253\213\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = home2_table->horizontalHeaderItem(4);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("Widget", "\350\264\237\350\264\243\344\272\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
