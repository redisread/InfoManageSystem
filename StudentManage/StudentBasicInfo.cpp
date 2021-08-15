#include "StudentBasicInfo.h"
#include "ui_StudentBasicInfo.h"
#include "DatabaseUtils/MysqlHelper.h"
#include <QStandardItemModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

StudentBasicInfo::StudentBasicInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentBasicInfo)
{
    ui->setupUi(this);
    initSearchInfo();
    generateData();
//    ui->tableView
}

StudentBasicInfo::~StudentBasicInfo()
{
    delete ui;
}

/**
 * @brief StudentBasicInfo::initSearchInfo
 * 初始化映射表
 */
void StudentBasicInfo::initSearchInfo()
{
    searchInfo.insert("campus_id","*");
    searchInfo.insert("education_type","*");
    searchInfo.insert("teach_place_id","*");
    searchInfo.insert("school_id","*");
    searchInfo.insert("first_semester","*");
    searchInfo.insert("head_teacher_id","*");
    searchInfo.insert("company_id","*");
    searchInfo.insert("majoy_id","*");
    searchInfo.insert("status_id","*");
    searchInfo.insert("applicant_id","*");
    searchInfo.insert("semester","*");
    searchInfo.insert("klass_id","*");
    searchInfo.insert("level_id","*");
    searchInfo.insert("advance_process","*");
}

void StudentBasicInfo::generateData()
{
    MysqlHelper& mysqlHelper = MysqlHelper::getMysqlHelper();
    mysqlHelper.openDatabase();
    mysqlHelper.setDatabaseName(DatabaseConfig::DATABASE_NAME);

    this->getData();

    generateTableView();

//    mysqlHelper.closeDatabase();
//    mysqlHelper.getDatabase().isOpen();
    //    mysqlHelperPt->openDatabase(DatabaseConfig::)
}

