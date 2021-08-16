#ifndef STUDENTINFOUPDATEPAGE_H
#define STUDENTINFOUPDATEPAGE_H

#include <QWidget>

namespace Ui {
class StudentInfoUpdatePage;
}

class StudentInfoUpdatePage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentInfoUpdatePage(QWidget *parent = nullptr);
    ~StudentInfoUpdatePage();

private:
    Ui::StudentInfoUpdatePage *ui;
};

#endif // STUDENTINFOUPDATEPAGE_H
