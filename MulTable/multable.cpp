#include "multable.h"
#include "ui_multable.h"

MulTable::MulTable(int rows, int columns, QWidget *parent) : QAbstractTableModel(parent),
    ui(new Ui::MulTable)
{
    //ui->setupUi(this);

    m_rows = rows;
    m_columns = columns;


}

MulTable::~MulTable()
{
    delete ui;
}

int MulTable::rowCount(const QModelIndex &parent) const{
    return m_rows;
}


int MulTable::columnCount(const QModelIndex &parent) const{
    return m_columns;
}

QVariant MulTable::data(const QModelIndex &index, int role) const{

    switch (role) {
    case Qt::DisplayRole:
        return (index.row()+1)* (index.column()+1);
        break;

    case Qt::ToolTip:
        return QString("%1 * %2").arg(index.row()+1).arg(index.column()+1);
    default:
        return QVariant();
        break;
    }
}


QVariant MulTable::headerData(int section, Qt::Orientation orientation, int role) const{
    if(role != Qt::DisplayRole)
        return QVariant();

    return section + 1;
}



Qt::ItemFlags MulTable::flags(const QModelIndex &index) const{

    if(!index.isValid())
        return Qt::ItemIsEnabled;
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}











