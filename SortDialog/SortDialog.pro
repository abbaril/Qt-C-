#-------------------------------------------------
#
# Project created by QtCreator 2016-04-11T11:11:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SortDialog
TEMPLATE = app


SOURCES += main.cpp\
        sortdialog.cpp \
    ../Cell/cell.cpp

HEADERS  += sortdialog.h \
    ../Cell/cell.h

FORMS    += sortdialog.ui \
    ../Cell/cell.ui
