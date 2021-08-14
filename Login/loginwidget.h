#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    QString getUserName();
    ~LoginWidget();
signals:
    void login(); //登录主界面信号
    void close_window(); //关闭登录界面信号
    void set_title();


public slots:
    void pushbutton_login_clicked(); //登录按钮按下后触发的事件


private:
    Ui::LoginWidget *ui;
    QString userName;
};

#endif // LOGINWIDGET_H
