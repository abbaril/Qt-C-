#-------------------------------------------------
#
# Project created by QtCreator 2016-05-16T20:56:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Entry
TEMPLATE = app


SOURCES += main.cpp\
        entry.cpp \
    ../ContactEntry/contactentry.cpp

HEADERS  += entry.h \
    ../ContactEntry/contactentry.h \
    ../EditDialog/editdialog.h

FORMS    += entry.ui
