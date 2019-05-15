#include "servermainwindow.h"
#include "ui_servermainwindow.h"

ServerMainWindow::ServerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerMainWindow)
{
    ui->setupUi(this);

//    tcpServer = new QTcpServer(this);
//    ui->edtIP->setText(QNetworkInterface().allAddresses().at(1).toString());   //获取本地IP
//    ui->btnConnect->setEnabled(true);
//    ui->btnSend->setEnabled(false);

//    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(NewConnectionSlot()));

    tcpServer = new QTcpServer(this);
    ui->edtIP->setText(QNetworkInterface().allAddresses().at(1).toString());    //获取本地IP
    ui->btnConnect->setEnabled(true);   //监听按钮默认可以点击
    ui->btnSend->setEnabled(false); //发送按键默认不可以点击

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(NewConnectionSlot()));
}

ServerMainWindow::~ServerMainWindow()
{
    delete ui;
}

// newConnection -> newConnectionSlot 新连接建立的槽函数
void MyTcpServer::NewConnectionSlot()
{
    currentClient = tcpServer->nextPendingConnection();
    tcpClient.append(currentClient);
    ui->cbxConnection->addItem(tr("%1:%2").arg(currentClient->peerAddress().toString().split("::ffff:")[1])\
                                          .arg(currentClient->peerPort()));
    connect(currentClient, SIGNAL(readyRead()), this, SLOT(ReadData()));
    connect(currentClient, SIGNAL(disconnected()), this, SLOT(disconnectedSlot()));
}
//NewConnecton -> newConnectonSlot 新连接建立的槽函数
void ServerMainWindow::NewConnectionSlot()
{
    currentClient = tcpServer->nextPendingConnection(); //获取连接上的套接字对象，得到客户端的套接号
    tcpClient.append(currentClient);
    ui->cbxConnection->addItem(tr("%1:%2").arg(currentClient->peerAddress().toString()));
}

void ServerMainWindow::disConnectedSlot()
{

}

void ServerMainWindow::ReadData()
{

}
