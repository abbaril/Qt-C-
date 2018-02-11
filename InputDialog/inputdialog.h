#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QValidator>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = 0);
    ~InputDialog();

private:
    Ui::InputDialog *ui;
    QDialog *dialog;


};

#endif // INPUTDIALOG_H
