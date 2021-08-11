#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QPushButton>

#include "SqliteUtils/SqliteHelper.h"

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
    QString databaseName = "InfoSystem.db";
    SqliteHelper sqliteHelper;
    bool res = sqliteHelper.openDatabase(databaseName);
    if(res){
        sqliteHelper.closeDatabase();
        qDebug() << "finish" << endl;
    }
}
