#include "dialogdesign.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogDesign w;
    w.show();

    return a.exec();
}
