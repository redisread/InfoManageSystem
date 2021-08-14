#ifndef SQLITEHELPER_H
#define SQLITEHELPER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QVector>

#include "Model/User.h"

class SqliteHelper {
private:
    QSqlDatabase database;// 用于建立和数据库的连接
public:
    SqliteHelper(){}
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

    //判断行数
    int queryRowCount(QSqlQuery query)
    {
        int initialPos = query.at();
        // Very strange but for no records .at() returns -2
        int pos = 0;
        if (query.last()){
            pos = query.at() + 1;
        }else{
            pos = 0;
        }
        // Important to restore initial pos
        query.seek(initialPos);
        return pos;
    }


};

bool SqliteHelper::containUser(User user) {
    QSqlQuery sqlQuery;
    QString queryCommand = QString("SELECT account,password FROM Users WHERE account = %1 AND password = %2").arg(user.getAccount()).arg(user.getPassword());
    sqlQuery.exec(queryCommand);
//    sqlQuery.exec(QString("SELECT * FROM Users"));
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
        return false;
    }
    else
    {
        if(queryRowCount(sqlQuery) <= 0) return false;
        while(sqlQuery.next())
        {
            QString account = sqlQuery.value(0).toString();
            QString password = sqlQuery.value(1).toString();
            qDebug()<<QString("account:%1    password:%2").arg(account).arg(password);
        }
    }
    return true;

}

bool SqliteHelper::openDatabase(QString databaseName){
    // 建立和SQlite数据库的连接
    database = QSqlDatabase::addDatabase("QSQLITE");
    // 设置数据库文件的名字
    database.setDatabaseName(databaseName);
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError() << endl;
        return false;
    }
    return true;
}

void SqliteHelper::closeDatabase() {
    database.close();
}

#endif // SQLITEHELPER_H

