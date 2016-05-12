#-------------------------------------------------
#
# Project created by QtCreator 2016-02-11T16:14:55
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = barvicky2
TEMPLATE = app


SOURCES += main.cpp\
    menu.cpp \
    hra.cpp \
    konechry.cpp \
    skore.cpp \
    ctverec.cpp \
    spravabarev.cpp

HEADERS  += \
    menu.h \
    hra.h \
    konechry.h \
    skore.h \
    ctverec.h \
    spravabarev.h

FORMS    += \
    menu.ui \
    hra.ui \
    konechry.ui \
    skore.ui \
    spravabarev.ui
