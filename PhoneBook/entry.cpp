#include "entry.h"
#include "ui_entry.h"

Entry::Entry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Entry)
{
    ui->setupUi(this);
}

Entry::~Entry()
{
    delete ui;
}


void Entry::setName(const QString &name){
    ui->nameEdit->setText(name);
}

const QString Entry::name()const{
    return ui->nameEdit->text().replace("--", " ").trimmed();
}


void Entry::setNumber(const QString &number){
    ui->numEdit->setText(number);
}

const QString Entry::number()const{
    return ui->numEdit->text().replace("--", " ").trimmed();
}
