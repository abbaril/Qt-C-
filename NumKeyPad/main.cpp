#include "numkeypad.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget widget;

    QVBoxLayout *layout = new QVBoxLayout(&widget);
    NumKeyPad pad;


    layout->addWidget(&pad);

    QLabel *label = new QLabel;
    layout->addWidget(label);

    QObject::connect(&pad, SIGNAL(textChanged(const QString&)), label, SLOT(setText(const QString&)));

    widget.setWindowTitle("composed");
    widget.show();

    return a.exec();
}
