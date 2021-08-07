#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel *label = new QLabel("<h2><font color='red'>Hello</font>, world!<h2>");
    label->show();
    return a.exec();
}
