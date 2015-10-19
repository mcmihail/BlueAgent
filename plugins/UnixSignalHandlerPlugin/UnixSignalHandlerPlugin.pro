#-------------------------------------------------
#
# Project created by QtCreator 2015-10-09T11:52:18
#
#-------------------------------------------------

QT       -= gui

TARGET = UnixSignalHandlerPlugin
TEMPLATE = lib

DEFINES += UNIXSIGNALHANDERPLUGIN_LIBRARY

SOURCES += UnixSignalHandlerPlugin.cpp

HEADERS +=

INCLUDEPATH += ../../pub

unix {
    target.path = /usr/lib
    INSTALLS += target
}
