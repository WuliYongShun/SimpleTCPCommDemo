#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QWidget>

class myserver
{
public:
    myserver(QWidget *parent);

protected:
    virtual void incomingConnection(qintptr socketDescriptor);

};

#endif // MYSERVER_H
