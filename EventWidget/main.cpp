#include "eventwidget.h"
#include <QApplication>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextEdit log;
    EventWidget widget;

    QObject::connect(&widget, SIGNAL(gotEvent(const QString&)), &log, SLOT(append(const QString&)));

    log.show();
    widget.show();

    return a.exec();
}
