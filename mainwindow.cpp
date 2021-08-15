#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
//#include "iconhelper.h"
#include "qdebug.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuBar->setNativeMenuBar(false);

    this->studentManageItemPt = new StudentManageItem();
//    this->studentManageItemPt->studentBasicInfo = new StudentBasicInfo();

    //    this->initForm();
    // 设置标题
    this->setWindowTitle("信息管理系统");
    loginWidget = new LoginWidget();
    loginWidget->show();
    connect(loginWidget,SIGNAL(login()),this,SLOT(show()));
    connect(loginWidget,SIGNAL(set_title()),this,SLOT(setTitle()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTitle()
{
    this->setWindowTitle(loginWidget->getUserName());
}


/*************************学籍管理Action函数**********************/

/**
 * 打开学籍处理页面
 */
void MainWindow::on_action_student_info_process_triggered()
{
    if(this->studentManageItemPt->studentBasicInfo == nullptr) {
        this->studentManageItemPt->studentBasicInfo = new StudentBasicInfo();
        qDebug() << "init" << endl;
    }
    this->studentManageItemPt->studentBasicInfo->show();
//    QMessageBox::information(this, "Warning","Username or Password is wrong !");
}
