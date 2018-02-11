#ifndef SINGLEITEMVIEW_H
#define SINGLEITEMVIEW_H

#include <QAbstractItemView>
#include <QtCore>
#include <QtGui>
#include <QLabel>

namespace Ui {
class SingleItemView;
}

class SingleItemView : public QAbstractItemView
{
    Q_OBJECT

public:
    explicit SingleItemView(QWidget *parent = 0);
    ~SingleItemView();
    QModelIndex indexAt(const QPoint &point) const;
    void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible);
    QRect visualRect(const QModelIndex &index) const;

protected:
    int horizontalOffset()const;
    bool isIndexHidden(const QModelIndex &index) const;
    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);
    void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags flags);
    int verticalOffset()const;
    QRegion visualRegionForSelection(const QItemSelection &selection) const;

protected slots:
    void dataChanged(const QModelIndex &topleft, const QModelIndex &buttonRight);
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

private:
    Ui::SingleItemView *ui;
    void updateText();
    QLabel *label;
};






#endif // SINGLEITEMVIEW_H
