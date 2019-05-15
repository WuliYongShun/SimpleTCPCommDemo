#include"mytcpsocket.h"
#include<QByteArray>
#include<QDataStream>
#include<QString>
#include<QMessageBox>
#include<QDebug>

mytcpsocket::mytcpsocket(QWidget *parent,qintptr p):QTcpSocket(0)
{
//    this->setSocketDescriptor(p);
//    this->on_connected();
//    this->connect(this,SIGNAL(disconnected()),this,SLOT(on_discon()));
}

