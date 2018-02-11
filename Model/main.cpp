#include "model.h"
#include <QApplication>
#include <QTreeView>
#include <QTableView>
#include <QListView>
#include <QSplitter>
#include <QStandardItemModel>
#include <QAbstractItemView>
#include <QStringList>
#include <QStringListModel>
#include <QListView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Model w;

//    QListView list;
//    QStringListModel model;
//    QStringList strings;

//    strings << "Huey" << "Dewey" << "Louie";
//    model.setStringList(strings);
//    list.setModel(&model);
//    list.show();





    QTreeView *tree = new QTreeView;
    QListView *list = new QListView;
    QTableView *table = new QTableView;

    QSplitter split;
    split.addWidget(tree);
    split.addWidget(list);
    split.addWidget(table);


    QStandardItemModel model(5,2);
    for(int r = 0; r < 5; ++r)
        for(int c = 0; c < 2; ++c){
            QStandardItem *item
                    = new QStandardItem(QString("Row:%1, Column:%2").arg(r).arg(c));
            if(c == 0)
                for(int i = 0; i < 3; ++i)
                    item->appendRow(new QStandardItem(QString("Item:%1").arg(i)));

            model.setItem(r,c,item);
            model.setHorizontalHeaderItem(0, new QStandardItem("Name"));
            model.setHorizontalHeaderItem(1, new QStandardItem("Phone number"));
            tree->setModel(&model);
            list->setModel(&model);
            table->setModel(&model);

            list->setSelectionModel(tree->selectionModel());
           table->setSelectionModel(tree->selectionModel());

           // table->setSelectionBehavior(QAbstractItemView::SelectRows);
            table->setSelectionMode(QAbstractItemView::ContiguousSelection);


        }




   split.show();

    return a.exec();
}
