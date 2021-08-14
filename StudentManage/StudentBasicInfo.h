#ifndef STUDENTBASICINFO_H
#define STUDENTBASICINFO_H

#include <QWidget>

namespace Ui {
class StudentBasicInfo;
}

class StudentBasicInfo : public QWidget
{
    Q_OBJECT

public:
    explicit StudentBasicInfo(QWidget *parent = nullptr);
    ~StudentBasicInfo();

private:
    Ui::StudentBasicInfo *ui;
};

#endif // STUDENTBASICINFO_H
