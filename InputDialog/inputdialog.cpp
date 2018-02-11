#include "inputdialog.h"
#include "ui_inputdialog.h"
#include <QString>
#include <QLineEdit>
#include <QInputDialog>
#include <QStringList>
#include <QColorDialog>
#include <QFontDialog>
#include <QValidator>
#include <QRegExpValidator>
#include <QGridLayout>
#include <QLabel>
#include <QStyle>


InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);


    QGridLayout *layout = new QGridLayout(this);




    QLineEdit *intEdit = new QLineEdit("42");
    intEdit->setStyleSheet("background-color: yellow;");

    QLineEdit *doubleEdit = new QLineEdit("3.14");
    doubleEdit->setStyleSheet("background-color:blue;");
    QPushButton *button = new QPushButton("Close");
    button->setStyleSheet("background-color: grey;");


    layout->addWidget(new QLabel("Integer:"), 0,0);
    layout->addWidget(intEdit, 0,1);
    layout->addWidget(new QLabel("Double:"), 1,0);
    layout->addWidget(doubleEdit, 1,1);
    layout->addWidget(button, 2,0, 1,2);

    connect(button, SIGNAL(clicked(bool)), this, SLOT(accept()));















//    bool ok;
//    QFont font = QFontDialog::getFont(
//                &ok, QFont("Arial", 18),
//                this, tr("Pick a font"));

        
//    if(ok){

//    }






//    QColor color = QColorDialog::getColor(Qt::yellow, this);
//    if(color.isValid()){

//    }








//    bool ok;
//    QStringList items;
//    items << tr("Foo") << tr("Bar") << tr("Baz");
//    QString item = QInputDialog::getItem(
//                this,tr("Items"),
//                tr("Pick an Item"),
//                    items, 0 , true,
//                &ok);

//    if(ok && !item.isEmpty()){




//    }
}

InputDialog::~InputDialog()
{
    delete ui;
}
