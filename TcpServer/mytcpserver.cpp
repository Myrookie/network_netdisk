#include "mytcpserver.h"
#include <QDebug>

mytcpserver::mytcpserver()
{

}


mytcpserver &mytcpserver::getNewServer()
{
    static mytcpserver myserver;
    return myserver;
}


void mytcpserver::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "new client connected.";
}
