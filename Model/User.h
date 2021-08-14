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
#endif // USER_H
