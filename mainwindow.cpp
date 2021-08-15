#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "iconhelper.h"
#include "qdebug.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuBar->setNativeMenuBar(false);

    this->studentManageItemPt = new StudentManageItem();
    this->studentManageItemPt->studentBasicInfo = new StudentBasicInfo();
    this->studentManageItemPt->studentBasicInfo->show();
    QList<QAction*> qActions = this->ui->menu_student_manage->actions();

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

