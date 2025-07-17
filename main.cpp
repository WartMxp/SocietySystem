#include "Interface.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    qDebug() << "a" << QSqlDatabase::drivers();
    Widget w;

    return a.exec();
}
