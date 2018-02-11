#include "singledocument.h"
#include <QApplication>
#include "infowidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SingleDocument w;

    w.show();

    return a.exec();
}
