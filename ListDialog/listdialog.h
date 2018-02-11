#ifndef LISTDIALOG_H
#define LISTDIALOG_H

#include <QDialog>
#include "editdialog.h"
namespace Ui {
class ListDialog;
}

class ListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ListDialog(QWidget *parent = 0);
    ~ListDialog();

private slots:
    void addItem();
    void editItem();
    void deleteItem();


private:
    Ui::ListDialog *ui;

};

#endif // LISTDIALOG_H
