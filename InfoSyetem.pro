#-------------------------------------------------
#
# Project created by QtCreator 2021-08-07T12:52:54
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat
TARGET = InfoSyetem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    iconhelper.cpp \
    Model/Student.cpp \
    Model/Teacher.cpp \
    Model/User.cpp \
    DatabaseUtils/MysqlHelper.cpp \
    DatabaseUtils/SqliteHelper.cpp \
    Login/loginwidget.cpp \
    StudentManage/StudentManageItem.cpp \
    StudentManage/StudentBasicInfoPage.cpp

HEADERS += \
        mainwindow.h \
    iconhelper.h \
    Model/Student.h \
    Model/Teacher.h \
    Model/User.h \
    Config/DatabaseConfig.h \
    DatabaseUtils/MysqlHelper.h \
    DatabaseUtils/SqliteHelper.h \
    Login/loginwidget.h \
    StudentManage/StudentManageItem.h \
    StudentManage/StudentBasicInfoPage.h

FORMS += \
        mainwindow.ui \
    Login/loginwidget.ui \
    StudentManage/StudentBasicInfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DISTFILES += \
    sys.png
