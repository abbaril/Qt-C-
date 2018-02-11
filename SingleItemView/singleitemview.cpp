#include "singleitemview.h"
#include "ui_singleitemview.h"
#include <QtCore>
#include <QtGui>
#include <QGridLayout>
#include <QScrollBar>


SingleItemView::SingleItemView(QWidget *parent) :
    QAbstractItemView(parent),
    ui(new Ui::SingleItemView)
{
    ui->setupUi(this);
    QGridLayout *layout = new QGridLayout(this->viewport());
    label = new QLabel();

    layout->addWidget(label, 0,0);

    label->setAlignment(Qt::AlignCenter);
    label->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    label->setText(tr("<i>No data.</i>"));
}

SingleItemView::~SingleItemView()
{
    delete ui;
}


void SingleItemView::updateText(){
    switch(selectionModel()->selection().indexes().count()){
    case 0:
        label->setText(tr("<i>No dtat.</i>"));
        break;
    case 1:
        label->setText(model()->data(currentIndex()).toString());
        break;
    default:
        label->setText(tr("<i>Too many items selected.<br>"
                          "Can only show one item at a time</i>"));
        break;

    }
}

QRect SingleItemView::visualRect(const QModelIndex &index) const{
    if(selectionModel()->selection().indexes().count() != 1)
        return QRect();

    if(currentIndex() != index)
        return QRect();

    return QRect();
}

int SingleItemView::horizontalOffset()const{
    return horizontalScrollBar()->value();
}


int SingleItemView::verticalOffset()const{
    return verticalScrollBar()->value();
}


QModelIndex SingleItemView::moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers){
    return currentIndex();
}


void SingleItemView::setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags flags){
    //do nothing
}

void SingleItemView::scrollTo(const QModelIndex &index, ScrollHint hint){
    //cannot scroll
}

void SingleItemView::dataChanged(const QModelIndex &topleft, const QModelIndex &buttonRight){
    updateText();
}

void SingleItemView::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected){
    updateText();
}
