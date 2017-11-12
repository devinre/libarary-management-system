#-------------------------------------------------
#
# Project created by QtCreator 2012-03-26T17:57:19
#
#-------------------------------------------------

QT       += core gui

QT += sql
TARGET = booklib
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    reg.cpp \
    reader.cpp \
    admin.cpp \
    readermod.cpp \
    bookmod.cpp

HEADERS  += mainwindow.h \
    reg.h \
    connection.h \
    reader.h \
    admin.h \
    readermod.h \
    bookmod.h

FORMS    += mainwindow.ui \
    reg.ui \
    reader.ui \
    admin.ui \
    readermod.ui \
    bookmod.ui
