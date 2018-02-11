#include "intmodel.h"
#include <QApplication>
#include <QListView>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IntModel model(25);

    QListView list;
    list.setModel(&model);
    list.show();

    return a.exec();
}
