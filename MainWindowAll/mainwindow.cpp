#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_finddialog.h"
#include "ui_gotocelldialog.h"
#include "ui_sortdialog.h"


#include "sortdialog.h"
#include "gotocelldialog.h"
#include "spreadsheet.h"
#include "finddialog.h"

#include <QtGui>
#include <QMainWindow>
#include <QAction>
#include <QTableWidget>
#include <QTableView>
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include <QObject>
#include <QLineEdit>
#include <QIcon>





class SpreadsheetCompare;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);



    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();
    //writeSettings();


    readSettings();

    findDialog = 0;

    setWindowIcon(QIcon(":/images/abba.png"));
    setCurrentFile("");
}

MainWindow::~MainWindow()
{
    delete ui;
}


//createActions function Implementation

void MainWindow::createActions(){

    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/images/icon.jpeg"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create new Spreadsheet file"));
    connect(newAction, SIGNAL(triggered(bool)),
            this, SLOT(newFile()));



    openAction = new QAction(tr("&open"), this);
    openAction->setIcon(QIcon(":/images/icon.jpg"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setToolTip(tr("Open"));
    connect(openAction, SIGNAL(triggered(bool)),
            this, SLOT(open()));



    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/images/icon.jpg"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setToolTip(tr("Save"));
    connect(saveAction, SIGNAL(triggered(bool)),
           this, SLOT(save()));


    saveAsAction = new QAction(tr("Save &As"), this);
    saveAsAction->setIcon(QIcon(":/images/icon.jpg"));
    saveAction->setShortcut(QKeySequence::SaveAs);
    saveAction->setToolTip(tr("SaveAs"));
    connect(saveAsAction, SIGNAL(triggered(bool)),
            this, SLOT(saveAs()));








    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/images/icon.jpg"));
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setToolTip(tr("cut"));
    connect(cutAction, SIGNAL(triggered(bool)),
            spreadsheet,SLOT(cut()));

    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setIcon(QIcon(":/images/icon.jpg"));
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setToolTip(tr("Copy"));
    connect(copyAction, SIGNAL(triggered(bool)),
            spreadsheet, SLOT(copy()));


    pasteAction = new QAction(tr("&paste"), this);
    pasteAction->setIcon(QIcon(":/images/icon.jpg"));
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setToolTip("paste");
    connect(pasteAction, SIGNAL(triggered(bool)),
            spreadsheet, SLOT(paste()));


    deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setShortcut(QKeySequence::Delete);
    deleteAction->setToolTip(tr("Del"));
    connect(deleteAction, SIGNAL(triggered(bool)),
            spreadsheet, SLOT(del()));

    selectAllAction = new QAction(this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setToolTip(tr("Select All"));
    connect(selectAllAction, SIGNAL(triggered(bool)),
            spreadsheet, SLOT(selectAll()));

    selectRowAction = new QAction(tr("&Row"), this);
    connect(selectRowAction, SIGNAL(triggered(bool)),
            spreadsheet, SLOT(selectCurrentRow()));

    selectColumnAction = new QAction(tr("&Column"), this);
    connect(selectColumnAction, SIGNAL(triggered(bool)),
            spreadsheet, SLOT(selectCurrentColumn()));

    goToCellAction = new QAction(tr("&Go to Cell"), this);
    goToCellAction->setIcon(QIcon(":/images/goto.png"));
    goToCellAction->setShortcut(QKeySequence::SelectNextPage);
    goToCellAction->setToolTip(tr("Go to cell"));
    connect(goToCellAction, SIGNAL(triggered(bool)),
            this, SLOT(gotoCell()));

    findAction = new QAction(tr("&Find"), this);
    findAction->setIcon(QIcon(":/images/find.png"));
    findAction->setShortcut(QKeySequence::Find);
    findAction->setToolTip(tr("Find"));
    connect(findAction, SIGNAL(triggered(bool)),
            this, SLOT(find()));


    recalculateAction = new QAction(tr("&Recalculate"), this);
    recalculateAction->setShortcut(QKeySequence::WhatsThis);
    connect(recalculateAction, SIGNAL(toggled(bool)),
            spreadsheet, SLOT(recalculate()));

    autoRecalcAction = new QAction(tr("&Auto-Recalculate"), this);
    autoRecalcAction->setCheckable(true);
    connect(autoRecalcAction, SIGNAL(triggered(bool)),
            spreadsheet, SLOT(setAutoRecalculate(bool)));

    sortAction = new QAction(tr("&Sort..."), this);
    connect(sortAction, SIGNAL(triggered(bool)),
            this , SLOT(sort()));





    for(int i = 0; i<MaxRecentFiles; ++i){
        recentFilesActions[i] = new QAction(this);
        recentFilesActions[i]->setVisible(false);
        connect(recentFilesActions[i], SIGNAL(triggered(bool)),
                this,SLOT(openRecentFile()));
    }

    exitAction = new QAction(tr("&Exit"),this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered(bool)),
                this, SLOT(close()));


    selectAllAction = new QAction(tr("&All"), this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
    connect(selectAllAction, SIGNAL(triggered(bool)),
                   spreadsheet, SLOT(selectAll()));


    showGridAction = new QAction(tr("&Show Grid"), this);
    showGridAction->setCheckable(true);
    showGridAction->setChecked(spreadsheet->showGrid());
    showGridAction->setStatusTip(tr("Show or hide the spreadsheet`s greed"));
    connect(showGridAction, SIGNAL(toggled(bool)),
                this,SLOT(showNormal()));


    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the Qt`s library about box"));
    connect(aboutAction, SIGNAL(triggered(bool)),
            this, SLOT(about()));



    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt`s library about box"));
    connect(aboutQtAction, SIGNAL(triggered(bool)),
           qApp, SLOT(aboutQt()));



}


//createMenus function Implementation
void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction = fileMenu->addSeparator();
    for(int i = 0; i < MaxRecentFiles; ++i)
        fileMenu->addAction(recentFilesActions[i]);
        fileMenu->addSeparator();
        fileMenu->addAction(exitAction);

        editMenu = menuBar()->addMenu(tr("&Edit"));
        editMenu->addAction(cutAction);
        editMenu->addAction(copyAction);
        editMenu->addAction(pasteAction);
        editMenu->addAction(deleteAction);


        selectSubMenu = menuBar()->addMenu(tr("&Select"));
        selectSubMenu->addAction(selectRowAction);
        selectSubMenu->addAction(selectColumnAction);
        selectSubMenu->addAction(selectAllAction);

        editMenu->addSeparator();
        editMenu->addAction(findAction);
        editMenu->addAction(goToCellAction);


        toolsMenu = menuBar()->addMenu(tr("&Tools"));
        toolsMenu->addAction(recalculateAction);
        toolsMenu->addAction(sortAction);

        optionsMenu = menuBar()->addMenu(tr("&Options"));
        optionsMenu->addAction(showGridAction);
        optionsMenu->addAction(autoRecalcAction);

        menuBar()->addSeparator();

        helpMenu = menuBar()->addMenu(tr("&Help"));
        helpMenu->addAction(aboutAction);
        helpMenu->addAction(aboutQtAction);


}

//createContextAction function Implementation


void MainWindow::createContextMenu(){
    spreadsheet->addAction(cutAction);
    spreadsheet->addAction(copyAction);
    spreadsheet->addAction(pasteAction);

    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);

}

