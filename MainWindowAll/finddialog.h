#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>

class QLabel;
class QCheckBox;
class QLineEdit;
class QPushButton;

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = 0);
    ~FindDialog();
signals:
   void findNext(const QString &str, Qt::CaseSensitivity cs);
   void findPrevious(const QString &str, Qt::CaseSensitivity cs);
private slots:
    void findClicked();
    void enabledFindButton(const QString &text);

public:
    Ui::FindDialog *ui;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox  *backWardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;

};

#endif // FINDDIALOG_H
