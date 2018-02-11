#ifndef LISTWIDGETDIALOG_H
#define LISTWIDGETDIALOG_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QListWidget>
namespace Ui {
class ListWidgetDialog;
}

class ListWidgetDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ListWidgetDialog(QWidget *parent = 0);
    ~ListWidgetDialog();

private slots:
    void moveLeft();
    void moveRight();

private:
    Ui::ListWidgetDialog *ui;
    QGridLayout *layout;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QListWidget *leftList;
    QListWidget *rightList;
};

#endif // LISTWIDGETDIALOG_H
