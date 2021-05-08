#-------------------------------------------------
#
# Project created by QtCreator 2021-05-08T11:14:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    signup.cpp \
    communicationroom.cpp

HEADERS  += mywidget.h \
    signup.h \
    communicationroom.h

FORMS    += mywidget.ui \
    signup.ui \
    communicationroom.ui
