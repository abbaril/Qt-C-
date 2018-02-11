#include "customwidget.h"
#include "ui_customwidget.h"
#include <QtGui>
#include <QtCore>

CustomWidget::CustomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomWidget)
{
    ui->setupUi(this);
}

CustomWidget::~CustomWidget()
{
    delete ui;
}


void CustomWidget::paintEvent(QPaintEvent *){
    //QPixmap pixmap(200,300);
    QPainter painter(this);

    QPen pen(Qt::black);


    painter.setPen(pen);


    //painter.drawRect(10,10, 85,35);
    //painter.drawRoundRect(10, 55, 85, 35);


    //QRect rect(105, 10, 85, 35);

    //painter.drawRoundRect(rect);
    //painter.drawRect(rect.translated(0,45));

    /*painter.drawEllipse(10, 10, 10, 80);
    painter.drawEllipse(30, 10, 20, 80);
    painter.drawEllipse(60, 10, 40, 80);
    painter.drawEllipse(QRect(110, 10, 100, 100));

    painter.drawArc(10, 100, 10, 80, 30*16, 240*16);
    painter.drawArc(30, 100, 20, 80, 45*16, 200*16);
    painter.drawArc(60, 100, 40, 80, 60*16, 160*16);
    painter.drawArc(QRect(110, 100, 80, 80), 75*16, 120*16);*/


    QPoint point (10,20);
    painter.drawText(point, "You can draw text from a point...");
    painter.drawLine(point + QPoint(-5, 0), point+QPoint(5, 0));
    painter.drawLine(point + QPoint(0, -5), point+QPoint(0, 5));

    QRect rect = QRect(10, 30, 180, 20);
    painter.drawText(rect, Qt::AlignCenter,
                     "....or you can draw it inside a rectangle...");
    rect.translate(0,30);
    painter.drawRect(rect);



    QFont font = QApplication::font();
    font.setPixelSize(rect.height());
    painter.setFont(font);

    painter.drawText(rect, Qt::AlignRight, "Right.");
    painter.drawText(rect, Qt::AlignLeft,  "Left.");
    painter.drawRect(rect);


    rect.translate(0, rect.height() + 10);
    rect.setHeight(QFontMetrics(font).height());

    painter.drawText(rect, Qt::AlignRight, "Right.");
    painter.drawText(rect, Qt::AlignLeft, "Left.");
    painter.drawRect(rect);


}










