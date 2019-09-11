#-------------------------------------------------
#
# Project created by QtCreator 2019-09-10T17:01:47
#
#-------------------------------------------------

DEFINES  -= UNICODE
QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = STT_MRAMtest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    PCIE.cpp

HEADERS  += mainwindow.h \
    PCIE.h \
    TERASIC_PCIE.h

FORMS    += mainwindow.ui
