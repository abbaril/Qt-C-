#include "cell.h"
#include <QApplication>
#include "spreadsheet.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Spreadsheet spread;
    spread.show();



    return a.exec();
}
