#ifndef STUDENTBASICINFO_H
#define STUDENTBASICINFO_H

#include <QWidget>
#include <QHash>
#include <QSqlQuery>
#include <QComboBox>

namespace Ui {
class StudentBasicInfo;
}

class StudentBasicInfo : public QWidget
{
    Q_OBJECT

public:
    explicit StudentBasicInfo(QWidget *parent = nullptr);
    ~StudentBasicInfo();
    void initSearchInfo();
    void generateData();
    void generateTableView();

private:
    void getData();
    void setData();
    void setOneData(QSqlQuery& query,QList<QString>& tList,const QString& name,const QString& tableQuery);
    void fillOneData(QComboBox* combobox,QList<QString>& tList);

private:
    Ui::StudentBasicInfo *ui;
    QHash<QString,QString> searchInfo;

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
