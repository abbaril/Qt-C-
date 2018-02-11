#include "entry.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Entry w;
    w.show();

    return a.exec();
}
