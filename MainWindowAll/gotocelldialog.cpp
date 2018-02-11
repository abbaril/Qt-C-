#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QtGui>
#include <QRegExpValidator>

GotoCellDialog::GotoCellDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GotoCellDialog)
{
    ui->setupUi(this);
    QRegExpValidator *lineValidator = new QRegExpValidator(QRegExp("[A-Za-a][1-9][0-9]{0,2}"), this);
    ui->lineEdit->setValidator(lineValidator);

    connect(ui->okButton, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));


}

GotoCellDialog::~GotoCellDialog()
{
    delete ui;
}

void GotoCellDialog::on_lineEdit_textChanged(const QString &newValue)
{
    if(newValue == ""){
      ui->okButton->setEnabled(false);
    }else
        if(newValue != ""){
          ui->okButton->setEnabled(true);
          ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
    }
}
