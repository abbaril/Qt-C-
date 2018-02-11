#include "dialogdesign.h"
#include "ui_dialogdesign.h"

DialogDesign::DialogDesign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDesign)
{
    ui->setupUi(this);
}

DialogDesign::~DialogDesign()
{
    delete ui;
}
