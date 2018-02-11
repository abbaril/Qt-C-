#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtCore>
namespace Ui {
class CustomWidget;
}

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomWidget(QWidget *parent = 0);
    ~CustomWidget();
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::CustomWidget *ui;
};

#endif // CUSTOMWIDGET_H