//createToolBar function Implementation

void MainWindow::createToolBars(){
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);


    editToolBar = addToolBar(tr("&Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);

    editToolBar->addSeparator();

    editToolBar->addAction(findAction);
    editToolBar->addAction(goToCellAction);

}


//createStatusBar function Implementation

void MainWindow::createStatusBar(){
    locationLabel = new QLabel(" W999 ");
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel, 1);



    connect(spreadsheet, SIGNAL(currentCellChanged(int, int , int, int)),
                        this, SLOT(updateStatusBar()));
    connect(spreadsheet, SIGNAL(modified()), this, SLOT(spreadsheetModified()));

    updateStatusBar();
}

//updateStatusBar function Implementation

//Correction Caller
void MainWindow::updateStatusBar(){
    locationLabel->setText(spreadsheet->currentLocation());
    formulaLabel->setText(spreadsheet->currentFormula());
}


//spreadsheetModified function Implementation


void MainWindow::spreadsheetModified(){
    setWindowModified(true);
    updateStatusBar();
}




/*Implementing the File Menu*/

//newFile Slot Implementation
//Correction Caller
void MainWindow::newFile(){
    MainWindow *mainwin = new MainWindow;
    mainwin->show();
    if(okTocontinue()){
        spreadsheet->clear();
        setCurrentFile(" ");
    }
}




