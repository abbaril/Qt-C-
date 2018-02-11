#ifndef KEYBOARDFILTER_H
#define KEYBOARDFILTER_H

#include <QObject>

namespace Ui {
class KeyboardFilter;
}

class KeyboardFilter : public QObject
{
    Q_OBJECT

public:
    explicit KeyboardFilter(QObject *parent = 0);
    ~KeyboardFilter();
protected:
    bool eventFilter(QObject *dist, QEvent *event);

private:
    Ui::KeyboardFilter *ui;
};

#endif // KEYBOARDFILTER_H
