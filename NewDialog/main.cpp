#include "dialog.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDialog w;
    w.show();
    return app.exec();
}
