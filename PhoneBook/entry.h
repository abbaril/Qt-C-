#ifndef ENTRY_H
#define ENTRY_H

#include <QDialog>

namespace Ui {
class Entry;
}

class Entry : public QDialog
{
    Q_OBJECT

public:
    explicit Entry(QWidget *parent = 0);
    ~Entry();
    void setName(const QString &);
    const QString name()const;

    void setNumber(const QString &);
    const QString number()const;

private:
    Ui::Entry *ui;
};

#endif // ENTRY_H
