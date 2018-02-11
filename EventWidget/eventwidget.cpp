#include "eventwidget.h"
#include "ui_eventwidget.h"
#include <QKeyEvent>

EventWidget::EventWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EventWidget)
{
    ui->setupUi(this);
}

EventWidget::~EventWidget()
{
    delete ui;
}

void EventWidget::closeEvent(QCloseEvent */*event*/){
    emit gotEvent(tr("CloseEvent"));
}


void EventWidget::keyPressEvent(QKeyEvent *event){

    emit gotEvent(QString("KeyPressEvent(text:%1, modifiers:%2)")
                  .arg(event->text())
                  .arg(event->modifiers() == 0? tr("NoModifier"):(
                   (event->modifiers() & Qt::ShiftModifier == 0? tr(" "):
                     tr("ShiftModofier")) +
                   (event->modifiers() & Qt::ControlModifier == 0? tr(" "):
                     tr("ControlModifier")) +
                   (event->modifiers() & Qt::AltModifier == 0? tr(" "):
                     tr("AltModifier")) +
                   (event->modifiers() & Qt::MetaModifier == 0? tr(" "):
                     tr("MetaModifier")) +
                   (event->modifiers() & Qt::KeypadModifier == 0? tr(" "):
                     tr("KeyPadModifier")) +
                   (event->modifiers() & Qt::GroupSwitchModifier == 0? tr(""):
                     tr("Groupswitchmodifier") ))));


}


void EventWidget::contextMenuEvent(QContextMenuEvent *event){
    emit gotEvent(QString("contectMenuEvent(x:%1, y:%2, reason:%3)")
                  .arg(event->x())
                  .arg(event->y())
                  .arg(event->reason() == QContextMenuEvent::Other ? "Other":
                       event->reason() == QContextMenuEvent::Keyboard ? "Keyboard" : "Mouse"));
}


void EventWidget::mouseDoubleClickEvent(QMouseEvent *event){
    emit gotEvent(QString("mouseDoubleClikcedEvent(x:%1, y:%2, button:%3)")
                  .arg(event->x())
                  .arg(event->y())
                  .arg(event->button() == Qt::LeftButton ? "LeftButton" :
                       event->button() == Qt::RightButton ? "RightButton" :
                       event->button() == Qt::MidButton ? "MidButton" :
                       event->button() == Qt::XButton1 ? "XButton1" : "XButton2"));
}



void EventWidget::wheelEvent(QWheelEvent *event){
    emit gotEvent(QString("wheelEvent(x:%1, y:%2, delta:%3, orientation:%4)")
                  .arg(event->x())
                  .arg(event->y())
                  .arg(event->delta()).arg(event->orientation() == Qt::Horizontal ?
                                               "Horizontal" : "Vertical"));

}










