#ifndef SINGLEDOCUMENT_H
#define SINGLEDOCUMENT_H

#include <QMainWindow>
#include <QTextEdit>
#include <QAction>
#include <QCloseEvent>
#include <QDockWidget>

namespace Ui {
class SingleDocument;
}

class SingleDocument : public QMainWindow
{
    Q_OBJECT

public:
    explicit SingleDocument(QWidget *parent = 0);
    ~SingleDocument();
private slots:

    void createActions();
    void createMenus();
    void createToolBars();
    void fileNew();
protected:
    void closeEvent(QCloseEvent *);
    bool isSafeToClose();
    void createDocks();




private:
    Ui::SingleDocument *ui;
    QTextEdit *docWidget;
    QDockWidget *dock;

    QAction *newAction;
    QAction *cutAction;
    QAction *aboutQtAction;
    QAction *closeAction;
    QAction *exitAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *aboutAction;

};

#endif // SINGLEDOCUMENT_H
