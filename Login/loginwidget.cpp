#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "DatabaseUtils/MysqlHelper.h"
#include "Config/DatabaseConfig.h"
#include <QMessageBox>
LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    // 触发登录按钮的信号槽连接
    connect(ui->login_pushButton,SIGNAL(clicked()),this,SLOT(pushbutton_login_clicked()));
    // 关闭窗口的信号槽连接
    connect(this,SIGNAL(close_window()),this,SLOT(close()));

    // 设置密码输入不可见
    ui->password_lineEdit->setEchoMode(QLineEdit::Password);

    // 调试用
    ui->userName_lineEdit->setText("915");
    ui->password_lineEdit->setText("123456");
    this->setWindowTitle("登录界面");

}

LoginWidget::~LoginWidget()
{
    delete ui;
}


QString LoginWidget::getUserName(){
    return this->userName;
}

void LoginWidget::pushbutton_login_clicked()
{
    QString userName = ui->userName_lineEdit->text();
    QString password = ui->password_lineEdit->text();
    this->userName = userName;

    // 连接数据库
    MysqlHelper mysqlHelper(DatabaseConfig::HOST_NAME,DatabaseConfig::PORT,
                            DatabaseConfig::USER_NAME,DatabaseConfig::PASSWORD);
    bool ok = mysqlHelper.openDatabase(DatabaseConfig::DATABASE_NAME);
    if(!ok) {
        qWarning() << "数据库打开失败" << endl;
        QMessageBox::warning(this, "错误", mysqlHelper.getDatabase()->lastError().text());
    }

    bool isContainUser = mysqlHelper.containUser(User(userName,password));
    if(isContainUser) {
        // 发出登录信号
        emit(login());
        emit(set_title());
        // 发出关闭窗口信号
        emit(close_window());
        mysqlHelper.closeDatabase();
    }
    else {
        QMessageBox::information(this, "Warning","Username or Password is wrong !");
    }

}
