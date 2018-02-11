#include "phonebook.h"
#include "ui_phonebook.h"
#include "entry.h"
#include <QtGui>
#include <QStringList>
#include <QtCore>
#include <QFileDialog>


PhoneBook::PhoneBook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PhoneBook)
{
    ui->setupUi(this);

    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(addItem()));
    connect(ui->editButton, SIGNAL(clicked(bool)), this, SLOT(editItem()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteItem()));

}

PhoneBook::~PhoneBook()
{
    delete ui;
}


void PhoneBook::addItem(){


    Entry entery(this);
    if(entery.exec() == QDialog::Accepted)
        ui->list->addItem(entery.name() +" -- " + entery.number());





}

void PhoneBook::editItem(){

    if(!ui->list->currentItem())
        return;

    QStringList part = ui->list->currentItem()->text().split( " -- " );

    Entry entry(this);
    entry.setName(part[0].trimmed());
    entry.setNumber(part[1].trimmed());

    if(entry.exec() == QDialog::Accepted)
       ui->list->currentItem()->setText(entry.name()+ " -- " + entry.number());

}

void PhoneBook::deleteItem(){

   delete ui->list->currentItem();

}
