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
    signup.cpp \
    sendmessstate.cpp \
    emoji.cpp

HEADERS  += mywidget.h \
    communicationroom.h \
    signup.h \
    sendmessstate.h \
    emoji.h

FORMS    += mywidget.ui \
    signup.ui \
    communicationroom.ui \
    emoji.ui

LIBS    += -lmysocket -lpthread

RESOURCES += \
    imagesrc.qrc \
    image/emoji.qrc

OTHER_FILES += \
    login.qss

