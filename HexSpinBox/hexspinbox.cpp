#include "hexspinbox.h"
#include "ui_hexspinbox.h"
#include <QtGui>
#include <QSpinBox>

HexSpinBox::HexSpinBox(QWidget *parent) :
    QSpinBox(parent)
    //ui(new Ui::HexSpinBox)
{
    //ui->setupUi(this);
    setRange(0, 255);
    validator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);
}



QValidator::State HexSpinBox::validate(QString &input, int &pos) const{
    return validator->validate(input, pos);
}

QString HexSpinBox::textFromValue(int val) const{
    return QString::number(val, 16).toUpper();

}


int HexSpinBox::valueFromText(const QString &text) const{
    bool ok;
    return text.toInt(&ok, 16);
}
