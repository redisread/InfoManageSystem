#include "DatabaseUtils/mysqlhelper.h"

MysqlHelper::MysqlHelper()
{

}

MysqlHelper::~MysqlHelper()
{

}

MysqlHelper::MysqlHelper(QString hostName, int port, QString userName, QString password)
{
    this->database = QSqlDatabase::addDatabase("QMYSQL");
    this->database.setHostName(hostName);
    this->database.setPort(port);
    this->database.setUserName(userName);
    this->database.setPassword(password);
}

MysqlHelper& MysqlHelper::getMysqlHelper()
{
    static MysqlHelper mysqlHelper(DatabaseConfig::HOST_NAME,DatabaseConfig::PORT,
                       DatabaseConfig::USER_NAME,DatabaseConfig::PASSWORD);
    return mysqlHelper;
}

QSqlDatabase &MysqlHelper::getDatabase()
{
    return database;
}

bool MysqlHelper::openDatabase(){
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError() << endl;
        return false;
    }
    return true;
}

void MysqlHelper::closeDatabase() {
    database.close();
}

void MysqlHelper::setDatabaseName(QString databaseName)
{
    this->database.setDatabaseName(databaseName);
}

bool MysqlHelper::containUser(User user) {
    QSqlQuery sqlQuery;
    QString queryCommand = QString("SELECT account,password FROM %1 WHERE account = %2 AND password = %3").arg(DatabaseConfig::USER_TABLE_NAME).arg(user.getAccount()).arg(user.getPassword());
    sqlQuery.exec(queryCommand);
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
        return false;
    }

    if(sqlQuery.size() > 0)
        return true;
    return false;

}
