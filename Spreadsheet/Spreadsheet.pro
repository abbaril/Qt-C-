#-------------------------------------------------
#
# Project created by QtCreator 2016-04-11T17:39:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Spreadsheet
TEMPLATE = app


SOURCES += main.cpp \
    spreadsheet.cpp \
    ../Cell/cell.cpp





HEADERS  += spreadsheet.h \
    ../Cell/cell.h \




FORMS    += spreadsheet.ui \
    ../Cell/cell.ui

RESOURCES += \
    images/images.qrc



