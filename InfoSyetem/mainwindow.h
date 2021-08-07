#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

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

private slots:
    void initForm();
    void buttonClick();
private:
    Ui::MainWindow *ui;
    QList<NavButton *> btns;
};

#endif // MAINWINDOW_H
