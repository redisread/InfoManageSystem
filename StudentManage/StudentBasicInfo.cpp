#include "StudentBasicInfo.h"
#include "ui_StudentBasicInfo.h"

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
