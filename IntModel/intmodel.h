#ifndef INTMODEL_H
#define INTMODEL_H

#include <QAbstractListModel>
#include <QtCore>
#include <QtGui>
namespace Ui {
class IntModel;
}

class IntModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit IntModel(int count,QObject *parent = 0);
    ~IntModel();
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

private:
    Ui::IntModel *ui;
    QList<int> m_values;

};

#endif // INTMODEL_H
