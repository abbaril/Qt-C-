#include "intmodel.h"
#include "ui_intmodel.h"

IntModel::IntModel(int count, QObject *parent) : QAbstractListModel(parent),
    ui(new Ui::IntModel)
{
    //ui->setupUi(this);

    for(int i = 0; i < count; ++i)
        m_values << i +1;

}

IntModel::~IntModel()
{
    delete ui;
}


int IntModel::rowCount(const QModelIndex &parent) const{

    return m_values.count();
}

QVariant IntModel::data(const QModelIndex &index, int role) const{
    if(role != Qt::DisplayRole || role != Qt::EditRole)
        return QVariant();

    if(index.column() == 0 && index.row() < m_values.count())
        return m_values.at(index.row());
    else
        return QVariant();

}


Qt::ItemFlags IntModel::flags(const QModelIndex &index) const{
    if(!index.isValid())
        return Qt::ItemIsEnabled;

    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;


}

bool IntModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if(role != Qt::EditRole || index.column() != 0 || index.row() >= m_values.count())
        return false;
    if(value.toInt() ==  m_values.at(index.row()))
        return false;

    m_values[index.row()] = value.toInt();

    emit dataChanged(index, index);
    return true;

}





