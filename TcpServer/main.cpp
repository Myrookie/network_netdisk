#include "tcpserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tcpServer w;
    w.show();

    return a.exec();
}
