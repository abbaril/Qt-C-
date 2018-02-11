#-------------------------------------------------
#
# Project created by QtCreator 2016-05-14T15:10:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhoneBook
TEMPLATE = app


SOURCES += main.cpp\
        phonebook.cpp \
    ../Entry/entry.cpp

HEADERS  += phonebook.h \
    ../Entry/entry.h

FORMS    += phonebook.ui \
    ../Entry/entry.ui
