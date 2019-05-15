#-------------------------------------------------
#
# Project created by QtCreator 2019-05-15T16:39:45
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThreadTcpServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myserver.cpp \
    mytcpsocket.cpp \
    socketthread.cpp

HEADERS  += mainwindow.h \
    myserver.h \
    mytcpsocket.h \
    socketthread.h

FORMS    += mainwindow.ui
