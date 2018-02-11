#include "simpledialog.h"
#include "ui_simpledialog.h"

SimpleDialog::SimpleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimpleDialog)
{
    ui->setupUi(this);
}

SimpleDialog::~SimpleDialog()
{
    delete ui;
}
