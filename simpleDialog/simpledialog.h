#ifndef SIMPLEDIALOG_H
#define SIMPLEDIALOG_H

#include <QDialog>

namespace Ui {
class SimpleDialog;
}

class SimpleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SimpleDialog(QWidget *parent = 0);
    ~SimpleDialog();

private:
    Ui::SimpleDialog *ui;
};

#endif // SIMPLEDIALOG_H
