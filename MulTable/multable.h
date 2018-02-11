#ifndef MULTABLE_H
#define MULTABLE_H

#include <QAbstractTableModel>

namespace Ui {
class MulTable;
}

class MulTable : public QAbstractTableModel
{
    Q_OBJECT

public:
     MulTable(int rows, int columns ,QWidget *parent = 0);
    ~MulTable();
     Qt::ItemFlags flags(const QModelIndex &index) const;
     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
     QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
     int rowCount(const QModelIndex &parent = QModelIndex()) const;
     int columnCount(const QModelIndex &parent = QModelIndex()) const;


private:
    Ui::MulTable *ui;
    int m_rows, m_columns;
};

#endif // MULTABLE_H
