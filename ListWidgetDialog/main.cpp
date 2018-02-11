#include "listwidgetdialog.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ListWidgetDialog list;




    list.show();

    return app.exec();
}