void StudentBasicInfo::generateTableView()
{
    ui->tableView->setSortingEnabled(true);

//    QStandardItemModel* model = new QStandardItemModel();
//    QStringList labels = QObject::trUtf8("频率,功率,误差,频率,功率,误差,频率,功率,误差,频率,功率,误差,频率,功率,误差,频率,功率,误差").simplified().split(",");
//    model->setHorizontalHeaderLabels(labels);
//    ui->tableView->setModel(model);
//    ui->tableView->show();
    QSqlRelationalTableModel *model;
    model = new QSqlRelationalTableModel(this);
    //属性变化时写入数据库
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setTable("student");
    //将student表的第三个属性设为course表的id属性的外键，
    //并将其显示为course表的name属性的值
    model->setRelation(11,QSqlRelation("education_info","id","education_type"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("学生ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("学生姓名"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("学生年龄"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("民族"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("生日"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("出生地"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("通信地址"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("身份证号"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("准考证号"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("工作单位"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("电话号码"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("学历形式"));
//    model->setHeaderData(12, Qt::Horizontal, QObject::tr("学历形式"));


    model->select();
    ui->tableView->setModel(model);
//    QSqlTableModel* model = new QSqlTableModel(this);

//    model->setTable("student");
//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    model->select(); //选取整个表的所有行
//    //不显示name属性列,如果这时添加记录，则该属性的值添加不上
//    // model->removeColumn(1);
//    ui->tableView->setModel(model);

}

void StudentBasicInfo::getData()
{
    // 分校
    const QString CAMPUS = "campus_name";
    const QString CAMPUS_TABLE = "campus_info";
    // TODO:学历形式未知
    const QString EDUCATION_TYPE = "education_type";
    const QString EDUCATION_TABLE = "education_info";

    const QString TEACH_PLACE = "teach_place_name";
    const QString TEACH_PLACE_TABLE = "teach_place_info";

    const QString SCHOOL = "school_name";
    const QString SCHOOL_TABLE = "school_info";

    const QString FIRST_SEMESTER = "semester";
    const QString FIRST_SEMESTER_TABLE = "semester_info";

    const QString HEAD_TEACHER = "teacher_name";
    const QString HEAD_TEACHER_TABLE = "teacher";

    const QString CAMPANY = "campany_name";
    const QString CAMPANY_TABLE = "campany_info";

    const QString MAJOY = "majoy_name";
    const QString MAJOY_TABLE = "majoy_info";

    const QString STATUS = "status_name";
    const QString STATUS_TABLE = "student_status";

    // TODO:报名人未知
    const QString APPLICANT = HEAD_TEACHER;
    const QString APPLICANT_TABLE = HEAD_TEACHER_TABLE;

    // TODO:学期未知
    const QString SEMESTER = FIRST_SEMESTER;
    const QString SEMESTER_TABLE = FIRST_SEMESTER_TABLE;

    const QString KLASS = "klass_name";
    const QString KLASS_TABLE = "klass_info";

    const QString LEVEL = "education_type";
    const QString LEVEL_TABLE = "education_info";

    const QString ADVANCE = "advance_name";
    const QString ADVANCE_TABLE = "advance_info";


    // 设置查询语句
    QString basicQuery = "select %1 from %2";
    QString campusQuery = basicQuery.arg(CAMPUS).arg(CAMPUS_TABLE);
    QString educationTypeQuery = basicQuery.arg(EDUCATION_TYPE).arg(EDUCATION_TABLE);
    QString teachPlaceQuery = basicQuery.arg(TEACH_PLACE).arg(TEACH_PLACE_TABLE);
    QString schoolQuery = basicQuery.arg(SCHOOL).arg(SCHOOL_TABLE);
    QString firstSemesterQuery = basicQuery.arg(FIRST_SEMESTER).arg(FIRST_SEMESTER_TABLE);
    QString headTeacherQuery = basicQuery.arg(HEAD_TEACHER).arg(HEAD_TEACHER_TABLE);
    QString campanyQuery = basicQuery.arg(CAMPANY).arg(CAMPANY_TABLE);
    QString majoyQuery = basicQuery.arg(MAJOY).arg(MAJOY_TABLE);
    QString statusQuery = basicQuery.arg(STATUS).arg(STATUS_TABLE);
    QString applicantQuery = basicQuery.arg(APPLICANT).arg(APPLICANT_TABLE);
    QString semesterQuery = basicQuery.arg(SEMESTER).arg(SEMESTER_TABLE);
    QString klassQuery = basicQuery.arg(KLASS).arg(KLASS_TABLE);
    QString levelQuery = basicQuery.arg(LEVEL).arg(LEVEL_TABLE);
    QString advanceQuery = basicQuery.arg(ADVANCE).arg(ADVANCE_TABLE);

    // 执行SQL填充数据
    QSqlQuery query;
    setOneData(query,campusList,CAMPUS,campusQuery);
    setOneData(query,educationTypeList,EDUCATION_TYPE,educationTypeQuery);
    setOneData(query,teachPlaceList,TEACH_PLACE,teachPlaceQuery);
    setOneData(query,schoolList,SCHOOL,schoolQuery);
    setOneData(query,firstSemesterList,FIRST_SEMESTER,firstSemesterQuery);
    setOneData(query,headTaecherList,HEAD_TEACHER,headTeacherQuery);
    setOneData(query,companyList,CAMPANY,campanyQuery);
    setOneData(query,majoyList,MAJOY,majoyQuery);
    setOneData(query,statusList,STATUS,statusQuery);
    setOneData(query,applicantList,APPLICANT,applicantQuery);
    setOneData(query,semesterList,SEMESTER,semesterQuery);
    setOneData(query,klassList,KLASS,klassQuery);
    setOneData(query,levelList,LEVEL,levelQuery);
    setOneData(query,advanceProcessList,ADVANCE,advanceQuery);

    fillOneData(ui->comboBox_campus,campusList);
    fillOneData(ui->comboBox_education_type,educationTypeList);
    fillOneData(ui->comboBox_teach_place,teachPlaceList);
    fillOneData(ui->comboBox_school,schoolList);
    fillOneData(ui->comboBox_first_semester,firstSemesterList);
    fillOneData(ui->comboBox_head_teacher,headTaecherList);
    fillOneData(ui->comboBox_campany,companyList);
    fillOneData(ui->comboBox_majoy,majoyList);
    fillOneData(ui->comboBox_status,statusList);
    fillOneData(ui->comboBox_applicant,applicantList);
    fillOneData(ui->comboBox_semester,semesterList);
    fillOneData(ui->comboBox_kclass,klassList);
    fillOneData(ui->comboBox_level,levelList);
    fillOneData(ui->comboBox_advance_process,advanceProcessList);

    query.finish();
}

void StudentBasicInfo::setOneData(QSqlQuery &query, QList<QString> &tList, const QString &name, const QString &tableQuery)
{
    query.exec(tableQuery);
    if(query.size() > 0)
    {
        while(query.next())
        {
            tList.append(query.value(name).toString());
        }
    }

}

void StudentBasicInfo::fillOneData(QComboBox *combobox, QList<QString> &tList)
{
    combobox->addItem("全部");
    for(QString value:tList) {
        combobox->addItem(value);
    }
}


