#include "SocietiesSql.h"

SocietiesSql* SocietiesSql::pSocietiesSql = nullptr;

SocietiesSql::SocietiesSql(QObject *parent)
    : QObject{parent} {
    /*
     * 构建思路：构造函数
    */

    // 若数据库不存在则初始化数据库
    SocietiesSql::init();
    // 添加wart作为管理员
    if (!SocietiesSql::addWartToSystem()) {
        qCritical() << "Critical error: Failed to initialize admin system";
    }
    // if(sq.exec()) {
    //     // 常规检查
    //     qDebug() << "Insert success";
    // } else {
    //     qDebug() << "failed" << sq.lastError().text();
    // }
    // stuInfo stu; stu.name = "Zfq"; stu.email = "1799146481@qq.com";
    // stu.password = "123456"; stu.description = "24级软工五班学生";
    // if(!SocietiesSql::addStudent(stu)) {
    //     qCritical() << "Critical error: Failed to initialize users system";
    // }
    // SocietiesSql::deleteStudent(2);

    // 写入tablewidget，应跳转到tableWidget槽

    // is_admin
    // is_leader
}

void SocietiesSql::init() {

    if(QSqlDatabase::drivers().isEmpty()) {
        qDebug() << "No database drivers found";
    }
    db = QSqlDatabase::addDatabase("QSQLITE");
#if 0
    auto str = QCoreApplication::applicationDirPath() + "Societies.db";
    qDebug() << str;
#endif
    db.setDatabaseName("Societies.db");
    //打开或新建数据库
    if(!db.open()) {
        qDebug() << "Database open failed." << db.lastError().text();
        return ;
    } /* else {
        qDebug() << "continue" << db.lastError().text();
    } */
    QSqlQuery query; // 要有光
    query.exec("PRAGMA foreign_keys = ON;"); // 启用外键语法
    // 初始化
    // 社团表初始化
    query.exec("CREATE TABLE IF NOT EXISTS society("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "name TEXT NOT NULL,"
               "type TEXT,"
               "description TEXT,"
               "create_time TEXT,"
               "leader TEXT" // NAME
               ");");
    // 用户表初始化（应对普通用户与管理员加type以区分）
    query.exec("CREATE TABLE IF NOT EXISTS users("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "name TEXT NOT NULL,"
               "email TEXT,"
               "description TEXT,"
               "joined_activity INTEGER,"
               "password TEXT NOT NULL,"
               "is_admin TEXT NOT NULL" // Y/N
               ");");
    // 社团成员表初始化
    query.exec("CREATE TABLE IF NOT EXISTS society_member("
               "society_id INTEGER NOT NULL," // FK
               "users_id INTEGER NOT NULL,"
               // 删除name以保证表的清晰
               "is_ leader TEXT NOT NULL," // Y/N
               "PRIMARY KEY (society_id, users_id)," // 复合主键
               "FOREIGN KEY (society_id) REFERENCES society(id)"
               "ON DELETE CASCADE,"
               "FOREIGN KEY (users_id) REFERENCES users(id)"
               "ON DELETE CASCADE"
               ");");
    // 活动表初始化
    query.exec("CREATE TABLE IF NOT EXISTS activities ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               //NOT NULL与AUTOINCREMENT无法共存
               "society_id NOT NULL," // FK
               "title TEXT UNIQUE,"
               "create_time TEXT,"
               "type TEXT,"
               "description TEXT,"
               "FOREIGN KEY (society_id) REFERENCES society(id)"
               "ON DELETE CASCADE"
               ");");
    // 活动成员表初始化
    query.exec("CREATE TABLE IF NOT EXISTS activity_participants ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "activity_id INTEGER NOT NULL,"
               "society_id INTEGER NOT NULL,"
               "users_id INTEGER NOT NULL,"
               "FOREIGN KEY (activity_id) REFERENCES activities(id)"
               "ON DELETE CASCADE," // 强相关，随主表数据变动而变动
               "FOREIGN KEY (society_id) REFERENCES society(id)"
               "ON DELETE CASCADE,"
               "FOREIGN KEY (users_id) REFERENCES users(id)"
               "ON DELETE CASCADE"
               ");");


}

