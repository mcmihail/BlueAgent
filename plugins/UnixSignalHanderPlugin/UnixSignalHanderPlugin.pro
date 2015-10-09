#-------------------------------------------------
#
# Project created by QtCreator 2015-10-09T11:52:18
#
#-------------------------------------------------

QT       -= gui

TARGET = UnixSignalHanderPlugin
TEMPLATE = lib

DEFINES += UNIXSIGNALHANDERPLUGIN_LIBRARY

SOURCES += UnixSignalHanderPlugin.cpp

HEADERS += UnixSignalHanderPlugin.h\
        unixsignalhanderplugin_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
