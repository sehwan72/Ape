#-------------------------------------------------
#
# Project created by QtCreator 2013-03-28T15:05:06
#
#-------------------------------------------------

QT       += core gui \
    svg

QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ape
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../src/Sys.cpp \
    ../../src/Process.cpp \
    ../../src/Ape.cpp \
    filesinusedialog.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    ../../src/Ui.h \
    ../../src/Sys.h \
    ../../src/Process.h \
    ../../src/Ape.h \
    filesinusedialog.h \
    aboutdialog.h

FORMS    += filesinusedialog.ui \
    mainwindow.ui \
    aboutdialog.ui

OTHER_FILES += \
    ape.svg
