#-------------------------------------------------
#
# Project created by QtCreator 2022-01-16T15:08:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mywine
TEMPLATE = app


SOURCES += main.cpp\
        mywine.cpp \
    wine.cpp \
    winedialog.cpp \
    winefinddialog.cpp

HEADERS  += mywine.h \
    wine.h \
    winedialog.h \
    winefinddialog.h

FORMS    += mywine.ui \
    winedialog.ui \
    winefinddialog.ui
