#ifndef SOCIETIESSQL_H
#define SOCIETIESSQL_H

#include <QCoreApplication>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include "Struct.h"



class SocietiesSql : public QObject {
    Q_OBJECT

private:
    QSqlDatabase db;

public:
    explicit SocietiesSql(QObject* parent = nullptr);

    static SocietiesSql* pSocietiesSql;
    static SocietiesSql* get_instance() {
        if(nullptr == pSocietiesSql) {
            pSocietiesSql = new SocietiesSql;
        }
        return pSocietiesSql;
    }
    // 初始化数据库
    void init();
    // 添加管理员
    bool addWartToSystem();
    int getLastInsertId(QSqlQuery& query); // 添加用户使用的中转函数
    // 新建操作
    bool addStudent(const stuInfo& student);
    bool addSociety(const socInfo& society);
    bool addMemberToSociety(const socMemInfo& member);
    bool addActivity(const actInfo& activity);
    bool addParticipants(const actPtpInfo& participate);
    // 删除操作
    bool deleteStudent(int id); // 删除指定用户/学生
    bool deleteSociety(int id); // 删除指定社团
    bool deleteMemberToSociety();
    bool deleteActivity(int id); // 删除指定社团的指定活动
    // 修改操作
    bool changeSocietyLeader(int societyId, int newLeaderId);
    // 查找操作
    quint32 getStudentCount(); // 获知用户/学生数量
    // 写入数据表界面
    QList<stuInfo> getPageStu(quint32 page, quint32 uiCnt);

signals:
    void studentAdded(const stuInfo& student);
    void societyAdded(const socInfo& society);
    void memberAdded(const socMemInfo& member);
    void activityAdded(const actInfo& activity);
    void participantsAdded(const actPtpInfo& participant);
};

#endif // SOCIETIESSQL_H
