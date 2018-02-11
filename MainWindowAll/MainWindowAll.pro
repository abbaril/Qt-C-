#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T14:54:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindowAll
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    finddialog.cpp \
    gotocelldialog.cpp \
    sortdialog.cpp \
    spreadsheet.cpp \
    cell.cpp

HEADERS  += mainwindow.h \
    finddialog.h \
    gotocelldialog.h \
    sortdialog.h \
    spreadsheet.h \
    cell.h

FORMS    += mainwindow.ui \
    ../GotoCellDialog/gotocelldialog.ui \
    ../FindDialog/finddialog.ui \
    ../SortDialog/sortdialog.ui \
    ../Spreadsheet/spreadsheet.ui

RESOURCES +=

DISTFILES +=








