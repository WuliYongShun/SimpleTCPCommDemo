#include"socketthread.h"
#include<QString>
#include<QByteArray>
#include<QDataStream>
#include<QMessageBox>
#include<QDebug>
#include"mytcpsocket.h"

socketThread::socketThread(QWidget *parent,qintptr p):QThread(parent)
{
    qDebug()<<"QThread构造函数依然在 旧线程";
    this->ptr=p;
}

void socketThread::run(){


    /*1.QObject->moveToThread(Thread *)会把一个Qt对象移动到一个新线程中运行 默认在run()中调用了 exec()这样 run()执行完后不会
     * 直接关闭 线程 还会让它 进入消息循环 直到调用了 结束 槽
     * 2.QtcpSocket 的write()函数是异步的 也就是 调用了 后不会立即 发送数据，它会直接往下执行 直到run()的尾部，如果run()没有
     * 调用exec()进行消息循环等待，那么 这个线程 直接就结束了，不会再发送。（发送数据失败）
     *3.如果在run()中调用了 exec()（发送成功）
     *4.如果在 write(QByteArray);后面加一句 socket->waitForBytesWritten()；这里就会阻塞等待 直到数据开始发送，这样
     * 不需要exec()在 线程结束之前直接就发送完了
     *socket->waitForConnected()
     * socket->waitForDisconnected()
     * socket->waitForReadyRead()都是一个道理
     */
    qDebug()<<"开始新线程";
   /* QTcpSocket * socket=new QTcpSocket();
    socket->setSocketDescriptor(this->ptr);
    QByteArray arr;
    QDataStream dts(&arr,QIODevice::WriteOnly);
    dts<<QString("这是数据");
    socket->write(arr);
    */
    mytcpsocket * socket=new mytcpsocket(0,this->ptr);
    socket->waitForBytesWritten();
  // this->exec();
    /*
1.  连接服务器
m_tcpSocket->connectToHost("127.0.0.1", 9877);
connected = m_tcpSocket->waitForConnected();
只有使用waitForConnected()后,QTcpSocket才真正尝试连接服务器，并返回是否连接的结果。
2. 写数据
m_tcpSocket->write(str.toStdString().c_str(), strlen(str.toStdString().c_str()));
m_tcpSocket->waitForBytesWritten();
当使用waitForBytesWritten()后，QTcpSocket才真正发送数据。
m_tcpSocket->write(str1.toStdString().c_str(), strlen(str1.toStdString().c_str()));
m_tcpSocket->write(str2.toStdString().c_str(), strlen(str2.toStdString().c_str()));
的结果是发送了str1str2
3. 断开与服务器的连接
m_tcpSocket->disconnectFromHost()
m_tcpSocket->waitForDisconnected()
4. 善于使用QTcpSocket的SIGNAL：connected(), disconnected(), error(QAbstractSocket::SocketError)
    配合自定义私有开关变量bool connected， QTimer
   可以实现自动重连接等逻辑。
      */
}

