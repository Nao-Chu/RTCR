#-------------------------------------------------
#
# Project created by QtCreator 2021-05-08T14:47:16
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    mysql.cpp

HEADERS  += mywidget.h \
    mysql.h \

FORMS    += mywidget.ui

LIBS    += -lmysocket -lpthread
