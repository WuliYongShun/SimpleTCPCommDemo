#-------------------------------------------------
#
# Project created by QtCreator 2019-05-15T09:37:40
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServer
TEMPLATE = app


SOURCES += main.cpp\
        servermainwindow.cpp

HEADERS  += servermainwindow.h

FORMS    += servermainwindow.ui
