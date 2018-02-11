#ifndef WIDGETTEST_H
#define WIDGETTEST_H

#include <QWidget>
#include <QEvent>

namespace Ui {
class WidgetTest;
}

class WidgetTest : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTest(QWidget *parent = 0);
    ~WidgetTest();
signals:
    gotEvent(const QString &);
protected:
   void closeEvent(QCloseEvent *);
   void contextMenuEvent(QContextMenuEvent *event);
   void enterEvent(QEvent *);
   void focusInEvent(QFocusEvent *);
   void focusOutEvent(QFocusEvent *);
   void hideEvent(QHideEvent *);
   void keyPressEvent(QKeyEvent *);
   void keyReleaseEvent(QKeyEvent *);
   void moveEvent(QEvent *);
   void leaveEvent(QEvent *);
   void mouseDoubleClickEvent(QMouseEvent *);
   void mouseMoveEvent(QMouseEvent *);
   void mousePressEvent(QMouseEvent *);
   void mouseReleaseEvent(QMouseEvent *);
   void paintEvent(QPaintEvent *);
   void resizeEvent(QResizeEvent *);
   void showEvent(QShowEvent *);
   void wheelEvent(QWheelEvent *);


private:
    Ui::WidgetTest *ui;
};

#endif // WIDGETTEST_H
