#include "sortonsecondmodel.h"
#include <QApplication>
#include <QStringListModel>
#include <QStringList>
#include <QTableView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringListModel model;
    QStringList list;


    list << "Zainab" <<"Abba" << "Aisha" << "Ummi" << "Fatima" << "Amina";
    model.setStringList(list);

    SortOnSecondModel sorter;
    sorter.setSourceModel(&model);


    QTableView table;
    table.setModel(&sorter);

    table.setSortingEnabled(true);


    table.show();


    return a.exec();
}
