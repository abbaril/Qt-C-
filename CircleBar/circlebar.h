#ifndef CIRCLEBAR_H
#define CIRCLEBAR_H

#include <QWidget>

namespace Ui {
class CircleBar;
}

class  CircleBar : public QWidget
{
    Q_OBJECT

public:

    explicit CircleBar(int value = 0, QWidget *parent = 0);
    ~CircleBar();
    int value()const;
    int heightForWidth(int) const;
    QSize sizeHint()const;


public slots:
    void setValue(int);
signals:
    void valueChanged(int);
protected:
    void paintEvent(QPaintEvent *);
    void wheelEvent(QWheelEvent *);
    void text();
private:
    Ui::CircleBar *ui;
    int m_value;
};

#endif // CIRCLEBAR_H
