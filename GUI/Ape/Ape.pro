#-------------------------------------------------
#
# Project created by QtCreator 2013-03-28T15:05:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ape
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../src/Sys.cpp \
    ../../src/Process.cpp \
    ../../src/Ape.cpp

HEADERS  += mainwindow.h \
    ../../src/Ui.h \
    ../../src/Sys.h \
    ../../src/Process.h \
    ../../src/Ape.h

FORMS    += mainwindow.ui
