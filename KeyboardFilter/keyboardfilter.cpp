#include "keyboardfilter.h"
#include "ui_keyboardfilter.h"
#include <QKeyEvent>
KeyboardFilter::KeyboardFilter(QObject *parent) :
    QObject(parent),
    ui(new Ui::KeyboardFilter)
{
    //ui->setupUi(this);
}

KeyboardFilter::~KeyboardFilter()
{
    delete ui;
}


bool KeyboardFilter::eventFilter(QObject *dist, QEvent *event){

    if(event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        static QString digits = QString("1234567890");
        if(digits.indexOf(keyEvent->text()) != -1)
        return true;

}

    return QObject::eventFilter(dist, event );

}
