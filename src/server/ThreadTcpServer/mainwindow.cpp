#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myserver.h"
#include <QHostAddress>
#include <QTcpServer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->server = new myserver(this);
//    this->server->listen(QHostAddress::LocalHost,520);
}

MainWindow::~MainWindow()
{
    delete ui;
}
