#include "mainwindow.h"
#include <QApplication>
#include "ui_finddialog.h"
#include "ui_sortdialog.h"
#include <QTextEdit>
#include <QSplitter>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *win = new MainWindow;
    win->show();

    /*QTextEdit *edit1 = new QTextEdit;
    QTextEdit *edit2 = new QTextEdit;
    QTextEdit *edit3 = new QTextEdit;

    QSplitter splitter(Qt::Horizontal);
    splitter.addWidget(edit1);
    splitter.addWidget(edit2);
    splitter.addWidget(edit3);

    splitter.show();*/



    return app.exec();
}
