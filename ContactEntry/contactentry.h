#ifndef CONTACTENTRY_H
#define CONTACTENTRY_H

#include <QDialog>

namespace Ui {
class ContactEntry;
}

class ContactEntry : public QDialog
{
    Q_OBJECT

public:
    explicit ContactEntry(QWidget *parent = 0);
    ~ContactEntry();

private:
    Ui::ContactEntry *ui;
};

#endif // CONTACTENTRY_H