int SocietiesSql::getLastInsertId(QSqlQuery& query) {
    // 获取最后输入流的id
    if (query.exec("SELECT last_insert_rowid()") && query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}

// 增删改查

bool SocietiesSql::addStudent(const stuInfo& student) {
    QSqlQuery query(db);

    query.prepare("SELECT id FROM users WHERE name = :name OR email = :email");
    query.bindValue(":name", student.name);
    query.bindValue(":email", student.email);
    if(query.exec() && query.next()) {
        qDebug() << "Society already exists:" << student.name;
        return false;
    }

    if(!db.transaction()) {
        qDebug() << "Transaction start failed:" << db.lastError().text();
        return false;
    }

    try { // 添加事物回滚
        // 添加学生
        query.prepare("INSERT INTO users (name, email, description, password, is_admin) "
                      "VALUES (:name, :email, :description, :password, 'N')");
        query.bindValue(":name", student.name);
        query.bindValue(":email", student.email);
        query.bindValue(":description", student.description);
        query.bindValue(":password", student.password);
        // 提交事务
        if (!query.exec()) throw query.lastError();
        if (!db.commit()) throw db.lastError();
        qDebug() << "User added successfully;" << student.name;
        emit studentAdded(student); // 发送信号
        return true;
    } catch(const QSqlError& e) { // 失败回滚
        db.rollback();
        qCritical() << "Failed to add user:" << e.text();
        return false;
    }
}

bool SocietiesSql::addSociety(const socInfo& society) {
    QSqlQuery query(db);

    query.prepare("SELECT id FROM society WHERE name = :name");
    query.bindValue(":name", society.name);
    if(query.exec() && query.next()) {
        qDebug() << "Society already exists:" << society.name;
        return false;
    }

    if(!db.transaction()) {
        qDebug() << "Transaction start failed:" << db.lastError().text();
        return false;
    }

    try {
        // 添加社团
        query.prepare("INSERT INTO society (name, type, description, create_time, leader) "
                      "VALUES (:name, :type, :description, :create_time, :leader)");
        query.bindValue(":name", society.name);
        query.bindValue(":type", society.type);
        query.bindValue(":description", society.description);
        query.bindValue(":create_time", QDateTime::currentDateTime().toString(Qt::ISODate));
        query.bindValue(":leader", society.leader);
        // 提交事务
        if (!query.exec()) throw query.lastError();
        if (!db.commit()) throw db.lastError();
        qDebug() << "Society added successfully;" << society.name;
        emit societyAdded(society);
        return true;
    } catch(const QSqlError& e) {
        db.rollback();
        qCritical() << "Failed to add society:" << e.text();
        return false;
    }
}

bool SocietiesSql::addMemberToSociety(const socMemInfo& member) {
    QSqlQuery query(db);

    query.prepare("SELECT 1 FROM society_member WHERE society_id = :s AND users_id = :u");
    query.bindValue(":s", member.societyId);
    query.bindValue(":u", member.userId);
    if(query.exec() && query.next()) {
        qDebug() << "User already exists in this society.";
        return false;
    }

    if(!db.transaction()) {
        qDebug() << "Transaction start failed:" << db.lastError().text();
        return false;
    }

    try {
        // 添加社团
        query.prepare("INSERT INTO society_member (society_id, users_id, is_leader) "
                      "VALUES (:society_id, :users_id, :is_leader)");
        query.bindValue(":society_id", member.societyId);
        query.bindValue(":users_id", member.userId);
        query.bindValue(":is_leader", member.isLeader ? "Y" : "N");
        // 提交事务
        if (!query.exec()) throw query.lastError();
        if (!db.commit()) throw db.lastError();
        qDebug() << "Society member added successfully." << member.userId;
        emit memberAdded(member);
        return true;
    } catch(const QSqlError& e) {
        db.rollback();
        qCritical() << "Failed to add member." << e.text();
        return false;
    }
}

bool SocietiesSql::addActivity(const actInfo& activity) {
    QSqlQuery query(db);

    query.prepare("SELECT id FROM society_member WHERE society_id = :s AND title = :t");
    query.bindValue(":s", activity.societyId);
    query.bindValue(":t", activity.title);

    if(query.exec() && query.next()) {
        qDebug() << "Activity already exists in this society.";
        return false;
    }

    if(!db.transaction()) {
        qDebug() << "Transaction start failed:" << db.lastError().text();
        return false;
    }

    try {
        // 添加社团
        query.prepare("INSERT INTO activities (society_id, title, create_time, type, description) "
                      "VALUES (:society_id, :title, :create_time, :type, :description)");
        query.bindValue(":society_id", activity.societyId);
        query.bindValue(":title", activity.title);
        query.bindValue(":create_time", QDateTime::currentDateTime().toString(Qt::ISODate));
        query.bindValue(":type", activity.type);
        query.bindValue(":description", activity.description);
        // 提交事务
        if (!query.exec()) throw query.lastError();
        if (!db.commit()) throw db.lastError();
        qDebug() << "Activity member added successfully." << activity.title;
        emit activityAdded(activity);
        return true;
    } catch(const QSqlError& e) {
        db.rollback();
        qCritical() << "Failed to add Activity." << e.text();
        return false;
    }

}

bool SocietiesSql::addParticipants(const actPtpInfo& participant) {
    QSqlQuery query(db);

    query.prepare("SELECT 1 FROM society_member WHERE society_id = :s AND users_id = :u");
    query.bindValue(":s", participant.societyId);
    query.bindValue(":u", participant.userId);

    if(query.exec() && query.next()) {
        qDebug() << "Activity already exists in this society.";
        return false;
    }

    if(!db.transaction()) {
        qDebug() << "Transaction start failed:" << db.lastError().text();
        return false;
    }

    try {
        // 添加社团
        query.prepare("INSERT INTO activity_participants (activity_id, society_id, users_id) "
                      "VALUES (:activity_id, :society_id, :users_id)");
        query.bindValue(":activity_id", participant.activityId);
        query.bindValue(":society_id", participant.societyId);
        query.bindValue(":users_id", participant.userId);
        // 提交事务
        if (!query.exec()) throw query.lastError();
        if (!db.commit()) throw db.lastError();
        qDebug() << "Activity member added successfully." << participant.activityId;
        emit participantsAdded(participant);
        return true;
    } catch(const QSqlError& e) {
        db.rollback();
        qCritical() << "Failed to add Activity." << e.text();
        return false;
    }

}

bool SocietiesSql::deleteStudent(int id) { // 删除指定学生

    QSqlQuery query(db);
    // 使用事务以确保数据一致性
    if (!db.transaction()) {
        qDebug() << "Transaction start failed:" << db.lastError().text();
        return false;
    }

    try {
        // 删除学生参加的社团成员关系
        query.prepare("DELETE FROM society_member WHERE users_id = :id");
        query.bindValue(":id", id);
        if (!query.exec()) throw query.lastError();
        // 删除学生参加的活动记录
        query.prepare("DELETE FROM activity_participants WHERE users_id = :id");
        query.bindValue(":id", id);
        if (!query.exec()) throw query.lastError();
        // 删除学生本身
        query.prepare("DELETE FROM users WHERE id = :id");
        query.bindValue(":id", id);
        if (!query.exec()) throw query.lastError();
        // 检查是否真正删除
        if (query.numRowsAffected() == 0) {
            throw QSqlError("No rows affected", "Student not found", QSqlError::NoError);
        }
        // 提交事务
        if (!db.commit()) throw db.lastError();

        qDebug() << "Student deleted successfully:" << id;
        return true;
    } catch (const QSqlError &e) {
        db.rollback();
        qCritical() << "Failed to delete student:" << id << "-" << e.text();
        return false;
    }

}

bool SocietiesSql::deleteActivity(int id) {
    QSqlQuery query(db);
    return query.exec(QString("DELETE FROM users WHERE id = %1").arg(id));
}

bool SocietiesSql::changeSocietyLeader(int societyId, int newLeaderId) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    // 开始事务
    if (!db.transaction()) {
        qDebug() << "Transaction start failed:" << db.lastError().text();
        return false;
    }

    try {
        // 检查新负责人是否是社团成员
        query.prepare("SELECT 1 FROM society_member "
                      "WHERE society_id = :soc_id AND users_id = :user_id");
        query.bindValue(":soc_id", societyId);
        query.bindValue(":user_id", newLeaderId);
        if (!query.exec() || !query.next()) {
            throw QSqlError("Invalid leader", "User not a member of society", QSqlError::ConnectionError);
        }
        // 更新社团负责人
        query.prepare("UPDATE society SET leader = :leader WHERE id = :soc_id");
        query.bindValue(":leader", newLeaderId);
        query.bindValue(":soc_id", societyId);
        if (!query.exec()) throw query.lastError();
        // 更新成员表中的领导状态
        query.prepare("UPDATE society_member SET is_leader = 'Y' "
                      "WHERE society_id = :soc_id AND users_id = :user_id");
        query.bindValue(":soc_id", societyId);
        query.bindValue(":user_id", newLeaderId);
        if (!query.exec()) throw query.lastError();
        // 提交事务
        if (!db.commit()) throw db.lastError();

        qDebug() << "Society leader changed:" << newLeaderId << "for society" << societyId;
        return true;
    } catch (const QSqlError &e) {
        db.rollback();
        qCritical() << "Failed to change society leader:" << e.text();
        return false;
    }
}

