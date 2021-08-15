#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QPushButton>

#include "DatabaseUtils/SqliteHelper.h"
//#include "DatabaseUtils/MysqlHelper.h"
#include "Config/DatabaseConfig.h"

void testSqlite();
void testMySQL();

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        MainWindow *window = new MainWindow();
    //    window->show();
    // 测试Sqlite数据库
    //    testSqlite();
//    testMySQL();
        return a.exec();
//    return 0;
}


void testMySQL() {
//    MysqlHelper mysqlHelper(DatabaseConfig::HOST_NAME,DatabaseConfig::PORT,
//                            DatabaseConfig::USER_NAME,DatabaseConfig::PASSWORD);
//    //连接sql服务器
//    bool r = mysqlHelper.openDatabase();
//    if(r) {
//        qDebug() << "Connect ok" << endl;
//        bool h = mysqlHelper.containUser(User("915","123456"));
//        if(h) {
//            qDebug() << "has User " << endl;
//        }
////        QSqlQuery query;
////        query.exec("select account,password from User where account=915 and password=123456");
////        qDebug() << query.size()<< endl;
////        while (true == query.next()) {  //一行一行遍历
////            //取出当前行的内容，以列为单位
////            qDebug() << query.value(0).toString()  //取第一列
////                     << query.value(1).toString() //取第二列
////                     << query.value("account").toString()  //按名字查找
////                     << query.value("password").toString();
////        }
//        mysqlHelper.closeDatabase();
//    }else{
////        QMessageBox::warning(this, "错误", db.lastError().text());
//        qDebug() << "Error" << endl;
//    }

}


void testSqlite() {
    QString databaseName = "InfoSystem.db";
    SqliteHelper sqliteHelper;
    bool res = sqliteHelper.openDatabase(databaseName);
    if(res){
        bool rr = sqliteHelper.containUser(User("915","123456"));
        if(rr) {
            qDebug() << "OK" << endl;
        }

        sqliteHelper.closeDatabase();
        qDebug() << "finish" << endl;
    }
}
