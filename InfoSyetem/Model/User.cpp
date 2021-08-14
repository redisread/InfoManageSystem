#include "Model/User.h"

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
