#include "listwidgetdialog.h"
#include "ui_listwidgetdialog.h"

ListWidgetDialog::ListWidgetDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListWidgetDialog)
{
    ui->setupUi(this);

    leftButton = new QPushButton(this);
    rightButton = new QPushButton(this);


    layout = new QGridLayout(this);
    layout->addWidget( leftButton = new QPushButton("<<"), 0, 1 );
    layout->addWidget( rightButton = new QPushButton(">>"), 1,1 );
    layout->addWidget(leftList = new QListWidget, 0,0, 3,1);
    layout->addWidget(rightList = new QListWidget, 0,2 ,3,1);

    connect(leftButton, SIGNAL(clicked(bool)), this, SLOT(moveLeft()));
    connect(rightButton, SIGNAL(clicked(bool)), this, SLOT(moveRight()));


    QStringList items;
    items <<    "Nigerian"  << "Brazil"     << "South African" <<
                "USA West"  << "Monaco"     << "Belgian"    <<
                "Spanish"   << "Swedish"    << "British"    <<
                "German"    << "Austrina"   << "Dutch"      <<
                "Italian"   << "USA East"   << "Canadian"   <<
                "Kaduna"    << "Agetine";

    rightList->addItems(items);

}

ListWidgetDialog::~ListWidgetDialog()
{
    delete ui;
}



void ListWidgetDialog::moveRight(){
    if(leftList->selectedItems().count() != 1)
        return;

    QListWidgetItem *item = leftList->takeItem(leftList->currentRow());
    rightList->addItem(item);
}

void ListWidgetDialog::moveLeft(){
    if(rightList->selectedItems().count() != 1)
        return;

    QListWidgetItem *item = rightList->takeItem(rightList->currentRow());
    leftList->addItem(item);
}














