#include "gotocelldialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GotoCellDialog *gotoCell = new GotoCellDialog;
    gotoCell->show();

    return a.exec();
}
