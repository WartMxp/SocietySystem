#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QKeyEvent>
#include <QFile>
#include <QCoreApplication>
#include <QHeaderView>
#include <QString>
#include <QTreeWidgetItem> // sqlie3 sqlite2 mysql
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidget>
#include <QSqlRecord>
#include <QTimer>
#include <QProgressDialog>
#include <QRandomGenerator>
#include "Login.h"
#include "./ui_Login.h"
#include "Addstudent.h"
#include "./ui_Addstudent.h"
#include "SocietiesSql.h"
#include "Struct.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private:
    QSqlDatabase db;
    QHash<QString, QPair<QString, QString>> pageTableMap;
    SocietiesSql* ptrSocietiesSql;
    // pageId -> (tableName, widgetName)
    // QTimer* lazyLoadTimer;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    // 界面美化
    bool openDatabase();
    virtual void keyPressEvent(QKeyEvent* event);
    void onTreeItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void loadTableData(const QString& tableName, QTableWidget* targetTable);
    void addDataToList();
    void addStudentsToTable();
    void addActivitiesToTable();
    void addSocietyToTable();
    QTableWidget* getTableForPage(int pageIndex);

private slots:
    void on_testButtom_clicked();

    void on_usersname_linkActivated(const QString &link);

    void on_exitButton_clicked();

    void on_pushButton_5_clicked();

    void on_add_button_clicked();

signals:
    void delayedLoad();
private:
    Ui::Widget *ui;
    Login login;
    QTreeWidget* treeWidgetActivities;
    QStringList l;
    AddStudent dlg_add_student;
};
#endif // INTERFACE_H
