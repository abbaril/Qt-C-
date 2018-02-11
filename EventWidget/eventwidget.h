#ifndef EVENTWIDGET_H
#define EVENTWIDGET_H

#include <QWidget>
#include <QEvent>

namespace Ui {
class EventWidget;
}

class EventWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EventWidget(QWidget *parent = 0);
    ~EventWidget();
signals:
    void gotEvent(const QString&);

 protected:
    void closeEvent(QCloseEvent *);
    void contextMenuEvent(QContextMenuEvent *event);
    //void enterEvent(QEvent *);
    //void focusInEvent(QFocusEvent *);
    //void focusOutEvent(QFocusEvent *);
    //void hideEvent(QHideEvent *);
    void keyPressEvent(QKeyEvent *);
    //void keyReleaseEvent(QKeyEvent *);
    //void moveEvent(QEvent *);
    //void leaveEvent(QEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
    //void mouseMoveEvent(QMouseEvent *);
    //void mousePressEvent(QMouseEvent *);
    //void mouseReleaseEvent(QMouseEvent *);
   // void paintEvent(QPaintEvent *);
    //void resizeEvent(QResizeEvent *);
    //void showEvent(QShowEvent *);
    void wheelEvent(QWheelEvent *);



private:
    Ui::EventWidget *ui;
};

#endif // EVENTWIDGET_H
