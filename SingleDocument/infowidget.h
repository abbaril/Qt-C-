#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QLabel>

class InfoWidget : public QLabel
{
    Q_OBJECT
public:
    explicit InfoWidget(QWidget *parent = 0);

signals:

public slots:
    void documentChanged(int position, int charsRemoved ,int charsAdded);

};

#endif // INFOWIDGET_H
