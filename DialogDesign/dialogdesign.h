#ifndef DIALOGDESIGN_H
#define DIALOGDESIGN_H

#include <QDialog>

namespace Ui {
class DialogDesign;
}

class DialogDesign : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDesign(QWidget *parent = 0);
    ~DialogDesign();

private:
    Ui::DialogDesign *ui;
};

#endif // DIALOGDESIGN_H
