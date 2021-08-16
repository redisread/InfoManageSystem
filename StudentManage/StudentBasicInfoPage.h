#ifndef STUDENTBASICINFO_H
#define STUDENTBASICINFO_H

#include <QWidget>
#include <QHash>
#include <QSqlQuery>
#include <QComboBox>
#include <QMenu>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlRelationalTableModel>
#include "StudentInfoUpdatePage.h"

namespace Ui {
class StudentBasicInfo;
}

class StudentBasicInfoPage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentBasicInfoPage(QWidget *parent = nullptr);
    ~StudentBasicInfoPage();
    /**
     * @brief initSearchInfo 初始化查询的信息，从数据库种加载
     */
    void initSearchInfo();
    /**
     * @brief generateData 初始化数据，从数据库种加载
     */
    void generateData();
    /**
     * @brief generateTableView 初始化表格数据模型
     */
    void generateTableView();

private:
    void getData();
    void setData();
    void setOneData(QSqlQuery& query,QList<QString>& tList,const QString& name,const QString& tableQuery);
    void fillOneData(QComboBox* combobox,QList<QString>& tList);

private slots:
    /**
     * @brief slotContextMenu 右键菜单响应槽
     * @param pos
     */
    void slotContextMenu(QPoint pos);
    /**
     * @brief rightClickPage 右键打开学生信息修改页面的槽
     */
    void rightClickPage();
private:
    Ui::StudentBasicInfo *ui;
    QHash<QString,QString> searchInfo;
    /**
     * @brief popMenu 右键菜单组件
     */
    QMenu *popMenu;
    /**
     * @brief updatePage 学生信息更新页面
     */
    StudentInfoUpdatePage* updatePage;
    /**
     * @brief model 关系数据库模型
     */
    QSqlRelationalTableModel *model;

    /**
     * @brief campusList 校区列表
     */
    QList<QString> campusList;
    QList<QString> educationTypeList;
    QList<QString> teachPlaceList;
    QList<QString> schoolList;
    QList<QString> firstSemesterList;
    QList<QString> headTaecherList;
    QList<QString> companyList;
    QList<QString> majoyList;
    QList<QString> statusList;
    QList<QString> applicantList;
    QList<QString> semesterList;
    QList<QString> klassList;
    QList<QString> levelList;
    QList<QString> advanceProcessList;
};

#endif // STUDENTBASICINFO_H
