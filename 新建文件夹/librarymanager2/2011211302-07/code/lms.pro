#-------------------------------------------------
#
# Project created by QtCreator 2013-05-05T21:55:46
#
#-------------------------------------------------
RC_FILE =lms.rc

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = helloworld
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    reg.cpp \
    reader.cpp \
    admin.cpp \
    pc.cpp \
    key.cpp \
    book.cpp \
    bookl.cpp \
    ad_user.cpp

HEADERS  += mainwindow.h \
    reg.h \
    head.h \
    reader.h \
    admin.h \
    pc.h \
    key.h \
    book.h \
    bookl.h \
    ad_user.h

FORMS    += mainwindow.ui \
    reg.ui \
    reader.ui \
    admin.ui \
    pc.ui \
    key.ui \
    book.ui \
    bookl.ui \
    ad_user.ui

RESOURCES += \
    resource.qrc
