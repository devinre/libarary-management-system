#-------------------------------------------------
#
# Project created by QtCreator 2015-06-03T09:31:38
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = libraryManager
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    register.cpp \
    logindialog.cpp

HEADERS  += widget.h \
    register.h \
    logindialog.h \
    connection.h

FORMS    += widget.ui \
    register.ui \
    logindialog.ui

RESOURCES += \
    image.qrc

RC_ICONS = book.ico
