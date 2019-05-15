#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QWidget>

class mytcpsocket;
class socketThread : public QThread
{
private:
    qintptr ptr;
    mytcpsocket * socket;

public:
    socketThread(QWidget * parent, qintptr p);

protected:
    virtual void run();
};

#endif // SOCKETTHREAD_H
