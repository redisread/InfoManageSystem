#ifndef SQLITEHELPER_H
#define SQLITEHELPER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>


class SqliteHelper {
private:
    QSqlDatabase database;// 用于建立和数据库的连接
public:
    SqliteHelper(){}
    bool openDatabase(QString DatabaseName);
    void closeDatabase();
};

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

