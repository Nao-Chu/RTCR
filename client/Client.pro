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
    communicationroom.cpp \
    signinup.cpp

HEADERS  += mywidget.h \
    communicationroom.h \
    signinup.h

FORMS    += mywidget.ui \
    signup.ui \
    communicationroom.ui

LIBS    += -lmysocket -lpthread

