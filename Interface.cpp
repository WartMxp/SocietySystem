#include "Interface.h"
#include "./ui_Interface.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , ptrSocietiesSql(nullptr) {

    ui->setupUi(this);
    //使登陆界面默认开启
    login.show();
    auto s = [&]() {
        this->show();
    };
    connect(&login, &Login::login_success, this, s);
    // 初始化界面

    // 初始化数据库类
    ptrSocietiesSql = SocietiesSql::get_instance();
    //左侧展示栏设计
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(1);
    // QStringList l_students("Students"), l_admin("Admin");
    // // 构造两个父类来使学生登陆时的管理员节点隐藏
    // // QTreeWidgetItem* pf = new QTreeWidgetItem(ui->treeWidget, lf);
    // QTreeWidgetItem* p_students = new QTreeWidgetItem(ui->treeWidget, l_students);
    // QTreeWidgetItem* p_admin = new QTreeWidgetItem(ui->treeWidget, l_admin);

    // ui->treeWidget->addTopLevelItem(p_students);
    // ui->treeWidget->addTopLevelItem(p_admin);
    // pf->addChild(pls); pf->addChild(prs);
    // ui->treeWidget->expandAll();

    // 近期活动，个人中心（个人主页，社团管理，活动管理），后台管理（用户管理，社团管理，活动管理）
    // 审核功能
    QStringList ra("近期活动"), h("个人中心"), m("后台管理");
    QTreeWidgetItem* recent_act = new QTreeWidgetItem(ui->treeWidget, ra);
    QTreeWidgetItem* home = new QTreeWidgetItem(ui->treeWidget, h);
    QTreeWidgetItem* manage = new QTreeWidgetItem(ui->treeWidget, m);
    ui->treeWidget->addTopLevelItem(recent_act);
    ui->treeWidget->addTopLevelItem(home);
    ui->treeWidget->addTopLevelItem(manage);
    QStringList h1("个人主页"), h2("社团管理"), h3("活动管理"),
        m1("用户管理"), m2("社团管理"), m3("活动管理");
    QTreeWidgetItem* home1 = new QTreeWidgetItem(home, h1);
    QTreeWidgetItem* home2 = new QTreeWidgetItem(home, h2);
    QTreeWidgetItem* home3 = new QTreeWidgetItem(home, h3);
    QTreeWidgetItem* manage1 = new QTreeWidgetItem(manage, m1);
    QTreeWidgetItem* manage2 = new QTreeWidgetItem(manage, m2);
    QTreeWidgetItem* manage3 = new QTreeWidgetItem(manage, m3);
    manage->addChild(manage1); manage->addChild(manage2); manage->addChild(manage3);
    home->addChild(home1); home->addChild(home2); home->addChild(home3);
    /*
     * 学生：
     * 社团信息管理：浏览社团信息（名称，类型，简介，创立时间，负责人）；支持按类型筛选
     * 社团活动管理：浏览社团活动信息（名称，时间，地点，类型，活动说明；支持筛选（或按时间排序）
     * 个人社团管理：查看自己已加入的社团列表及详细信息（包含加入时间）
     *
     * 管理员：
     * 社团管理：添加/删除/修改社团信息（名称，类型，简介，创作时间，负责人）；支持按类型筛选
     * 成员管理：成员注册（学号，姓名，学院，联系方式）；加入/退出社团；查询成员所属社团
     * 活动管理：发布活动（名称，时间，地点，类型，活动说明）；记录活动参与成员；生成活动总结报告
     */
    // 默认展开
    ui->treeWidget->expandAll();

    // 使stack与tree的页面一一对应
    recent_act->setData(0, Qt::UserRole, "page_recent_act");
    home1->setData(0, Qt::UserRole, "page_home1");
    home2->setData(0, Qt::UserRole, "page_home2");
    home3->setData(0, Qt::UserRole, "page_home3");
    manage1->setData(0, Qt::UserRole, "page_manage1");
    manage2->setData(0, Qt::UserRole, "page_manage2");
    manage3->setData(0, Qt::UserRole, "page_manage3");

    connect(ui->treeWidget, &QTreeWidget::currentItemChanged,
            this, &Widget::onTreeItemChanged);
    ui->treeWidget->setCurrentItem(recent_act);
    // 数据导入
    addDataToList();
    if(QSqlDatabase::drivers().isEmpty()) {
        qDebug() << "No database drivers found";
    }
    db = QSqlDatabase::addDatabase("QSQLITE");
