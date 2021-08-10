#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

void testSqlite();

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow *window = new MainWindow();
//    window->show();
    // 测试Sqlite数据库
    testSqlite();
//    return a.exec();
    return 0;
}

void testSqlite() {
    QSqlDatabase database;

    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        // 建立和SQlite数据库的连接
        database = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        database.setDatabaseName("MyDataBase.db");
        qDebug() << "cc" << endl;
    }

    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        qDebug() << "connect ok!" << endl;
    }


    //创建表格
    QSqlQuery sql_query;
    QString create_sql = "create table student (id int primary key, name varchar(30), age int)";
    sql_query.prepare(create_sql);
    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }
    database.close();
}
