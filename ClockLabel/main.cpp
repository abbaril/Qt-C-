#include "clocklabel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ClockLabel clock;


    clock.show();

    return app.exec();
}
