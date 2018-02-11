#ifndef NUMKEYPAD_H
#define NUMKEYPAD_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class NumKeyPad;
}

class NumKeyPad : public QWidget
{
    Q_OBJECT

public:
    explicit NumKeyPad(QWidget *parent = 0);
    ~NumKeyPad();
    const QString &text()const;

public slots:
    void setText(const QString &newText);

signals:
    void textChanged(const QString &newText);

private slots:
    void buttonClicked(const QString &newText);

private:
    Ui::NumKeyPad *ui;
    QLineEdit *lineEdit;
    QString  m_text ;

};

#endif // NUMKEYPAD_H
