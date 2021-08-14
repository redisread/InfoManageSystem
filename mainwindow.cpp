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

//    this->initForm();
    // 设置标题
    this->setWindowTitle("信息管理系统");
    loginWidget = new LoginWidget();
    loginWidget->show();
    connect(loginWidget,SIGNAL(login()),this,SLOT(show()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

