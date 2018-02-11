#include "contactentry.h"
#include "ui_contactentry.h"

ContactEntry::ContactEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactEntry)
{
    ui->setupUi(this);
}

ContactEntry::~ContactEntry()
{
    delete ui;
}
