#include "inputdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    InputDialog w;
    w.show();

    return app.exec();
}
