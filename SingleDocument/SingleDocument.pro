#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T08:28:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SingleDocument
TEMPLATE = app


SOURCES += main.cpp\
        singledocument.cpp \
    infowidget.cpp

HEADERS  += singledocument.h \
    infowidget.h

FORMS    += singledocument.ui

RESOURCES += \
    images.qrc