#if 0
    auto str = QCoreApplication::applicationDirPath() + "Societies.db";
    qDebug() << str;
#endif
    db.setDatabaseName("Societies.db");
    if(!db.open()) {
        qDebug() << "Database open failed." << db.lastError().text();
        return ;
    }
    // 导入学生数据
    addStudentsToTable();
    addActivitiesToTable();
    addSocietyToTable();
}

void Widget::addStudentsToTable() {
    QSqlQuery query(db);
    query.prepare("SELECT name, email, description, password FROM users");
    // 清空表格 // manage1_table
    ui->manage1_table->clearContents();
    ui->manage1_table->setRowCount(0);

    if (query.exec()) {
        while (query.next()) { // 创建新行
            int currentRow = ui->manage1_table->rowCount();
            ui->manage1_table->insertRow(currentRow);
            ui->manage1_table->setItem(currentRow, 0, new QTableWidgetItem(query.value("name").toString()));
            ui->manage1_table->setItem(currentRow, 1, new QTableWidgetItem(query.value("email").toString()));
            ui->manage1_table->setItem(currentRow, 2, new QTableWidgetItem(query.value("description").toString()));
            ui->manage1_table->setItem(currentRow, 3, new QTableWidgetItem(query.value("password").toString()));
        }
    } else {
        qDebug() << "Search error：" << query.lastError().text();
    }
    // 自动调整列宽
    ui->manage1_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void Widget::addSocietyToTable() {
    QSqlQuery query(db);
    query.prepare("SELECT name, type, description, create_time, leader FROM society");
    // manage2_table home2_table
    ui->manage2_table->clearContents();
    ui->manage2_table->setRowCount(0);
    ui->home2_table->clearContents();
    ui->home2_table->setRowCount(0);

    if (query.exec()) {
        while (query.next()) { // 创建新行
            int currentRow = ui->manage2_table->rowCount();
            ui->manage2_table->insertRow(currentRow);
            ui->manage2_table->setItem(currentRow, 0, new QTableWidgetItem(query.value("name").toString()));
            ui->manage2_table->setItem(currentRow, 1, new QTableWidgetItem(query.value("type").toString()));
            ui->manage2_table->setItem(currentRow, 2, new QTableWidgetItem(query.value("description").toString()));
            ui->manage2_table->setItem(currentRow, 3, new QTableWidgetItem(query.value("create_time").toString()));
            ui->manage2_table->setItem(currentRow, 4, new QTableWidgetItem(query.value("leader").toString()));
            currentRow = ui->home2_table->rowCount();
            ui->home2_table->insertRow(currentRow);
            ui->home2_table->setItem(currentRow, 0, new QTableWidgetItem(query.value("name").toString()));
            ui->home2_table->setItem(currentRow, 1, new QTableWidgetItem(query.value("type").toString()));
            ui->home2_table->setItem(currentRow, 2, new QTableWidgetItem(query.value("description").toString()));
            ui->home2_table->setItem(currentRow, 3, new QTableWidgetItem(query.value("create_time").toString()));
            ui->home2_table->setItem(currentRow, 4, new QTableWidgetItem(query.value("leader").toString()));
        }
    } else {
        qDebug() << "Search error：" << query.lastError().text();
    }
    // 自动调整列宽
    ui->manage2_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->home2_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void Widget::on_exitButton_clicked() {
    exit(0);
}

void Widget::addActivitiesToTable() {
    QSqlQuery query(db);
    query.prepare("SELECT society_id, title, create_time, type, description FROM activities");
    // 清空表格 // manage3_table, recent_act_table
    ui->manage3_table->clearContents();
    ui->manage3_table->setRowCount(0);
    ui->home3_table->clearContents();
    ui->home3_table->setRowCount(0);
    ui->recent_act_table->clearContents();
    ui->recent_act_table->setRowCount(0);

    if (query.exec()) {
        while (query.next()) { // 创建新行
            int currentRow = ui->manage3_table->rowCount();
            ui->manage3_table->insertRow(currentRow);
            ui->manage3_table->setItem(currentRow, 0, new QTableWidgetItem(query.value("society_id").toString()));
            ui->manage3_table->setItem(currentRow, 1, new QTableWidgetItem(query.value("title").toString()));
            ui->manage3_table->setItem(currentRow, 2, new QTableWidgetItem(query.value("create_time").toString()));
            ui->manage3_table->setItem(currentRow, 3, new QTableWidgetItem(query.value("type").toString()));
            ui->manage3_table->setItem(currentRow, 4, new QTableWidgetItem(query.value("description").toString()));
            currentRow = ui->recent_act_table->rowCount();
            ui->recent_act_table->insertRow(currentRow);
            ui->recent_act_table->setItem(currentRow, 0, new QTableWidgetItem(query.value("society_id").toString()));
            ui->recent_act_table->setItem(currentRow, 1, new QTableWidgetItem(query.value("title").toString()));
            ui->recent_act_table->setItem(currentRow, 2, new QTableWidgetItem(query.value("create_time").toString()));
            ui->recent_act_table->setItem(currentRow, 3, new QTableWidgetItem(query.value("type").toString()));
            ui->recent_act_table->setItem(currentRow, 4, new QTableWidgetItem(query.value("description").toString()));
            currentRow = ui->home3_table->rowCount();
            ui->home3_table->insertRow(currentRow);
            ui->home3_table->setItem(currentRow, 0, new QTableWidgetItem(query.value("society_id").toString()));
            ui->home3_table->setItem(currentRow, 1, new QTableWidgetItem(query.value("title").toString()));
            ui->home3_table->setItem(currentRow, 2, new QTableWidgetItem(query.value("create_time").toString()));
            ui->home3_table->setItem(currentRow, 3, new QTableWidgetItem(query.value("type").toString()));
            ui->home3_table->setItem(currentRow, 4, new QTableWidgetItem(query.value("description").toString()));
        }
    } else {
        qDebug() << "Search error：" << query.lastError().text();
    }
    // 自动调整列宽
    ui->home3_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->manage3_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->recent_act_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void Widget::onTreeItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    Q_UNUSED(previous);
    if (!current) return;

    QString pageName = current->data(0, Qt::UserRole).toString();

    for (int i = 0; i < ui->stackedWidget->count(); ++i) {
        if (ui->stackedWidget->widget(i)->objectName() == pageName) {
            ui->stackedWidget->setCurrentIndex(i);
            return;
        }
    }

    qWarning() << "Page not found for:" << pageName;
}

Widget::~Widget() {
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event) { // 按键刷新
    if(event->key() == Qt::Key_F6) {
        QFile f;
        auto str = QCoreApplication::applicationDirPath();
        f.setFileName(str+"//"+"stuQss.css");
        f.open(QIODevice::ReadOnly);
        QString strQss = f.readAll();
        this->setStyleSheet(strQss);
        login.setStyleSheet(strQss);

    }
}

void Widget::on_testButtom_clicked()
{
    QRandomGenerator g;
    g.seed(0);
    g.bounded(7, 9);
    for(int i = 0;i < l.size();i ++) {
        stuInfo info;
        info.name = l[i];

        info.email = QString::number(i * 114514) + "@qq.com";
        info.description = QString::number(i);
        info.password = QString::number(123456);
        ptrSocietiesSql->addStudent(info);

    }
}

void Widget::on_pushButton_5_clicked() {

}

void Widget::on_add_button_clicked() { //

}

void Widget::on_usersname_linkActivated(const QString &link) {

}

void Widget::addDataToList() {

    // shit
    l << "止天薇";
    l << "和雅柔";
    l << "胡醉巧";
    l << "佴紫萱";
    l << "布访天";
    l << "蒲鹏天";
    l << "泉初瑶";
    l << "霍静槐";
    l << "谯亦凝";
    l << "班友灵";
    l << "愚涵意";
    l << "饶嘉言";
    l << "贡国";
    l << "保希蓉";
    l << "及旭炎";
    l << "仙爰美";
    l << "漆雕婉慧";
    l << "党辰良";
    l << "喜音华";
    l << "法施诗";
    l << "苑晴曦";
    l << "多怡";
    l << "单诺";
    l << "翦忆秋";
    l << "谬会雯";
    l << "晁春竹";
    l << "楼雅云";
    l << "纪问萍";
    l << "谏怀薇";
    l << "朱薄";
    l << "睦丽佳";
    l << "易代梅";
    l << "楚骏哲";
    l << "须梦山";
    l << "粘千山";
    l << "百里惠丽";
    l << "鄂婷秀";
    l << "世昶";
    l << "訾哲茂";
    l << "声秋白";
    l << "尔翠绿";
    l << "虎绢";
    l << "袁建本";
    l << "邗娟巧";
    l << "赫思真";
    l << "艾书萱";
    l << "慕平安";
    l << "瑞丽珠";
    l << "国飞舟";
    l << "改半芹";
    l << "綦曼寒";
    l << "伟若云";
    l << "用希彤";
    l << "费莫向真";
    l << "裴暖姝";
    l << "吴安容";
    l << "纳喇永丰";
    l << "皇甫博雅";
    l << "仪绮梅";
    l << "咸天宇";
    l << "有小夏";
    l << "亢虹";
    l << "甘卓";
    l << "性雅彤";
    l << "位昭";
    l << "帅迎曼";
    l << "蓬新之";
    l << "错诗蕾";
    l << "忻家";
    l << "原兴庆";
    l << "边雅丽";
    l << "回夏寒";
    l << "毕芷荷";
    l << "可天悦";
    l << "银寄春";
    l << "师心语";
    l << "狂时";
    l << "籍安福";
    l << "司庄丽";
    l << "浦鸿畅";
    l << "季向山";
    l << "蒋驰海";
    l << "花雅青";
    l << "桂温韦";
    l << "乌雅昌黎";
    l << "赫连明轩";
    l << "五璇娟";
    l << "苏丹亦";
    l << "将智晖";
    l << "皋德佑";
    l << "帛嘉玉";
    l << "本鸿朗";
    l << "道定";
    l << "俟语柔";
    l << "扶夏山";
    l << "奇承福";
    l << "封语梦";
    l << "勤初珍";
    l << "殷飞翮";
    l << "长孙天干";
    l << "初星辰";
    l << "登清雅";
    l << "丑萝";
    l << "褚芊丽";
    l << "抗丽";
    l << "舒尔蓝";
    l << "郏娴淑";
    l << "贰雁露";
    l << "赤柔雅";
    l << "合以彤";
    l << "禚麦冬";
    l << "贸欢";
    l << "东郭庆生";
    l << "项曦之";
    l << "己谷之";
    l << "阚理群";
    l << "典高远";
    l << "东方云臻";
    l << "休夏兰";
    l << "伯和";
    l << "占婀娜";
    l << "乌孙仙媛";
    l << "沙悦";
    l << "霜夏山";
    l << "碧烨伟";
    l << "脱静娴";
    l << "接雨莲";
    l << "集云霞";
    l << "旗梦寒";
    l << "徐德元";
    l << "夏依风";
    l << "卯忆";
    l << "祁光华";
    l << "唐莲";
    l << "隗映冬";
    l << "莱玉堂";
    l << "汪优";
    l << "竭初瑶";
    l << "管鹏鲲";
    l << "宝旷";
    l << "其亘";
    l << "汤梦秋";
    l << "香海秋";
    l << "友以蕊";
    l << "务广";
    l << "庾明哲";
    l << "节寻桃";
    l << "包书文";
    l << "说妮";
    l << "亓官和豫";
    l << "勇涵菡";
    l << "洋雯华";
    l << "弥瑜";
    l << "井海之";
    l << "帖高洁";
    l << "冉月华";
    l << "欧哲思";
    l << "溥向真";
    l << "祈娅童";
    l << "杨康裕";
    l << "印痴灵";
    l << "第若华";
    l << "后兰娜";
    l << "委昭昭";
    l << "仉天籁";
    l << "丛文敏";
    l << "别如雪";
    l << "淳于文华";
    l << "澄绍辉";
    l << "英新冬";
    l << "第五安白";
    l << "豆听露";
    l << "曾高芬";
    l << "欧阳香天";
    l << "太史又柔";
    l << "生琳怡";
    l << "藩倚云";
    l << "盍元化";
    l << "墨琰";
    l << "门春梅";
    l << "詹涵衍";
    l << "司徒裕";
    l << "展薇歌";
    l << "铎舒畅";
    l << "竹奇文";
    l << "以飞薇";
    l << "宋念蕾";
    l << "何华池";
    l << "夫锦";
    l << "禾洛灵";
    l << "达曼冬";
    l << "涂洁玉";
    l << "阴念蕾";
    l << "董映寒";
    l << "候芸若";
    l << "姚睿思";
    l << "剑代芙";
    l << "卷梦寒";
    l << "孝学名";
    l << "老邵美";
    l << "烟烟";
    l << "郯奇";
    l << "载默";
    l << "徭梦凡";
    l << "耿晓桐";
    l << "闫乐儿";
    l << "郭冷珍";
    l << "檀丽泽";
    l << "资幻梅";
    l << "穰梦晨";
    l << "丁冰夏";
    l << "咎秀英";
    l << "泰怡畅";
    l << "嵇竹雨";
    l << "奉初夏";
    l << "云亦绿";
    l << "舜忻愉";
    l << "厍孟君";
    l << "干琛";
    l << "考清馨";
    l << "海巧香";
    l << "犁晤";
    l << "傅星雨";
    l << "窦念之";
    l << "武忍";
    l << "风语儿";
    l << "禹沈然";
    l << "卿君昊";
    l << "祭英发";
    l << "孙尔风";
    l << "钦幼丝";
    l << "良恨瑶";
    l << "王怜双";
    l << "束小之";
    l << "邶秋英";
    l << "野诗蕾";
    l << "乙德水";
    l << "厉葳";
    l << "疏韵诗";
    l << "衡永昌";
    l << "吕令慧";
    l << "函雅昶";
    l << "魏寄";
    l << "敬浩宕";
    l << "石晋鹏";
    l << "敛浩歌";
    l << "允森";
    l << "丘芸欣";
    l << "查华皓";
    l << "次英韶";
    l << "续颖然";
    l << "索星瑶";
    l << "阿以珊";
    l << "狄星剑";
    l << "绪锐";
    l << "树诗怀";
    l << "公羊柔丽";
    l << "岳温瑜";
    l << "张简曼吟";
    l << "箕语山";
    l << "完颜芷烟";
    l << "璩谷雪";
    l << "荆刚";
    l << "卞华清";
    l << "萨傲易";
    l << "邸倚云";
    l << "诺半雪";
    l << "郑凡灵";
    l << "蓝映雁";
    l << "朴向卉";
    l << "母新翰";
    l << "蒯绣梓";
    l << "仝夏容";
    l << "化育";
    l << "让思松";
    l << "司空长星";
    l << "白怀桃";
    l << "祝季";
    l << "张廖子怡";
    l << "栾运凯";
    l << "招慧雅";
    l << "汗妍和";
    l << "类珊珊";
    l << "雀冰薇";
    l << "荣梓珊";
    l << "业念桃";
    l << "坚合";
    l << "邱虹英";
    l << "施又槐";
    l << "历霞月";
    l << "彭芮欢";
    l << "曹红艳";
    l << "歧明知";
    l << "杜初晴";
    l << "渠元芹";
    l << "虢正思";
    l << "巴桃雨";
    l << "开星海";
    l << "芮童欣";
    l << "钮涵山";
    l << "蒿思枫";
    l << "仇茜茜";
    l << "旅绮波";
    l << "华梦蕊";
    l << "龙子默";
    l << "公西秀华";
    l << "肇英";
    l << "台如曼";
    l << "堵绿海";
    l << "革阳波";
    l << "玄乐人";
    l << "麴良工";
    l << "马景焕";
    l << "祢之槐";
    l << "桐梓颖";
    l << "庹春雪";
    l << "么寻桃";
    l << "盖芳芳";
    l << "凌文斌";
    l << "乌巍昂";
    l << "古笑卉";
    l << "出丰雅";
    l << "寿俊楠";
    l << "令城";
    l << "归耘豪";
    l << "巢莺莺";
    l << "费孤云";
    l << "连英耀";
    l << "阮鸿卓";
    l << "宛妃";
    l << "酒骊美";
    l << "尉迟芬";
    l << "汉初晴";
    l << "军宵";
    l << "戏彩妍";
    l << "少煜祺";
    l << "逮青曼";
    l << "堂淑慧";
    l << "戊千柳";
    l << "盛小宸";
    l << "南元纬";
    l << "昝飞雨";
    l << "奈光耀";
    l << "茹桐";
    l << "向宛丝";
    l << "锁芷荷";
    l << "彤芮佳";
    l << "伏慕蕊";
    l << "戚松";
    l << "官羲";
    l << "斐千凡";
    l << "娄霞辉";
    l << "春谷雪";
    l << "敖安然";
    l << "黎骊霞";
    l << "鹿子薇";
    l << "势雪萍";
    l << "闪绮烟";
    l << "藏芸溪";
    l << "冠鸿煊";
    l << "礼鑫";
    l << "天思卉";
    l << "能冰绿";
    l << "后芃芃";
    l << "时依波";
    l << "斯彭湃";
    l << "明振凯";
    l << "钟离迎夏";
    l << "邢承宣";
    l << "惠子";
}

