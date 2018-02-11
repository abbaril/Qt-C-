#include "multable.h"
#include <QApplication>
#include <QTableView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MulTable multi(12,12);

    QTableView table;
    table.setModel(&multi);

    table.show();


    return a.exec();
}
