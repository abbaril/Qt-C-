#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QLabel>

#include "sortdialog.h"
#include "finddialog.h"
#include "spreadsheet.h"
#include "gotocelldialog.h"

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);

private slots:

    void newFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void gotoCell();
    void sort();
    void about();
    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModified();


private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool okTocontinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);


    Spreadsheet *spreadsheet;
    GotoCellDialog *dialog;
    FindDialog *findDialog;
    SortDialog *sortDialog;
    QLabel *locationLabel;
    QLabel *formulaLabel;
    QStringList recentFiles;
    QString curFile;


    enum{ MaxRecentFiles = 5 };
    QAction *recentFilesActions[MaxRecentFiles];
    QAction *separatorAction;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *selectSubMenu;
    QMenu *toolsMenu;
    QMenu *optionsMenu;
    QMenu *helpMenu;


    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    QAction *newAction;
    QAction *openAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
    QAction *exitAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;
    QAction *selectRowAction;
    QAction *selectColumnAction;
    QAction *goToCellAction;
    QAction *findAction;
    QAction *recalculateAction;
    QAction *sortAction;
    QAction *autoRecalcAction;
    QAction *selectAllAction;
    QAction *showGridAction;

};

#endif // MAINWINDOW_H
