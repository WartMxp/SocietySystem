#ifndef STRUCT_H
#define STRUCT_H
#include <QString>

typedef struct {

    QString name;
    QString email;
    QString description;
    QString password;

} stuInfo;

typedef struct {

    QString name;
    QString type;
    QString description;
    QString leader;

} socInfo;

typedef struct {

    int societyId;
    int userId;
    bool isLeader;

} socMemInfo;

typedef struct {

    qint32 societyId;
    QString title;
    QString type;
    QString description;

} actInfo;

typedef struct {

    int activityId;
    int societyId;
    int userId;

} actPtpInfo;
#endif // STRUCT_H
