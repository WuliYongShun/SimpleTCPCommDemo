#include "myserver.h"
#include <QMessageBox>
#include "mytcpsocket.h"
#include "socketthread.h"

//myserver::myserver(QWidget * parent):QTcpServer(parent)
//{

//}

void myserver::incomingConnection(qintptr socketDescriptor)
{
    QMessageBox::about(0,"提示","有新连接");
/*    socketthread * thread=new socketThread(0,socketDescriptor);
    thread->start()*/;
}



