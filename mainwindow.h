#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "Login/loginwidget.h"
#include "StudentManage/StudentManageItem.h"


class NavButton;

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void setTitle();

private slots:
    void on_action_student_info_process_triggered();

private:
    Ui::MainWindow *ui;
    LoginWidget *loginWidget;

    // 学籍管理模块界面
    StudentManageItem *studentManageItemPt;


    QString userName;
    //    QList<NavButton *> btns;
};

#endif // MAINWINDOW_H
