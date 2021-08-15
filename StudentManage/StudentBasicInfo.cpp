#include "StudentBasicInfo.h"
#include "ui_StudentBasicInfo.h"

// 代码里面添加动作了
StudentBasicInfo::StudentBasicInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentBasicInfo)
{
    ui->setupUi(this);
}

StudentBasicInfo::~StudentBasicInfo()
{
    delete ui;
}
