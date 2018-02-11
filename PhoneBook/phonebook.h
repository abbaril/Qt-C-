#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>

namespace Ui {
class PhoneBook;
}

class PhoneBook : public QMainWindow
{
    Q_OBJECT

public:
    explicit PhoneBook(QWidget *parent = 0);
    ~PhoneBook();
private slots:
    void addItem();
    void editItem();
    void deleteItem();

private:
    Ui::PhoneBook *ui;
};

#endif // PHONEBOOK_H
