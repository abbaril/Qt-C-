#include "sortdialog.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SortDialog *sortDialog = new SortDialog;
    sortDialog->setColumnRange('A', 'Z');
    sortDialog->show();


    return a.exec();
}
