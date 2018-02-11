#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QString>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str = "Hello World";
    qDebug() << str;

    return a.exec();
}
