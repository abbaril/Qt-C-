#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = 0);
    ~EditDialog();

    const QString name() const;
    void setName( const QString& );


    const QString number() const;
    void setNumber( const QString& );

private:
    Ui::EditDialog *ui;
};

#endif // EDITDIALOG_H
