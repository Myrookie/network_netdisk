#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QMessageBox>
#include <QStringList>
#include <QHostAddress>

TcpClient::TcpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    readIpProt();

    //将信号与槽函数联系起来
    connect(&my_tcpSocket, SIGNAL(connected()),this, SLOT(showConnect()));

    //连接服务器
    my_tcpSocket.connectToHost(QHostAddress(my_strIp), my_Port);


}

TcpClient::~TcpClient()
{
    delete ui;
}


void TcpClient::readIpProt(void)
{
    QFile file(":/client.txt");     //导入文件
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


void TcpClient::showConnect()
{
    QMessageBox::information(this, "连接服务器", "服务器连接成功");


}