quint32 SocietiesSql::getStudentCount() {

    QSqlQuery query(db);
    quint32 uiCount = 0;
    query.exec("SELECT COUNT(id) FROM users;");
    while(query.next()) uiCount = query.value(0).toInt();

    return uiCount;
}

// 写入数据表页面


// 添加管理员

bool SocietiesSql::addWartToSystem() {

    QSqlQuery query(db);

    // 检查wart是否已存在
    query.prepare("SELECT id FROM users WHERE name = 'wart'");
    if(query.exec() && query.next()) {
        qDebug() << "wart already exists";
        return true;  // 已存在视为成功
    }

    // 开始事务
    if (!db.transaction()) {
        qDebug() << "Transaction start failed:" << db.lastError().text();
        return false;
    }

    try {
        // 添加管理员
        query.prepare("INSERT INTO users (name, email, description, password, is_admin) "
                      "VALUES ('wart', 'wartmxp@gmail.com', 'creator', '135619', 'Y')");
        if (!query.exec()) throw query.lastError();
        const int studentId = getLastInsertId(query);
        if (studentId <= 0) throw QSqlError("Failed to get student ID", "", QSqlError::TransactionError);
        // 添加社团
        QString currentTime = QDateTime::currentDateTime().toString(Qt::ISODate);
        query.prepare("INSERT INTO society (name, type, description, create_time, leader) "
                      "VALUES ('ACM协会', '计算机学院', '在Vjudge上做题的训练队', :time, :leader)");
        query.bindValue(":time", currentTime);
        query.bindValue(":leader", studentId);  // 存储用户ID而非名字
        if (!query.exec()) throw query.lastError();
        const int societyId = getLastInsertId(query);
        if (societyId <= 0) throw QSqlError("Failed to get society ID", "", QSqlError::TransactionError);
        // 添加社团成员关系
        query.prepare("INSERT INTO society_member (society_id, users_id, is_leader) "
                      "VALUES (:soc_id, :user_id, 'Y')");
        query.bindValue(":soc_id", societyId);
        query.bindValue(":user_id", studentId);
        if (!query.exec()) throw query.lastError();
        // 添加活动
        query.prepare("INSERT INTO activities (society_id, title, create_time, type, description) "
                      "VALUES (:soc_id, 'ACM第一次考核', :time, '考核', "
                      "'如培训无法到场的提前联系管理说明原因 可自行外带键鼠')");
        query.bindValue(":soc_id", societyId);
        query.bindValue(":time", currentTime);
        if (!query.exec()) throw query.lastError();
        const int activityId = getLastInsertId(query);
        if (activityId <= 0) throw QSqlError("Failed to get activity ID", "", QSqlError::TransactionError);
        // 添加活动参与
        query.prepare("INSERT INTO activity_participants (activity_id, society_id, users_id) "
                      "VALUES (:act_id, :soc_id, :user_id)");
        query.bindValue(":act_id", activityId);
        query.bindValue(":soc_id", societyId);
        query.bindValue(":user_id", studentId);
        if (!query.exec()) throw query.lastError();
        // 提交事务
        if (!db.commit()) throw db.lastError();

        qDebug() << "Wart system initialized successfully";
        qDebug() << "Congradulation Wart"; // 太有匠心了
        return true;
    } catch (const QSqlError &e) {
        db.rollback();
        qCritical() << "Initialization failed:" << e.text();
        return false;
    }
}

