#-------------------------------------------------
#
# Project created by QtCreator 2016-05-14T15:11:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ListDialog
TEMPLATE = app


SOURCES += main.cpp\
        listdialog.cpp \
    ../EditDialog/editdialog.cpp

HEADERS  += listdialog.h \
    ../EditDialog/editdialog.h

FORMS    += listdialog.ui \
    ../EditDialog/editdialog.ui
