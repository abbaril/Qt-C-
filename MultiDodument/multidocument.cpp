#include "multidocument.h"
#include "ui_multidocument.h"

MultiDocument::MultiDocument(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MultiDocument)
{
    ui->setupUi(this);
}

MultiDocument::~MultiDocument()
{
    delete ui;
}
