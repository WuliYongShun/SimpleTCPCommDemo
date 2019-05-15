#include "mytcpclient.h"
#include "ui_mytcpclient.h"

MyTcpClient::MyTcpClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyTcpClient)
{
    ui->setupUi(this);

    tcpClient = new QTcpSocket(this);
    tcpClient->abort();
    ui->btnConnect->setEnabled(true);
    ui->btnSend->setEnabled(false);

    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(ReadData()));
    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)),\
            this,SLOT(ReadError(QAbstractSocket::SocketError)));
}

MyTcpClient::~MyTcpClient()
{
    delete ui;
}


/* 读取数据函数 */
void MyTcpClient::ReadData()
{
    //定义一个QByteArray类型的的buffer接收客户端的全部数据
    QByteArray buffer = tcpClient->readAll();
    //判断接收区是否有数据，如果有数据拼接字符，进行显示
    if(!buffer.isEmpty())
    {
        ui->edtRecv->append(buffer);
    }
}

/* 读取数据错误 */
void MyTcpClient::ReadDataError()
{
    tcpClient->disconnectFromHost();
    ui->btnConnect->setText(tr("连接"));
    QMessageBox msgBox;

    msgBox.setText(tr("failed to connect server because %1").arg(tcpClient->errorString()));
    msgBox.exec();
}

//连接按钮槽函数
void MyTcpClient::on_btnConnect_clicked()
{
    if(ui->btnConnect->text()=="连接")
    {
        //客户端连接主机，传入IP地址和端口号
        tcpClient->connectToHost(ui->edtIP->text(), ui->edtPort->text().toInt());

        if(tcpClient->waitForConnected())   //连接成功则进入if{}
        {
            ui->btnConnect->setText("断开");  //按钮显示“断开”
            ui->btnSend->setEnabled(true);  //按钮可以点击
        }

    }
    else
    {
        //客户端不连接主机
        tcpClient->disconnectFromHost();
        if(tcpClient->state() == QAbstractSocket::UnconnectedState\
                || tcpClient->waitForDisconnected(1000))    //判断是否断开连接，断开后进入if{}
        {
            ui->btnConnect->setText("连接");  //按钮显示“连接”
            ui->btnSend->setEnabled(false); //按钮不可以点击
        }

    }
}

//发送按钮槽函数
void MyTcpClient::on_btnSend_clicked()
{
    QString data = ui->edtSend->toPlainText(); //允许edtSend文本框输入
    //判断输入是否为空
    if(data != "")
    {
        tcpClient->write(data.toLatin1());
    }
}

//清除按钮槽函数
void MyTcpClient::on_btnClear_clicked()
{
    ui->edtRecv->clear();
}
