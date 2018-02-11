#include "objecttreemodel.h"
#include <QApplication>
#include <QTreeView>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QObject root;

    root.setObjectName("root");
    QObject *child;
    QObject *foo = new QObject(&root);

    foo->setObjectName("foo");
    child = new QObject(foo);
    child->setObjectName("Mark");
    child = new QObject(foo);
    child->setObjectName("Bob");
    child = new QObject(foo);
    child->setObjectName("Kent");

    QObject *bar = new QObject(&root);
    bar->setObjectName("bar");
    child = new QObject(bar);
    child->setObjectName("Abba");
    child = new QObject(bar);
    child->setObjectName("Aisha");

    ObjectTreeModel model(&root);


    QTreeView tree;
    tree.setModel(&model);
    tree.show();




    return app.exec();
}
