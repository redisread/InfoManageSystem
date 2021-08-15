#ifndef MYSQLHELPER_H
#define MYSQLHELPER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QVector>

#include "Model/User.h"
#include "Config/DatabaseConfig.h"

/**
 * 单例
 * @brief The MysqlHelper class
 */
class MysqlHelper {
private:
    QSqlDatabase database;// 用于建立和数据库的连接
    MysqlHelper();
    ~MysqlHelper();
    MysqlHelper(const MysqlHelper&);
    MysqlHelper& operator=(const MysqlHelper&);

    MysqlHelper(QString hostName,int port,QString userName,QString password);

public:
    static MysqlHelper& getMysqlHelper();
    QSqlDatabase &getDatabase();
    /*
     * 打开数据库
     * */
    bool openDatabase();
    /*
     * 关闭数据库
     * */
    void closeDatabase();
    /**
     * 设置数据库的名字
     * @brief setDatabaseName
     * @param databaseName
     */
    void setDatabaseName(QString databaseName);

    /*
     * 查询是否有该用户
     * @Param
     * @Return
     * */
    bool containUser(User user);

};

//MysqlHelper* MysqlHelper::mysqlHelperPt = nullptr;

#endif // MYSQLHELPER_H
