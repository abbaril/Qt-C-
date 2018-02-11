#include "keyboardfilter.h"
#include <QApplication>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLineEdit line;
    KeyboardFilter filter;

    line.installEventFilter(&filter);
    line.show();

    return app.exec();
}
