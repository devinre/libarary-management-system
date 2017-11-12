TEMPLATE = app
TARGET = BKSystemServer
QT += core \
    gui \
    sql \
    network
HEADERS += Uibooksystemserver.h \
    GlobalDefine.h \
    booksystemserver.h \
    ServerTime.h \
    TCPClientThread.h \
    SqlCommand.h \
    server.h
SOURCES += booksystemserver.cpp \
    ServerTime.cpp \
    TCPClientThread.cpp \
    SqlCommand.cpp \
    server.cpp \
    main.cpp
RESOURCES+= BookSystemServer.qrc
TRANSLATIONS = BookSystemServer_Ch.ts
#win32:CONFIG += console
RC_FILE = BookSystem.rc
