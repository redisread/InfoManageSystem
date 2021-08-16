#include "StudentInfoUpdatePage.h"
#include "ui_StudentInfoUpdatePage.h"

StudentInfoUpdatePage::StudentInfoUpdatePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentInfoUpdatePage)
{
    ui->setupUi(this);
}

StudentInfoUpdatePage::~StudentInfoUpdatePage()
{
    delete ui;
}