//okToContinue function Implementation


bool MainWindow::okTocontinue(){
    if(isWindowModified()){
        int r = QMessageBox::warning(this,tr("spreadsheet"),
                                     tr("The document has been modified.\n"
                                        "Do you want to save changes?"),
                                     QMessageBox::Yes | QMessageBox::No
                                     | QMessageBox::Cancel);
        if(r == QMessageBox::Yes){
            return save();
        }else if(r == QMessageBox::Cancel){
            return false;
        }

    }
    return true;
}



//open slot Implementation

void MainWindow::open(){
    if(okTocontinue()){
        QString fileName = QFileDialog::getOpenFileName(this,tr("Open Spreadsheet"), ".",
                                                        tr("Spreadsheet files (*sp)"));
        if(!fileName.isEmpty())
            loadFile(fileName);
    }
}


//openFile function Implementation

bool MainWindow::loadFile(const QString &fileName){
    if(!spreadsheet->readFile(fileName)){
        statusBar()->showMessage(tr("Load canceled"), 2000);
        return false;
    }
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("file loaded"), 2000);
    return true;
}



//save slot Implementation

bool MainWindow::save(){
    if(curFile.isEmpty()){
        return saveAs();
    }else{
        return saveFile(curFile);
    }
}


//saveFile IMplementation

bool MainWindow::saveFile(const QString &fileName){
    if(!spreadsheet->writeFile(fileName)){
        statusBar()->showMessage(tr("Saving canceled"), 2000);
        return false;
    }
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}


//saveAs function Implementation

bool MainWindow::saveAs(){
    QString fileName = QFileDialog::getSaveFileName(this,
                                    tr("Save Spreadsheet"), ".",
                                    tr("Spreadsheet Files (* sp)"));
    if(fileName.isEmpty())
        return false;
    return saveFile(fileName);

}

//closeEvent function Implementation
void MainWindow::closeEvent(QCloseEvent *event){
    if(okTocontinue()){
        writeSettings();
        event->accept();
    }else{
        event->ignore();
    }
}




void MainWindow::setCurrentFile(const QString &fileName){
    curFile = fileName;
    setWindowModified(false);

    QString showName = tr("Untitled");
    if(!curFile.isEmpty()){
        showName = strippedName(curFile);
        recentFiles.removeAll(curFile);
        recentFiles.prepend(curFile);
        updateRecentFileActions();
    }
    setWindowTitle(tr("%1[*] - %2").arg(showName)
                                    .arg(tr("Spreadsheet")));
}

QString MainWindow::strippedName(const QString &fullFileName){
    return QFileInfo(fullFileName).fileName();
}



void MainWindow::updateRecentFileActions(){

    QMutableStringListIterator i(recentFiles);
    while(i.hasNext()){
        if(!QFile::exists(i.next()))
            i.remove();
    }
    for(int j = 0; j < MaxRecentFiles; ++j){
        if(j < recentFiles.count()){
            QString text = tr("&%1 %2")
                           .arg(j + 1)
                           .arg(strippedName(recentFiles[j]));
            recentFilesActions[j]->setText(text);
            recentFilesActions[j]->setData(recentFiles[j]);
            recentFilesActions[j]->setVisible(true);

        }else{
            recentFilesActions[j]->setVisible(false);
        }
    }
    separatorAction->setVisible(!recentFiles.isEmpty());
}


