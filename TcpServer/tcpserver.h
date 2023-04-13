#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include "mytcpserver.h"



namespace Ui {
class tcpServer;
}

class tcpServer : public QWidget
{
    Q_OBJECT

public:
    explicit tcpServer(QWidget *parent = 0);
    void loadtxt();

    ~tcpServer();

private:
    Ui::tcpServer *ui;

    QString my_strIp;
    quint16 my_Port;

};

#endif // TCPSERVER_H
