#include "circlebar.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QSlider>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget base;
    QVBoxLayout *layout = new QVBoxLayout(&base);

    CircleBar *bar = new CircleBar;

    QSlider *slider = new QSlider(Qt::Horizontal);

    layout->addWidget(bar);
    layout->addWidget(slider);

    QObject::connect( slider, SIGNAL(valueChanged(int)), bar, SLOT(setValue(int)) );
    QObject::connect( bar, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)) );

    base.show();
    return app.exec();
}
