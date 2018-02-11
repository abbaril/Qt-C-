#include "clocklabel.h"
#include "ui_clocklabel.h"
#include <QTimer>
#include <QTime>
#include <QDateTime>

ClockLabel::ClockLabel(QWidget *parent) :
    QLabel(parent),
    ui(new Ui::ClockLabel)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start();
    updateTime();
}

ClockLabel::~ClockLabel()
{
    delete ui;
}


void ClockLabel::updateTime(){
    setText(QTime::currentTime().toString("hh:mm:ss"));
}