void MainWindow::openRecentFile(){
    if(okTocontinue()){
        QAction *action = qobject_cast<QAction *>(sender());
        if(action)
            loadFile(action->data().toString());
    }
}


void MainWindow::find(){
    if(!findDialog){
        findDialog = new FindDialog(this);
        connect(findDialog, SIGNAL(findNext(const QString &,
                                            Qt::CaseSensitivity &)),
                spreadsheet, SLOT(findNext(QString,Qt::CaseSensitivity)));
        connect(findDialog, SIGNAL(findPrevious(const QString &,
                                                Qt::CaseSensitivity)),
                spreadsheet, SLOT(findPreviouse(QString,Qt::CaseSensitivity)));
    }

    findDialog->show();
    findDialog->raise();
    findDialog->activateWindow();

}



void MainWindow::gotoCell(){
    GotoCellDialog *dialog = new GotoCellDialog(this);
    if(dialog->exec()){
        QString str = dialog->ui->lineEdit->text().toUpper();
        spreadsheet->setCurrentCell(str.mid(1).toInt() - 1,
                                    str[0].unicode() - 'A');


    }
    delete dialog;

}



//sort function Implementation

void MainWindow::sort(){






    SortDialog *dialog = new SortDialog(this);
    QTableWidgetSelectionRange range = spreadsheet->selectedRange();

    dialog->setColumnRange('A' + range.leftColumn(),
                           'A' + range.rightColumn());
    if(dialog->exec()){
        SpreadsheetCompare compare;
        compare.keys[0] = dialog->ui->primaryColumnCombo->currentIndex();

        compare.keys[1] = dialog->ui->secondaryColumnCombo->currentIndex() - 1;

        compare.keys[2] = dialog->ui->tertiaryColumnCombo->currentIndex() - 1;


        compare.ascending[0] = (dialog->ui->primaryOrderCombo->currentIndex() == 0);

        compare.ascending[1] = (dialog->ui->secondaryOrderCombo->currentIndex() == 0);

        compare.ascending[2] = (dialog->ui->tertiaryColumnCombo->currentIndex() == 0);

        spreadsheet->sort(compare);

    }
    delete dialog;
}


void MainWindow::about(){
    QMessageBox::about(this, tr("About Spreadsheet"),
                 tr("<h2>Spreadsheet 1.1</h2>"
                    "<p>Copyright &copy; 2016 Software Inc."
                    "<p>Spreadsheet is a small application "
                    "that demostrates QAction, QMainWindow, QMenuBar, "
                    "QStatusBar, QTableWidget, QToolBar, and many other"
                    "Qt classe."));


}



void MainWindow::writeSettings(){




    QSettings settings("Software Inc.", "Spreadsheet");

    settings.setValue("geometry", saveGeometry());
    settings.setValue("recentFiles", recentFiles );
    settings.setValue("showGrid", showGridAction->isChecked());
    settings.setValue("autoRecalc", autoRecalcAction->isChecked());
    settings.beginGroup("FindDialog");
    settings.setValue("matchCase", findDialog->caseCheckBox->isChecked());
    settings.setValue("searchBackward", findDialog->backWardCheckBox->isCheckable());
    settings.endGroup();

}




void MainWindow::readSettings(){

    QSettings settings("Software Inc", "Spreadsheet");
    restoreGeometry(settings.value("geometry").toByteArray());

    recentFiles = settings.value("recentFiles").toStringList();
    updateRecentFileActions();

    bool showGrid = settings.value("showGrid", true).toBool();
    showGridAction->setChecked(showGrid);

    bool autoRecalc = settings.value("autoRecalc", true).toBool();
    autoRecalcAction->setChecked(autoRecalc);
}

