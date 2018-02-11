#ifndef CLOCKLABEL_H
#define CLOCKLABEL_H

#include <QLabel>

namespace Ui {
class ClockLabel;
}

class ClockLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClockLabel(QWidget *parent = 0);
    ~ClockLabel();
private slots:

    void updateTime();

private:
    Ui::ClockLabel *ui;
};

#endif // CLOCKLABEL_H
