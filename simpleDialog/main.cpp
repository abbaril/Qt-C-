#include "simpledialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleDialog w;
    w.show();

    return a.exec();
}
