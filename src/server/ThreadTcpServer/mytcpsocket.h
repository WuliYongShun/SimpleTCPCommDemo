#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QTcpSocket>


class mytcpsocket:public QTcpSocket
{
    Q_OBJECT
public:
    mytcpsocket(QWidget * parent,qintptr p);

private:
    void on_discon();

public:
    void on_connectd();
};

#endif // MYTCPSOCKET_H
