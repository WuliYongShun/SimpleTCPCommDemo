#ifndef SERVERMAINWINDOW_H
#define SERVERMAINWINDOW_H

#include <QMainWindow>

#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QMessageBox>

namespace Ui {
class ServerMainWindow;
}

class ServerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerMainWindow(QWidget *parent = 0);
    ~ServerMainWindow();

private:
    Ui::ServerMainWindow *ui;
    QTcpServer *tcpServer;
    QList<QTcpSocket*> tcpClient;
    QTcpSocket *currentClient;


private slots:
    void NewConnectionSlot();
    void disConnectedSlot();
    void ReadData();

    void on_btnSend_clicked();
    void on_btnClear_clicked();
    void on_btnConnect_clicked();
};

#endif // SERVERMAINWINDOW_H
