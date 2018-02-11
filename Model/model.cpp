#include "model.h"
#include "ui_model.h"

Model::Model(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Model)
{
    ui->setupUi(this);
}

Model::~Model()
{
    delete ui;
}
