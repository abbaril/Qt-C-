#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>

namespace Ui {
class GotoCellDialog;
}

class GotoCellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GotoCellDialog(QWidget *parent = 0);
    ~GotoCellDialog();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

public:
    Ui::GotoCellDialog *ui;
};

#endif // GOTOCELLDIALOG_H
