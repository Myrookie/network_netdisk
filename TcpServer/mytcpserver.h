#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>


class mytcpserver : public QTcpServer
{
    Q_OBJECT
public:
    mytcpserver();

    //创建全局的对象,利用静态函数
    static mytcpserver &getNewServer();

    //查看是否有客户端连接
    void incomingConnection(qintptr socketDescriptor);

};

#endif // MYTCPSERVER_H
