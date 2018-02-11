#include "multidocument.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MultiDocument w;
    w.show();

    return a.exec();
}
