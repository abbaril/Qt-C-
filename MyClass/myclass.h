#ifndef MYCLASS_H
#define MYCLASS_H

#include <QWidget>

namespace Ui {
class MyClass;
}

class MyClass : public QWidget
{
    Q_OBJECT

public:
    explicit MyClass(QWidget *parent = 0);
    ~MyClass();

private:
    Ui::MyClass *ui;
};

#endif // MYCLASS_H
