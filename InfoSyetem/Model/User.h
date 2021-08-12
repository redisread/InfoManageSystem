#ifndef USER_H
#define USER_H

#include <QString>

class User {
private:
    QString account;
    QString password;
public:
    User(){}
    User(QString account,QString password);
    QString getAccount();
    QString getPassword();
};

User::User(QString account,QString password)
{
    this->account = account;
    this->password = password;
}

QString User::getAccount(){
    return this->account;
}

QString User::getPassword(){
    return this->password;
}
#endif // USER_H
