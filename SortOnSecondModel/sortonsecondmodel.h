#ifndef SORTONSECONDMODEL_H
#define SORTONSECONDMODEL_H

#include <QSortFilterProxyModel>

namespace Ui {
class SortOnSecondModel;
}

class SortOnSecondModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit SortOnSecondModel(QObject *parent = 0);
    ~SortOnSecondModel();
protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;

private:
    Ui::SortOnSecondModel *ui;
};

#endif // SORTONSECONDMODEL_H
