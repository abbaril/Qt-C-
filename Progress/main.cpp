#include "progress.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Progress w;
    w.show();

    return a.exec();
}
