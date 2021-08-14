#ifndef MYSQLHELPER_H
#define MYSQLHELPER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QVector>

#include "Model/User.h"

class MysqlHelper {
private:
    QSqlDatabase database;// 用于建立和数据库的连接
public:
    MysqlHelper(QString hostName,int port,QString userName,QString password);

    QSqlDatabase *getDatabase();
    /*
     * 打开数据库
     * */
    bool openDatabase(QString DatabaseName);
    /*
     * 关闭数据库
     * */
    void closeDatabase();
    /*
     * 查询是否有该用户
     * @Param
     * @Return
     * */
    bool containUser(User user);

};
#endif // MYSQLHELPER_H
