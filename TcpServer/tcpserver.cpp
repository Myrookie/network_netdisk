#include "tcpserver.h"
#include "ui_tcpserver.h"

#include <QMessageBox>
#include <QStringList>
#include <QHostAddress>
#include <QFile>
#include <QDebug>

tcpServer::tcpServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tcpServer)
{
    ui->setupUi(this);
    loadtxt();      //获取IP和port

    mytcpserver::getNewServer().listen(QHostAddress(my_strIp), my_Port);        //对客户端进行监听，看是否有客户端连接

}

tcpServer::~tcpServer()
{
    delete ui;
}


void tcpServer::loadtxt()
{

    QFile file(":/server.txt");     //导入文件
    if(file.open(QIODevice::ReadOnly))  //打开文件
    {
        QByteArray baData = file.readAll();     //读取文件所有内容
        QString strData = baData.toStdString().c_str();     //将读取出来的内容转换成QString字符串格式


        file.close();           //关闭文件

        strData.replace("\n", " ");         //将文件内的换行符换成空格

        QStringList strlist =  strData.split(" ");          //以空格为界拆分ip和port

        my_strIp = strlist.at(0);           //给ip赋值
        my_Port = strlist.at(1).toUShort();         //将port转换成短整形赋值
        //qDebug() << "ip: " <<my_strIp << "port: " << my_Port;

    }
    else
    {
        QMessageBox::critical(this, "打开资源文件","打开资源文件失败");           //打开失败跳出提示框
    }
}
