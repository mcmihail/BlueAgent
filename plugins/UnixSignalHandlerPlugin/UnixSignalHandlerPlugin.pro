#-------------------------------------------------
#
# Project created by QtCreator 2015-10-09T11:52:18
#
#-------------------------------------------------

include(../../common.pri)

QT       -= gui

TARGET = UnixSignalHandlerPlugin
TEMPLATE = lib

DEFINES += UNIXSIGNALHANDERPLUGIN_LIBRARY

SOURCES += UnixSignalHandlerPlugin.cpp

HEADERS +=

INCLUDEPATH += ../../app/pub

unix {
    target.path = /usr/lib
    INSTALLS += target
}
