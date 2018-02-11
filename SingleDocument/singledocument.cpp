#include "singledocument.h"
#include "ui_singledocument.h"
#include "infowidget.h"

#include <QMenu>
#include <QToolBar>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDockWidget>

SingleDocument::SingleDocument(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SingleDocument)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(QString("%1[*] - %2").arg("Unnamed").arg("SDI"));
    setWindowIcon(QIcon(":/images/logo.png"));



    docWidget = new QTextEdit(this);
    setCentralWidget(docWidget);



    connect(docWidget->document(), SIGNAL(modificationChanged(bool)), this,
            SLOT(setWindowModified(bool)));

    createActions();
    createMenus();
    createToolBars();
    statusBar()->showMessage("Done");
}

SingleDocument::~SingleDocument()
{
    delete ui;
}

void SingleDocument::createActions(){

    newAction = new QAction(QIcon(":/images/new.png"),tr("&New"), this);
    newAction->setShortcut(tr("Ctrl+N"));
    newAction->setStatusTip(tr("Create a new Document"));
    connect(newAction, SIGNAL(triggered(bool)), this, SLOT(fileNew()));


    cutAction = new QAction(QIcon(":/images/cut.png"), tr("&Cut"), this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("Cut"));
    cutAction->setEnabled(true);
    connect(docWidget, SIGNAL(copyAvailable(bool)), cutAction , SLOT(setEnabled(bool)));
    connect(cutAction, SIGNAL(triggered(bool)), docWidget, SLOT(cut()));

    pasteAction = new QAction(QIcon(":/images/paste.ong"), tr("&Paste"), this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("Paste"));
    connect(docWidget, SIGNAL(copyAvailable(bool)), pasteAction, SLOT(setEnabled(bool)));
    connect(pasteAction, SIGNAL(triggered(bool)), docWidget, SLOT(paste()));




    aboutQtAction = new QAction(QIcon(":/images/aboutQt.png"),tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("About the Qt toolkit"));
    connect(aboutQtAction, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));


    closeAction = new QAction(QIcon(":/images/close.png"),tr("&Close"), this);
    closeAction->setStatusTip(tr("Close Window"));
    closeAction->setShortcut(tr("Ctrl+Shift+W"));
    connect(closeAction, SIGNAL(triggered(bool)), docWidget , SLOT(close()));

    exitAction = new QAction(QIcon(":/images/exit.png"),tr("Exit"), this);
    exitAction->setStatusTip(tr("Exit"));
    exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, SIGNAL(triggered(bool)), this , SLOT(close()));




}

void SingleDocument::createDocks(){

    dock = new QDockWidget( tr("Information"), this );

    InfoWidget *info = new InfoWidget( dock );
    dock->setWidget( info );
    addDockWidget( Qt::LeftDockWidgetArea, dock );

    connect( docWidget->document(), SIGNAL(contentsChange(int, int, int)),
    info, SLOT(documentChanged(int, int, int)) );




}


void SingleDocument::createMenus(){

    QMenu *menu;

    menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(newAction);
    menu->addAction(closeAction);
    menu->addSeparator();
    menu->addAction(cutAction);
    menu->addSeparator();
    menu->addAction(exitAction);

    menu = menuBar()->addMenu( tr("&Edit") );
    menu->addAction( cutAction );
    menu->addAction( copyAction );
    menu->addAction( pasteAction );

    menu = menuBar()->addMenu(tr("&View"));
    menu->addAction(dock->toggleViewAction());





}



void SingleDocument::createToolBars(){

    QToolBar *toolBar;
    toolBar = addToolBar(tr("File"));

    toolBar->addAction(newAction);
    toolBar->addAction(cutAction);
    toolBar->addAction(aboutQtAction);
    toolBar->addAction(closeAction);
    toolBar->addAction(exitAction);
}





void SingleDocument::fileNew(){
    SingleDocument *s = new SingleDocument;
    s->show();
}



void SingleDocument::closeEvent(QCloseEvent *event){
    if(isSafeToClose())
        event->accept();
    else
        event->ignore();
}


bool SingleDocument::isSafeToClose(){

    if(isWindowModified()){

        switch(QMessageBox::warning(this, tr("SDI"),
               tr("The document has unsaved changes\n"
                "Do you want to save before it is closed?"),

                QMessageBox::Discard | QMessageBox::Cancel)){



        case QMessageBox::Cancel:
            return false;
        default:
            return true;
        }
    }
    return true;
}











