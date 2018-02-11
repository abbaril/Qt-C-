#ifndef OBJECTTREEMODEL_H
#define OBJECTTREEMODEL_H

#include <QAbstractItemModel>

namespace Ui {
class ObjectTreeModel;
}

class ObjectTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit ObjectTreeModel(QObject *root, QObject *parent = 0);
    ~ObjectTreeModel();

    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;


private:
    Ui::ObjectTreeModel *ui;
    QObject *m_root;
};

#endif // OBJECTTREEMODEL_H
